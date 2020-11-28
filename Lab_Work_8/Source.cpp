#include <iterator>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <map>
#include "TaskOne.h"
#include "TaskTwo.h"

using namespace std;

string convert_to_string(vector<int> vect);

string vector_to_str(vector<int> vect);

void enterFile(string path, vector<int> vect);

void enterFile(string path, string str);

void print_splitter(char, int, bool flag = true);

string readFile(string path);

long filesize(string path);

double compressionRate(string path1, string path2);

int main()
{
	system("chcp 1251 > nul");
	string path_src = "source.txt";

	string raw = readFile(path_src);
	cout << "Начальный текст: " << raw << endl;
	map<char, int> symbols;

	for (int i = 0; i < raw.length(); i++) 
	{
		symbols[raw[i]]++;
	}

	list<Huffman*> trees;
	map<char, int>::iterator itr;
	for (itr = symbols.begin(); itr != symbols.end(); itr++)
	{
		Huffman* p = new Huffman(itr->first, itr->second); 
		trees.push_back(p);
	}

	while (trees.size() != 1)
	{
		trees.sort(SortHuf);

		Huffman* l = trees.front();
		trees.pop_front();
		Huffman* r = trees.front();
		trees.pop_front();

		Huffman* parent = new Huffman(l, r);
		trees.push_back(parent);
	}

	Huffman* root = trees.front();
	Print(root);

	vector<bool> code; // buffer
	map<char, vector<bool>> table;
	BuildTable(root, code, table); 

	for (itr = symbols.begin(); itr != symbols.end(); itr++)
	{
		cout << itr->first << " - ";
		for (int j = 0; j < table[itr->first].size(); j++) 
		{
			cout << table[itr->first][j];
		}
		cout << endl;
	}


	string out = "";
	for (int i = 0; i < raw.length(); i++) 
	{
		for (int j = 0; j < table[raw[i]].size(); j++)
		{
			out += table[raw[i]][j] + '0';
		}
	}
	string path1 = "out1.txt";

	// decode
	map<vector<bool>, char> ftable;
	for (auto i = table.begin(); i != table.end(); i++) 
	{
		ftable[i->second] = i->first;
	}

	enterFile(path1, out);

	cout << "Коэфицент сжатия huffman: " << compressionRate(path_src, path1) << endl;

	enterFile(path1, out + "\n" + Decode(out, ftable));

	print_splitter('=', 50);
	
	string path2 = "out2.txt";
	string str = readFile(path_src);

	cout << "Начальный текст: " << str << endl;

	cout << "Кодирование:\n";
	vector<int> output_code = encoding(str);

	cout << "Декодирование: ";
	decoding(output_code);

	enterFile(path2, output_code);

	cout << endl;
	
	cout << "Коэфицент сжатия LWZ: " << compressionRate(path_src, path2) << endl;

	enterFile(path2, 
		"Кодирование: " + 
		vector_to_str(output_code) + 
		"\nДекодирование: " + 
		convert_to_string(output_code));

	system("pause");
	return 0;
}

void print_splitter(char c, int n, bool flag) 
{ 
	for (int i = 0; i < n; i++) 
	{
		cout << c;
	}
	if (flag) 
	{
		cout << endl;
	}
}

string convert_to_string(vector<int> vect)
{
	string res;
	for (int i = 0; i < vect.size(); i++)
	{
		res += vect[i];
	}
	return res;
}
string vector_to_str(vector<int> vect)
{
	ostringstream res;
	if (!vect.empty())
	{
		// Convert all but the last element to avoid a trailing ","
		copy(vect.begin(), vect.end() - 1, ostream_iterator<int>(res, ","));
		// Now add the last element with no delimiter
		res << vect.back();
	}

	return res.str();
}

void enterFile(string path, vector<int> vect)
{
	fstream fout(path, ios::out | ios::trunc);
	if (!fout.is_open())
	{
		cout << "Error, file not open.";
		exit(1);
	}
	for (int i = 0; i < vect.size(); i++)
	{
		fout << vect[i] << " ";
	}
	fout.close();
}

void enterFile(string path, string str)
{
	fstream fout(path, ios::out | ios::trunc);
	if (!fout.is_open())
	{
		cout << "Error, file not open.";
		exit(1);
	}
	fout << str;
	fout.close();
}

string readFile(string path)
{
	string value;
	fstream fout(path, ios::in);
	if (!fout.is_open())
	{
		cout << "Error, file not open.\n";
		return "";
	}
	getline(fout, value);
	fout.close();

	return value;
}

long filesize(string path) 
{
	fstream fin(path, ios::in);
	if (!fin)
	{
		cout << "Error, file not found.\n";
		exit(1);
	}
	fin.seekg(0, ios::end);
	long size = fin.tellg();
	fin.close();
	return size;
}

double compressionRate(string path1, string path2) 
{
	return (double)filesize(path2) / filesize(path1);
}
