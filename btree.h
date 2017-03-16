#pragma once
struct btree_node {
public:
	int * keys_array;
	btree_node ** child_ptr_array;
	int min_deg;
	int num_of_keys;
	bool leaf_status;
	btree_node(int min_deg, bool leaf_status);

	void insert(int new_key);
	void split_node(int index, btree_node * full_child);
	void print_pre_oder();
	int find_key_index(int);
	void remove_key(int k);
	void remove_leaf(int);
	void remove_non_leaf(int);
	void merge(int);
	void borrow(int);
	void left_borrow(int);
	void right_borrow(int);
	bool search(int);
};

class BTREE {
public:
	btree_node * root;
	int min_deg;
	BTREE(int min_deg);
	void insert(int new_key);
	void print_pre_oder();
	void delete_key(int);
	bool search(int);
};
