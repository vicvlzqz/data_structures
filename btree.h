#pragma once
#include <vector>

using namespace std;
struct btree_node {
public:
	int * keys_array;
	btree_node ** child_ptr_array;
	int min_deg;
	int max_deg;
	int num_of_keys;
	bool leaf_status;
	vector<int> keys;
	btree_node(int min_deg, bool leaf_status);

	void insert(int new_key);
	void split_node(int, btree_node *);
	void print_pre_order();
	int find_key_index(int);
	void merge(int);
	void borrow(int);
	void left_borrow(int);
	void right_borrow(int);
	bool search(int);
	void destroy();
	//testing
	void rem_key(int);
};

class BTREE {
public:
	btree_node * root;
	int min_deg;
	int max_deg;
	BTREE(int);
	void insert(int);
	void print_pre_order();
	void delete_key(int);
	bool search(int);
	void destroy();
};
