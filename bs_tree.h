#pragma once
#include <iostream>
using namespace std;
struct node
{
	int val;
	node * left;
	node * right;
};


class BST
{
public:
	BST();
	void add_node(int);
	void print_bst_in_order();
private:
	node * root;
	void add_node(node *&, int);
	void print_bst_in_order(node *&);
};

BST::BST()
{
	root = NULL;
}

void BST::add_node(int new_val)
{
	add_node(root, new_val);
}

void BST::add_node(node *& root, int new_val)
{
	if (root == NULL)
	{
		root = new node;
		root->val = new_val;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->val < new_val)
	{
		add_node(root->right, new_val);
	}
	else if (root->val > new_val)
	{
		add_node(root->left, new_val);
	}
}

void BST::print_bst_in_order()
{
	cout << "Printing BST..." << endl;
	print_bst_in_order(root);
	cout << "\nDone..." << endl;
}

void BST::print_bst_in_order(node *& root)
{
	if (root != NULL)
	{
		print_bst_in_order(root->left);
		cout << root->val << " ";
		print_bst_in_order(root->right);
	}
}
