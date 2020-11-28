#ifndef TaskOne
#define TaskOne
#include <iostream>
using namespace std;

const int MAXIMUM_SYMBOLS = 256;

class Huffman
{
	public:
		int count;
		char symbol;
		Huffman* left;
		Huffman* right;

		Huffman() { }

		Huffman(char __symbol, int __count)
		{
			symbol = __symbol;
			count = __count;
		}

		Huffman(Huffman* l, Huffman* r) // create parent
		{
			symbol = 0;
			left = l;
			right = r;
			count = l->count + r->count;
		}
};

void Print(Huffman* root, int depth = 0)
{
	if (!root) 
	{
		return;
	}

	if (root->symbol)
	{
		for (int i = 0; i < depth; i++) 
		{
			cout << ".";
		}
		cout << root->symbol << endl;
	}
	else depth++;
	Print(root->left, depth);
	Print(root->right, depth);
}

void BuildTable(Huffman* root, vector<bool>& code, map<char, vector<bool>>& table) // dfs
{
	if (root->left)
	{
		code.push_back(0); // left
		BuildTable(root->left, code, table);
	}

	if (root->right)
	{
		code.push_back(1); // right
		BuildTable(root->right, code, table);
	}

	if (root->symbol) 
	{
		table[root->symbol] = code;
	}
	if (code.size())
	{
		code.pop_back();
	}
}

bool SortHuf(const Huffman* a, const Huffman* b)
{
	return a->count < b->count;
}

string Decode(string& str, map<vector<bool>, char>& table) // flipped table: code - char pairs
{
	string out = "";
	vector<bool> code;
	for (int i = 0; i < str.length(); i++)
	{
		code.push_back(str[i] == '0' ? false : true);
		if (table[code])
		{
			out += table[code];
			code.clear();
		}
	}
	return out;
}
#endif
