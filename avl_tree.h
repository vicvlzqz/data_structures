#pragma once
#include <algorithm>
#include <iostream>
using namespace std;

struct node
{
	int val;
	node * left;
	node * right;
};

class AVLT
{
public:
	AVLT();
	void add_node(int);
	void print_avlt_in_order();
	void print_avlt_pre_order();
private:
	node * root;
	void AVLT::add_node(node *&, int);
	node * balance(node *&);
	int height(node *&);
	int diff(node *&);
	node * ll_rotate(node *&);//which I call right rotate
	node * rr_rotate(node *&);//which I call left rotate
	node * lr_rotate(node *&);
	node * rl_rotate(node *&);
	void print_avlt_in_order(node *& root);
	void print_avlt_pre_order(node *& root);
};

AVLT::AVLT()
{
	root = NULL;
}

int AVLT::height(node *& avl_node)
{
	if (avl_node == NULL)
	{
		return 0;
	}
	else
	{
		int l_height = height(avl_node->left);
		int r_height = height(avl_node->right);
		return max(l_height, r_height) + 1;
	}
}

int AVLT::diff(node *& avl_node)
{
	return height(avl_node->left) - height(avl_node->right);
}

node * AVLT::ll_rotate(node *& avl_node)
{
	node * temp = avl_node->left;
	avl_node->left = temp->right;
	temp->right = avl_node;
	return temp;
}

node * AVLT::rr_rotate(node *& avl_node)
{
	node * temp = avl_node->right;
	avl_node->right = temp->left;
	temp->left = avl_node;
	return temp;
}

node * AVLT::lr_rotate(node *& avl_node)
{
	node * temp = avl_node->left;
	temp = rr_rotate(avl_node->left);
	return ll_rotate(avl_node);
}

node * AVLT::rl_rotate(node *& avl_node)
{
	node * temp = avl_node->right;
	temp = ll_rotate(avl_node->right);
	return rr_rotate(avl_node);
}

node * AVLT::balance(node *& avl_node)
{
	int b_f = diff(avl_node);
	if (b_f > 1)
	{
		if (diff(avl_node->left) > 0)
		{
			avl_node = ll_rotate(avl_node);
		}
		else
		{
			avl_node = lr_rotate(avl_node);
		}
	}
	else if (b_f < -1)
	{
		if (diff(avl_node->right) < 0)
		{
			avl_node = rr_rotate(avl_node);
		}
		else
		{
			avl_node = rl_rotate(avl_node);
		}
	}
	return avl_node;
}
void AVLT::add_node(int new_val)
{
	add_node(root, new_val);
}
void AVLT::add_node(node *& root, int new_val)
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
		root = balance(root);
	}
	else if (root->val > new_val)
	{
		add_node(root->left, new_val);
		root = balance(root);
	}
}

void AVLT::print_avlt_in_order()
{
	cout << "Printing AVLT in order..." << endl;
	print_avlt_in_order(root);
	cout << "\nDone..." << endl;
}

void AVLT::print_avlt_pre_order()
{
	cout << "Printing AVLT pre order..." << endl;
	print_avlt_pre_order(root);
	cout << "\nDone..." << endl;
}
void AVLT::print_avlt_in_order(node *& root)
{
	if (root != NULL)
	{
		print_avlt_in_order(root->left);
		cout << root->val << " ";
		print_avlt_in_order(root->right);
	}
}

void AVLT::print_avlt_pre_order(node *& root)
{
	if (root != NULL)
	{
		cout << root->val << " ";
		print_avlt_pre_order(root->left);
		print_avlt_pre_order(root->right);
	}
}
