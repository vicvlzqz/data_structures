#pragma once
#include <string>
#include "btree.h"
#include <iostream>
using namespace std;

BTREE::BTREE(int min_deg)
{
	this->min_deg = min_deg;
	root = NULL;
}
void BTREE::insert(int new_key)
{
	cout << "inserting: " << new_key << endl;
	//first insert of empty tree
	if (root == NULL)
	{
		// make new root
		root = new btree_node(min_deg, true);
		root->keys_array[0] = new_key;  // assign new_key tp first key in keys_array
		root->num_of_keys = 1;  // update number of keys
		root->leaf_status = true;
	}
	else // if the tree is not empty, root is not NULL
	{
		// if the root node is full
		if (root->num_of_keys == 2 * min_deg - 1)
		{
			// make new root
			btree_node * temp_node = new btree_node(min_deg, false);

			// make new root point to old root
			temp_node->child_ptr_array[0] = root;

			// split the old root
			cout << "root's leaf status is: " << root->leaf_status << endl;
			temp_node->split_node(0, root);
			cout << "now root has : " << root->num_of_keys << "children" << endl;
			//figure out where to place key
			int running_index = 0;
			if (temp_node->keys_array[0] < new_key)
				running_index++;
			temp_node->child_ptr_array[running_index]->insert(new_key);

			root = temp_node; //update root
		}
		else  // if root is not full just insert
			root->insert(new_key);
	}
}

void BTREE::print_pre_oder()
{
	root->print_pre_oder();
}
btree_node::btree_node(int min_deg, bool is_leaf)
{
	keys_array = new int[2 * min_deg - 1];
	child_ptr_array = new btree_node *[2 * min_deg];
	num_of_keys = 0;
	leaf_status = is_leaf;
	this->min_deg = min_deg;
}

void btree_node::insert(int new_key)
{
	int last_key_index = num_of_keys - 1;
	cout << "chabaca: " << num_of_keys;
	if (leaf_status == true)//if it is a leaf
	{
		cout << "trying leaf insert" << endl;
		int running_index;
		for (running_index = last_key_index; keys_array[running_index] > new_key && running_index >= 0; running_index--)
		{
			cout << "runnig nindex: " << running_index;
			keys_array[running_index + 1] = keys_array[running_index];
		}
		cout << "runnig nindex: " << running_index;
		keys_array[running_index + 1] = new_key;
		num_of_keys++;
		cout << "leaf insert completed successfully" << endl;
	}
	else
	{
		cout << "trying non leaf insert" << endl;
		int running_index;

		for (running_index = last_key_index; running_index >= 0 && keys_array[running_index] > new_key; running_index--)
		{
			cout << "last_r_i" << running_index << endl;
		}//find the appropriate child place to put the key
		if (child_ptr_array[running_index + 1]->num_of_keys == 2 * min_deg - 1) //if the child t the appropriate place happens to be full
		{
			split_node(running_index + 1, child_ptr_array[running_index + 1]);//split the child

			cout << ":)r_i" << running_index << endl;
			if (keys_array[running_index + 1] < new_key)
			{
				running_index++;
			}
		}
		cout << "r_i" << running_index << endl;
		child_ptr_array[running_index + 1]->insert(new_key);	//the insert the key into the proper child
																//child_ptr_array[running_index = 1]->num_of_keys++;
		cout << "non leaf insert succes!" << endl;
	}

}

void btree_node::split_node(int index, btree_node * full_child)
{
	cout << "splitting node!" << endl;
	cout << "full_child's leaf status is: " << full_child->leaf_status << endl;
	cout << "number of keys in node to be split: " << full_child->num_of_keys << endl;
	btree_node * temp_node = new btree_node(full_child->min_deg, full_child->leaf_status);//make a temp node similar to the full one
	cout << "new node ready " << endl;
	int running_index;
	for (running_index = 0; running_index < min_deg - 1; running_index++)//copy one less than half of the keys in the full node's array into the 
	{																	 //temp node
		cout << "assigning new keys " << endl;
		//cout << temp_node->keys_array[running_index] << endl;
		cout << "Copying full_child key at index: " << min_deg + running_index << " to temp_node key at index: " << running_index << endl;
		cout << full_child->keys_array[min_deg + running_index] << endl;
		temp_node->keys_array[running_index] = full_child->keys_array[min_deg + running_index];
		full_child->num_of_keys--;
		temp_node->num_of_keys++;
	}
	//if full_child is not a leaf node, we also need to copy its child pointers!
	if (!(full_child->leaf_status))
	{
		for (running_index = 0; running_index < min_deg; running_index++)
		{
			temp_node->child_ptr_array[running_index] = full_child->child_ptr_array[min_deg + running_index];
		}
	}
	//since parent full child will have new children, create pointers allocate pointer in child array for the new children
	//concretely, shift all former pointers right, once
	cout << "abc: " << num_of_keys << endl;
	for (running_index = num_of_keys; running_index > index + 1; running_index--)
	{
		child_ptr_array[running_index + 1] = child_ptr_array[running_index];
	}
	//then, at the correct child, point to temp node:
	child_ptr_array[index + 1] = temp_node;
	//we need to promote one of the keys of the full_child, so we shift all the keys right of the index further right by 1
	for (running_index = num_of_keys - 1; running_index >= index; running_index--)
	{
		keys_array[running_index + 1] = keys_array[running_index];
	}
	keys_array[running_index + 1] = full_child->keys_array[min_deg - 1];
	//keep track of the number of keys, increase that by 1
	full_child->num_of_keys--;
	cout << "finally, number of keys in node to be split: " << full_child->num_of_keys << endl;
	num_of_keys++;
}

void btree_node::print_pre_oder()
{
	cout << "num_of_keys is: " << num_of_keys << endl;
	for (int i = 0; i < num_of_keys; i++)
	{
		cout << keys_array[i] << "<-->";
	}
	if (!leaf_status)
	{
		for (int i = 0; i <= num_of_keys; i++)
		{
			child_ptr_array[i]->print_pre_oder();
		}
	}
	cout << endl;
}
int btree_node::find_key_index(int target)
{
	int running_index = 0;
	while (running_index < num_of_keys && keys_array[running_index] < target)
	{
		running_index++;
	}
	return running_index;
}

void btree_node::remove_key(int target)
{
	int index = find_key_index(target);
	cout << "index is :" << index << ". " << endl;
	cout << "and number of keys is: " << num_of_keys << endl;
	if (index < num_of_keys && keys_array[index] == target)
	{
		if (leaf_status == true)
		{
			remove_leaf(target);
		}
		else
		{
			remove_non_leaf(index);
		}
	}
	else
	{
		if (leaf_status == true)
		{
			cout << target << " is not in this tree." << endl;
			return;
		}
		
		bool flag = ((index == num_of_keys) ? true : false);
		cout << "herala" << endl;
		if (child_ptr_array[index]->num_of_keys < min_deg)
		{
			cout << "hera" << endl;
			borrow(index);
		}
		
		// If the last child has been merged, it must have merged with the previous
		// child and so we recurse on the (idx-1)th child. Else, we recurse on the
		// (idx)th child which now has atleast t keys
		if (flag && index > num_of_keys)
			child_ptr_array[index - 1]->remove_key(target);
		else
			child_ptr_array[index]->remove_key(target);
		
	}
}

void btree_node::remove_leaf(int target)
{
	if (num_of_keys >= min_deg)
	{
		int running_index = 0;
		while (running_index < num_of_keys && keys_array[running_index] != target)
		{
			running_index++;
		}
		cout << "running_index is :" << running_index << ". " << endl;
		cout << "key at running_index is : " << keys_array[running_index] << endl;
		if (keys_array[running_index] != target)
		{
			cout << target << " is not in this tree." << endl;
		}
		else
		{
			int temp_running_index = running_index;
			while (temp_running_index < num_of_keys)
			{
				keys_array[temp_running_index] = keys_array[temp_running_index + 1];
				temp_running_index += 1;
			}
			num_of_keys -= 1;
		}
	}
}
void BTREE::delete_key(int target)
{
	cout << "attempting to delete " << target << endl;
	root->remove_key(target);
}

void btree_node::remove_non_leaf(int index)
{
	if (child_ptr_array[index]->num_of_keys >= min_deg)
	{
		// if the previous child has sufficient children, get the predecessor
		btree_node * temp_node = child_ptr_array[index];
		while (!temp_node->leaf_status)
			temp_node = temp_node->child_ptr_array[temp_node->num_of_keys];
		int predecessor = temp_node->keys_array[temp_node->num_of_keys - 1];
		temp_node->remove_key(predecessor);
		keys_array[index] = predecessor;
	}
	else if (child_ptr_array[index  + 1]->num_of_keys >= min_deg)
	{
		//if instead the next child has sufficient children, get the predecessor
		btree_node * temp_node = child_ptr_array[index + 1];
		while (!temp_node->leaf_status)
			temp_node = temp_node->child_ptr_array[0];
		int predecessor = temp_node->keys_array[0];
		temp_node->remove_key(predecessor);
		keys_array[index] = predecessor;
	}
	else
	{//if neither is able to donate predecessor or successor
		int target = keys_array[index];
		merge(index);
		child_ptr_array[index]->remove_key(target);
	}
}

void btree_node::merge(int index)
{
	int running_index = 0;
	btree_node * l_child = child_ptr_array[index];
	btree_node * r_child = child_ptr_array[index + 1];

	l_child->keys_array[l_child->num_of_keys] = keys_array[index];
	l_child->num_of_keys++;
	running_index = l_child->num_of_keys;
	int temp_running_index = 0;
	while (temp_running_index < r_child->num_of_keys)
	{
		l_child->keys_array[running_index] = r_child->keys_array[temp_running_index];
		running_index++;
		temp_running_index++;
	}
	if (!l_child->leaf_status)
	{
		for (int i = 0; i <= r_child->num_of_keys; ++i)
			l_child->child_ptr_array[i + min_deg] = r_child->child_ptr_array[i];
	}
	for (int i = index + 1; i < num_of_keys; ++i)
		keys_array[i - 1] = keys_array[i];

	for (int i = index + 2; i <= num_of_keys; ++i)
		child_ptr_array[i - 1] = child_ptr_array[i];

	l_child->num_of_keys += r_child->num_of_keys;
	num_of_keys--;

	delete(r_child);
	return;
}

void btree_node::borrow(int index)
{
	cout << "trying to borrow!" << endl;
	if (index != 0 && child_ptr_array[index - 1]->num_of_keys >= min_deg)
	{
		cout << "trying to left borrow!" << endl;
		left_borrow(index);
	}

	else if (index != num_of_keys && child_ptr_array[index + 1]->num_of_keys >= min_deg)
	{
		cout << "nope trying to right borrow!" << endl;
		right_borrow(index);
	}

	else
	{
		if (index != num_of_keys)
			merge(index);
		else
			merge(index - 1);
	}
	cout << "succesfful borrow" << endl;
	return;
}

void btree_node::left_borrow(int index)
{

	btree_node * l_child = child_ptr_array[index];
	btree_node * r_child = child_ptr_array[index - 1];
		
	cout << "left borrowning!!!" << endl;
	for (int i = l_child->num_of_keys - 1; i >= 0; --i)
	{
		
		l_child->keys_array[i + 1] = l_child->keys_array[i];
		cout << "copying keys as needed" << endl;
	}
		
	if (!l_child->leaf_status)
	{
		for (int i = l_child->num_of_keys; i >= 0; --i)
			l_child->child_ptr_array[i + 1] = l_child->child_ptr_array[i];
	}
	
	l_child->keys_array[0] = keys_array[index - 1];
	cout << "here?" << endl;
	if (!leaf_status)
		l_child->child_ptr_array[0] = r_child->child_ptr_array[r_child->num_of_keys];
	cout << "left borrow duly completed" << endl;
	keys_array[index - 1] = r_child->keys_array[r_child->num_of_keys - 1];
	l_child->num_of_keys += 1;
	r_child->num_of_keys -= 1;
	return;
}
void btree_node::right_borrow(int index)
{
	btree_node * l_child = child_ptr_array[index];
	btree_node * r_child = child_ptr_array[index + 1];

	l_child->keys_array[l_child->num_of_keys] = keys_array[index];

	if (!(l_child->leaf_status))
		l_child->child_ptr_array[(l_child->num_of_keys) + 1] = r_child->child_ptr_array[0];

	
	keys_array[index] = r_child->keys_array[0];

	
	for (int i = 1; i<r_child->num_of_keys; ++i)
		r_child->keys_array[i - 1] = r_child->keys_array[i];

	
	if (!r_child->leaf_status)
	{
		for (int i = 1; i <= r_child->num_of_keys; ++i)
			r_child->child_ptr_array[i - 1] = r_child->child_ptr_array[i];
	}

	l_child->num_of_keys += 1;
	r_child->num_of_keys -= 1;

	return;
}
