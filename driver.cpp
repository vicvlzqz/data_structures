#include <iostream>
#include <string>
#include <algorithm>
#include "btree.h"
using namespace std;
void test_btree_search();
void test_btree_insert();
void test_btree_delete();
int main()
{
	test_btree_search();
	return 0;
}

void test_btree_insert()
{
	/** INSERTION TEST **/
	cout << "========INSERTION TEST START===========" << endl;
	BTREE test_tree(2); //
	cout << "Tree initialized properly." << endl;
	test_tree.insert(10);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	//cout << 10 << endl;
	test_tree.insert(20);
	//cout << 20 << endl;
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(5);
	//cout << 5 << endl;
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(6);
	//cout << 6 << endl;
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(12);
	//cout << 12 << endl;
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(30);
	//cout << 30 << endl;
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(7);
	//cout << 7 << endl;
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(17);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	cout << "========INSERTION TEST END===========" << endl;
}
void test_btree_delete()
{
	
	//DELETION TEST
	cout << "===========DELETION TEST START===========" << endl;
	BTREE test_tree(2);
	cout << "test_tree initialized properly." << endl;
	test_tree.insert(10);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(20);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(5);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(6);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(12);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(30);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(7);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(17);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.delete_key(50);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(70);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(50);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(60);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.delete_key(17);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	cout << "===========DELETION TEST END===========" << endl;

}
void test_btree_search()
{
	//SEARCH TEST
	cout << "===========SEARCH TEST START============" << endl;
	BTREE test_tree(2);
	cout << "test_tree initialized properly." << endl;
	test_tree.insert(10);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(20);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(5);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(6);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(12);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(30);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(7);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(17);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(70);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(50);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	test_tree.insert(60);
	test_tree.print_pre_oder();
	cout << "=========================================" << endl;
	
	//should be true
	test_tree.search(5);
	test_tree.search(70);
	test_tree.search(10);
	test_tree.search(17);

	//should be false
	test_tree.search(81);
	test_tree.search(9);
	test_tree.search(100);

	//little spacial test
	test_tree.delete_key(5);
	test_tree.print_pre_oder();
	test_tree.search(5);
	cout << "===========SEARCH TEST END============" << endl;
}