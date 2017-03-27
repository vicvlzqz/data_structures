#include <iostream>
#include <string>
#include "btree.h"
using namespace std;
void test_btree_search();
void test_btree_insert();
void test_btree_delete();
void misc_btree_test();
void let_user_test_btree();
int main()
{
	//These are tests we created to test search insert and delete
	//Uncomment let_user_test_btree() to perform individual inserts, deletes and searches
	test_btree_search();
	test_btree_insert();
	test_btree_delete();
	//misc_btree_test();
	//let_user_test_btree();
	return 0;
}

void test_btree_insert()
{
	/** INSERTION TEST **/
	cout << "========INSERTION TEST START===========" << endl;
	BTREE test_tree(5); //
	cout << "Tree initialized properly." << endl;
	test_tree.insert(5);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	//cout << 10 << endl;
	test_tree.insert(4);
	//cout << 20 << endl;
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(3);
	//cout << 5 << endl;
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(2);
	//cout << 6 << endl;
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(6);
	//cout << 12 << endl;
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(7);
	//cout << 30 << endl;
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(8);
	//cout << 7 << endl;
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(9);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(10);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(1);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(0);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	cout << "========INSERTION TEST END===========" << endl;
}
void test_btree_delete()
{
	
	//DELETION TEST
	cout << "===========DELETION TEST START===========" << endl;
	BTREE test_tree(5);
	cout << "test_tree initialized properly." << endl;
	test_tree.insert(10);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(20);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(5);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(6);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(12);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(30);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(7);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(17);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.delete_key(50);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(70);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(50);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(60);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.delete_key(17);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	cout << "===========DELETION TEST END===========" << endl;

}
void test_btree_search()
{
	//SEARCH TEST
	cout << "===========SEARCH TEST START============" << endl;
	BTREE test_tree(5);
	cout << "test_tree initialized properly." << endl;
	test_tree.insert(10);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(20);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(5);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(6);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(12);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(30);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(7);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(17);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(70);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(50);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(60);
	test_tree.print_pre_order();
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

	test_tree.delete_key(5);
	test_tree.print_pre_order();
	test_tree.search(5);
	cout << "===========SEARCH TEST END============" << endl;
}
void misc_btree_test()
{
	BTREE test_tree(5); //
	cout << "Tree initialized properly." << endl;
	for (int i = 1; i < 21; i++)
	{
		test_tree.insert(i);
		test_tree.print_pre_order();
		cout << "=========================================" << endl;
	}
	for (int i = 1; i < 21; i++)
	{
		test_tree.delete_key(i);
		test_tree.print_pre_order();
		cout << "=========================================" << endl;
	}
	for (int i = 1; i < 21; i++)
	{
		test_tree.insert(i);
		test_tree.print_pre_order();
		cout << "=========================================" << endl;
	}
	test_tree.destroy();
	/*test_tree.delete_key(8);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.delete_key(6);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.delete_key(9);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.delete_key(10);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.insert(15);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.delete_key(15);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;
	test_tree.destroy();
	test_tree.insert(15);
	test_tree.print_pre_order();
	cout << "=========================================" << endl;*/
}
void let_user_test_btree()
{
	cout << "Welcome.\nThis program will allow you test our B-TREE implementation,\n";
	bool repeat = false;
	int minimum_degree = 0;
	do {
		cout << "Begin by selecting the minimum degree for your desired B-TREE.\n";
		string str;
		cin >> str;
		while (!isdigit(str[0]) || (isdigit(str[0]) && stoi(str) <= 2))
		{
			cin.clear();
			cout << "Please enter a valid number (> 2).\n";
			cin >> str;
		}
		minimum_degree = ceil(stoi(str));
		BTREE test_tree(minimum_degree);
		cout << "A B-TREE of min degree " << minimum_degree << " has been initialized.\n";
		cout << "What operation do you wish to perform ? \n";
		cout << "The resulting pre order sequence will be displayed after your operation is completed." << endl;
		cout << "Enter(exactly one character):\n";
		char input;
		bool repeat_same_tree = false;
		do
		{
			cout << "d to delete a number\ni to insert a number\ns to search for a number\n";
			cin >> input;
			while (!(input == 'd' || input == 's' || input == 'i'))
			{
				cin.clear();
				cout << "Please enter one of the choices:\n";
				cout << "d to delete a number\ni to insert a number\ns to search for a number\n";
				cin >> input;
			}
			if (input == 'i')
			{
				cout << "Now please type in a number to insert:\n";
				int insert_num;
				string str;
				cin >> str;
				while (!isdigit(str[0]))
				{
					cin.clear();
					cout << "Please enter a valid number to delete.\n";
					cin >> str;
				}
				cout << "You have inserted " << str << "." << endl;
				insert_num = stoi(str);
				test_tree.insert(insert_num);
				test_tree.print_pre_order();
			}
			else if (input == 'd')
			{
				cout << "Now please type in a number to delete:\n";
				int delete_num;
				string str;
				cin >> str;
				while (!isdigit(str[0]))
				{
					cin.clear();
					cout << "Please enter a valid number to delete.\n";
					cin >> str;
				}
				cout << "You have inserted " << str << "." << endl;
				delete_num = stoi(str);
				test_tree.delete_key(delete_num);
				test_tree.print_pre_order();
			}
			else if (input == 's')
			{
				cout << "Now please type in a number to search for:\n";
				int search_num;
				string str;
				cin >> str;
				while (!isdigit(str[0]))
				{
					cin.clear();
					cout << "Please enter a valid number to delete.\n";
					cin >> str;
				}
				cout << "You have inserted " << str << "." << endl;
				search_num = stoi(str);
				test_tree.search(search_num);
				test_tree.print_pre_order();
			}
			cout << "Enter\ns to continue with the same tree\nd to continue with a different tree (and max degree) or exit\n";
			char same_tree_command;
			cin >> same_tree_command;
			while (!(same_tree_command == 'd' || same_tree_command == 's'))
			{
				cin.clear();
				cout << "you entered: " << same_tree_command << endl;
				cout << "Please enter one of the choices:\n";
				cout << "d for a new tree or to exit\ns to perform more operations on the same tree\n";
				cin >> same_tree_command;
			}
			repeat_same_tree = same_tree_command == 's' ? true : false;
		} while (repeat_same_tree);
		cout << "Do you wish to exit or start with a new tree?:\n";
		cout << "q: exit\tn: new tree\n";
		char ex_comm;
		cin >> ex_comm;
		while (!(ex_comm == 'q' || ex_comm == 'n'))
		{
			cin.clear();
			cout << "Please enter one of the choices:\n";
			cout << "n for a new tree or q to exit\n";
			cin >> ex_comm;
		}
		repeat = ex_comm == 'n' ? true : false;
	} while (repeat);
	cout << "Thank you and good bye.\n";
}
