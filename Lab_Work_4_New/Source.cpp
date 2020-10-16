#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cmath>

struct Node {
    int key;
    Node* left, * right;
};

Node* New_Node(int);

Node* Insert(Node*, int);

int Count(Node*);

int Get_Random_Int(int, int);

void inorder(Node*);

void Print_Tree_Info(Node*);

using namespace std;

int main() {
    srand(time(NULL));
    system("chcp 1251 > nul");
    Node* root = NULL;

    int amount, min, max;
    cout << "Enter amount of elements: ";
    cin >> amount;
    cout << "Enter min: ";
    cin >> min;
    cout << "Enter max: ";
    cin >> max;

    for (int i = 0; i < amount; i++) {
        root = Insert(root, Get_Random_Int(min, max));
    }
    int elementAmount = Count(root);
    int generation = 2;
    Print_Tree_Info(root);
    cout << "Потомков от второго уровня:" << elementAmount - 1 << endl;
    system("pause");
    return 0;
}

Node* New_Node(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* Insert(Node* Node, int key) {
    if (Node == NULL) {
        return New_Node(key);
    }
    if (key < Node->key) {
        Node->left = Insert(Node->left, key);
    }
    else if (key > Node->key)
    {
        Node->right = Insert(Node->right, key);
    }
    return Node;
}

int Count(Node* tree)
{
    if (tree == NULL) {
        return 0;
    }
    return Count(tree->right) + Count(tree->left) + 1;
}

void Print_Tree_Info(Node* root) {
    
    if (root != NULL) {
        Print_Tree_Info(root->left);
        cout << "=========\n" 
        << "Data: " << root->key 
        << "\nLeft child address: " << root->left 
        << "\nRight child address: " << root->right << "\n" 
        << "=========\n";
        Print_Tree_Info(root->right);
    }
}

int Get_Random_Int(int min, int max) {
    static const double fraction = 1.0 / ((double)(RAND_MAX) + 1.0);
    return (int)(rand() * fraction * (double)(max - min + 1) + min);
}