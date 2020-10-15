#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

struct Node {
    int key;
    Node* left, * right;
};

Node* New_Node(int);

Node* Insert(Node*, int);

int Get_Random_Int(int, int);

void inorder(Node*);

void Print_Tree_Info(Node*);

using namespace std;

int main() {
    srand(time(NULL));
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

    Print_Tree_Info(root);

    char user_answer;

    do {
        Print_Tree_Info(root);
        cout << "Continue? (y/n): ";
        cin >> user_answer;
    } while (user_answer == 'y');
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
    return (int)(rand() * fraction * (max - min + 1) + min);
}