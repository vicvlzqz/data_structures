#include <iostream>
#include <string>
#include <algorithm>
#include "btree.h"
using namespace std;

int main()
{

	//deletion test
	BTREE t_2(2);
	cout << "t_2 initialized properly." << endl;
	t_2.insert(10);
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	//cout << 10 << endl;
	t_2.insert(20);
	//cout << 20 << endl;
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	t_2.insert(5);
	//cout << 5 << endl;
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	t_2.insert(6);
	//cout << 6 << endl;
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	t_2.insert(12);
	//cout << 12 << endl;
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	t_2.insert(30);
	//cout << 30 << endl;
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	t_2.insert(7);
	//cout << 7 << endl;
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	t_2.insert(17);
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	t_2.delete_key(50);
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	t_2.delete_key(20);
	t_2.print_pre_oder();
	cout << "=========================================" << endl;
	
	/** INSERTION TEST
	BTREE t(2); // 
	cout << "Tree initialized properly." << endl;
	t.insert(10);
	t.print_pre_oder();
	cout << "=========================================" << endl;
	//cout << 10 << endl;
	t.insert(20);
	//cout << 20 << endl;
	t.print_pre_oder();
	cout << "=========================================" << endl;
	t.insert(5);
	//cout << 5 << endl;
	t.print_pre_oder();
	cout << "=========================================" << endl;
	t.insert(6);
	//cout << 6 << endl;
	t.print_pre_oder();
	cout << "=========================================" << endl;
	t.insert(12);
	//cout << 12 << endl;
	t.print_pre_oder();
	cout << "=========================================" << endl;
	t.insert(30);
	//cout << 30 << endl;
	t.print_pre_oder();
	cout << "=========================================" << endl;
	t.insert(7);
	//cout << 7 << endl;
	t.print_pre_oder();
	cout << "=========================================" << endl;
	t.insert(17);
	t.print_pre_oder();
	cout << "=========================================" << endl;
	**/
	return 0;
}