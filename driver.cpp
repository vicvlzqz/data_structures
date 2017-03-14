#include <iostream>
#include <string>
#include <algorithm>
#include "btree.h"
using namespace std;

int main()
{
	BTREE t(2); // 
	cout << "Tree initialized properly." << endl;
	t.insert(10);
	t.print_pre_oder();
	cout << 10 << endl;
	t.insert(20);
	cout << 20 << endl;
	t.print_pre_oder();
	t.insert(5);
	cout << 5 << endl;
	t.print_pre_oder();
	t.insert(6);
	cout << 6 << endl;
	t.print_pre_oder();
	t.insert(12);
	cout << 12 << endl;
	t.print_pre_oder();
	t.insert(30);
	cout << 30 << endl;
	t.insert(7);
	cout << 7 << endl;
	t.insert(17);

	t.print_pre_oder();
	return 0;
}