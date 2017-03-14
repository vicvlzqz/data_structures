#pragma once
struct btree_node {
	int * keys_array;
	btree_node ** child_ptr_array;
	int min_deg;
	int num_of_keys;
	bool leaf_status;
	btree_node(int min_deg, bool leaf_status);

	void insert(int new_key);
	void split_node(int index, btree_node * full_child);
	void print_pre_oder();
};

class BTREE {
public:
	btree_node * root;
	int min_deg;
	BTREE(int min_deg);
	void insert(int new_key);
	void print_pre_oder();
};
