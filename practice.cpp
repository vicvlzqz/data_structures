#include <iostream>
#include <string>
#include <algorithm>
#include "avl_tree.h"
#include "bs_tree.h"
using namespace std;

int main()
{
	cout << "Main starting \n";
	AVLT tree;
	tree.add_node(1);
	cout << 1;
	tree.add_node(2);
	cout << 2;
	tree.add_node(3);
	cout << 3;
	tree.add_node(4);
	cout << 4;
	tree.add_node(5);
	cout << 5;
	tree.add_node(6);
	cout << 6;
	tree.add_node(7);
	cout << 7;
	tree.add_node(8);
	cout << 8;
	tree.add_node(9);
	cout << 9;
	tree.add_node(10);
	cout << 10 << endl;
	cout << "Printing AVL\n";
	tree.print_avlt_in_order();
	tree.print_avlt_pre_order();
	cout << "Main Done" << endl;
	return 0;
}