#pragma once
#include "btree.h"
#include <iostream>
using namespace std;

//BTREE constructor takes the minimum degree
BTREE::BTREE(int max_deg)
{
	//initialize minimum degree
	this->max_deg = max_deg;
	min_deg = ceil(max_deg / 2.0);
	//initialize root as NULL
	root = NULL;
}
//BTREE insertion function
//NOTE: Our implementation uses a preemptive split;
//concretely, once the root is full on an insertion call,
//the root is immediately split regardless of whether
//the new key goes into the root or not
void BTREE::insert(int new_key)
{
	cout << "Inserting: " << new_key << "." << endl;
	//First case of empty tree
	if (root == NULL)
	{
		// make new root
		root = new btree_node(max_deg, true);
		root->keys.push_back(new_key);
		// update number of keys and leaf status
		root->num_of_keys = 1;  
		root->leaf_status = true;
	}
	else // general case: tree not empty, root is not NULL
	{
		// if the root node is full
		if (root->num_of_keys == max_deg - 1)
		{
			// make new root
			btree_node * temp_node = new btree_node(max_deg, false);
			//increase its vector size
			temp_node->keys.resize(1);
			//make new root point to old root
			temp_node->child_ptr_array[0] = root;

			//split the old root
			temp_node->split_node(0, root);
			
			//figure out where to place key
			int running_index = 0;
			if (temp_node->keys[0] < new_key)
				running_index++;
			
			//call insert on the correct child
			cout << temp_node->child_ptr_array[running_index]->leaf_status << endl;
			temp_node->child_ptr_array[running_index]->insert(new_key);

			root = temp_node; //update root
		}
		else  //if root is not, full just insert
			root->insert(new_key);
	}
}
void BTREE::print_pre_order()
{
	cout << "Start: Printing BTREE" << endl;
	if (root == NULL)
	{
		cout << "This tree has nothing in it. No further operations may be conducted." << endl;
		return;
	}
	if (root->num_of_keys > 0)
	{	
		root->print_pre_order();
	}
	else
	{
		cout << "Tree is empty." <<	 endl;
	}
	cout << "\nEnd: Printing BTREE" << endl;
}
void BTREE::delete_key(int target)
{
	cout << "Attempting to delete " << target << endl;
	if (root == NULL)
	{
		cout << "This tree is in NULL state. No further operations may be conducted." << endl;
		return;
	}
	root->rem_key(target);
	if (root->num_of_keys == 0)
	{
		btree_node * temp = root;
		if (root->leaf_status)
		{
			cout << "Root is now a leaf." << endl;
		}
		else
		{
			root = root->child_ptr_array[0];
			delete temp;
		}
		
	}
}
bool BTREE::search(int target)
{
	cout << "Searching for: " << target << endl;
	if (root == NULL)
	{
		cout << "This tree has been destroyed. No further operations may be conducted." << endl;
		return false;
	}
	bool found = root->search(target);
	if (found)
	{
		cout << target << " was found." << endl;
	}
	else
	{
		cout << target << " was not found." << endl;
	}
	cout << "Search Ended." << endl;
	return found;
}
void BTREE::destroy()
{
	if (root == NULL)
	{
		cout << "This tree has been destroyed. No further operations may be conducted." << endl;
		return;
	}
	root->destroy();
	btree_node * temp = root;
	root = NULL;
	delete temp;
	cout << "Tree Destroyed" << endl;
}
btree_node::btree_node(int max_deg, bool is_leaf)
{
	child_ptr_array = new btree_node*[ max_deg ];
	num_of_keys = 0;
	leaf_status = is_leaf;
	this->max_deg = max_deg;
	min_deg = ceil(max_deg / 2.0);
}
void btree_node::insert(int new_key)
{
	int last_key_index = num_of_keys - 1;
	if (leaf_status == true)//if it is a leaf
	{
		//leaf insert doesn't need to check for full node because the function is called
		//only when the parent has checked that it is not full
		int running_index;
		//increase the vector of keys by 1
		keys.resize(num_of_keys + 1);
		//find the right position for the key
		for (running_index = last_key_index; running_index >= 0 && keys[running_index] > new_key; running_index--)
		{
			keys[running_index + 1] = keys[running_index];
		}
		//insert the new key;
		keys[running_index + 1] = new_key;
		num_of_keys++;
	}
	else
	{
		int running_index;
		//perform insert on non leaf node
		//find the appropriate index for the 
		for (running_index = last_key_index; running_index >= 0 && keys[running_index] > new_key; running_index--)
		{		}
		//if the appropriate child is full, split the child accordingly
		if (child_ptr_array[running_index + 1]->num_of_keys ==  max_deg - 1) //if the child the appropriate place happens to be full
		{
			split_node(running_index + 1, child_ptr_array[running_index + 1]);//split the child
			if (keys[running_index + 1] < new_key)
			{
				running_index++;
			}
		}
		//then, insert the key into that child
		child_ptr_array[running_index + 1]->insert(new_key);	
		cout << "Non-leaf insert success!" << endl;
	}

}
//split_node splits the child of the node which calls the function
void btree_node::split_node(int index, btree_node * full_child)
{
	cout << "Splitting node!" << endl;
	//make a new node
	btree_node * temp_node = new btree_node(full_child->max_deg, full_child->leaf_status);//make a temp node similar to the full one
	temp_node->keys.resize(min_deg - 1);
	
	int running_index;

	//copy one less than half of the keys in the full node's array into the temp node
	for (running_index = 0; running_index < min_deg - 1; running_index++)
	{																	 
		temp_node->keys[running_index] = full_child->keys[min_deg + running_index - 1];
		full_child->num_of_keys--;
		temp_node->num_of_keys++;
	}
	//if full_child is not a leaf node, we also need to copy its child pointers!
	//to temp node
	if (!(full_child->leaf_status))
	{
		for (running_index = 0; running_index < min_deg; running_index++)
		{
			temp_node->child_ptr_array[running_index] = full_child->child_ptr_array[min_deg + running_index - 1];
		}
	}
	//since parent full child will have new children, create pointers allocate pointer in
	//child array for the new children
	//concretely, shift all former pointers right, once
	if (num_of_keys > 1)
	{//can't  remember why I differentiated between number of keys > 1 and < 1 :)
		for (running_index = num_of_keys; running_index > index + 1; running_index--)
		{
			child_ptr_array[running_index + 1] = child_ptr_array[running_index];
		}
	}
	else
	{
		for (running_index = num_of_keys; running_index >= index + 1; running_index--)
		{
			child_ptr_array[running_index + 1] = child_ptr_array[running_index];
		}
	}
	//then, at the correct child, point to temp node:
	child_ptr_array[index + 1] = temp_node;
	//we need to promote one of the keys of the full_child,
	//we make space in the parent node's key vector, and
	//shift all the keys right of the index further right by 1
	keys.resize(num_of_keys + 1);
	for (running_index = num_of_keys - 1; running_index >= index; running_index--)
	{
		keys[running_index + 1] = keys[running_index];
	}
	//place promoted key appropriately
	keys[running_index + 1] = full_child->keys[min_deg - 2];
	//furhter decrease the number of keys by 1 and change vector size
	full_child->num_of_keys--;
	full_child->keys.resize(full_child->num_of_keys);
	//increase parent number of keys by 1
	num_of_keys++;	
	cout << "Split completed" << endl;
}
void btree_node::print_pre_order()
{
	for (int i = 0; i < num_of_keys; i++)
	{
		cout << keys[i] << " ";
	}
	if (!leaf_status)
	{
		for (int i = 0; i <= num_of_keys; i++)
		{
			child_ptr_array[i]->print_pre_order();
		}
	}
}
int btree_node::find_key_index(int target) 
{	//returns index of the first key that is greater than the target
	int running_index = 0;
	while (running_index < num_of_keys && keys[running_index] < target)
	{
		running_index++;
	}
	return running_index;
}
void btree_node::rem_key(int target)
{
	int index = 0;
	//find the position the target would be at in the node
	for (int i = 0; i < num_of_keys && keys[i] < target; i++)
	{
		index++;
	}
	index = index >= num_of_keys ? num_of_keys - 1 : index;
	if (leaf_status)
	{
		//if it is found in a leaf node, delete it straight away
		if (keys[index] == target)
		{
			keys.erase(keys.begin() + index);
			num_of_keys--;
			keys.resize(num_of_keys);
		}
		else
		{
			cout << "Not in this tree!" << endl;
		}
	}
	else
	{
		//it is is found in a non leaf node,
		//find predecessor or successor
		//**we have arbitrarily called successor predecessor
		if (index < num_of_keys && keys[index] == target)
		{
			int predecessor;
			if (child_ptr_array[index]->num_of_keys > child_ptr_array[index + 1]->num_of_keys)
			{
				// if the previous child has sufficient children, get the predecessor
				btree_node * temp_node = child_ptr_array[index];
				while (!temp_node->leaf_status)
					temp_node = temp_node->child_ptr_array[temp_node->num_of_keys];

				//get predecessor and place it appropriately
				predecessor = temp_node->keys[temp_node->num_of_keys - 1];
				keys[index] = predecessor;

				//remove predecessor frmo where it might have been
				child_ptr_array[index]->rem_key(predecessor);

				//if removal of predecessor caused underflow, fix it by borrowing
				if (child_ptr_array[index]->num_of_keys < min_deg - 1)
				{
					borrow(index);
				}
			}
			else if (child_ptr_array[index]->num_of_keys <= child_ptr_array[index + 1]->num_of_keys)
			{	//HERE "PREDECESSOR" IS REALLY SUCCESSOR!!!!!!!!!!!!!!!!!!!!1
				//if instead the next child has sufficient children, get the predecessor (*successor)
				btree_node * temp_node = child_ptr_array[index + 1];
				while (!temp_node->leaf_status)
					temp_node = temp_node->child_ptr_array[0];

				//get predecessor and place it appropriately
				predecessor = temp_node->keys[0];
				keys[index] = predecessor;
				child_ptr_array[index + 1]->rem_key(predecessor);

				//if removal of predecessor(successor)  cause dunderflow,
				//remove predecessor as well
				if (child_ptr_array[index + 1]->num_of_keys < min_deg - 1)
				{
					borrow(index + 1);
				}
			}
		}
		else
		{	//if target wasn't found in the node
			//attempt to remove from appropriate child
			child_ptr_array[index]->rem_key(target);
			if (child_ptr_array[index]->num_of_keys < min_deg - 1)
			{
				borrow(index);
			}
		}
	}
}
//merge brings the key at index down into the appropriate child
//it merges into the left child
void btree_node::merge(int index)
{
	int running_index = 0;
	//ponint to left child and right child
	btree_node * l_child = child_ptr_array[index];
	btree_node * r_child = child_ptr_array[index + 1];
	
	//create space for the new key in the appropriate place
	l_child->keys.resize(l_child->num_of_keys + 1);
	l_child->keys[l_child->num_of_keys] = keys[index];
	l_child->num_of_keys++;
	
	running_index = l_child->num_of_keys;
	int temp_running_index = 0;
	//make space in the left child for all the keys in the right child
	l_child->keys.resize(l_child->num_of_keys + r_child->num_of_keys);
	
	//copy all the keys in right child ito left child
	while (temp_running_index < r_child->num_of_keys)
	{
		l_child->keys[running_index] = r_child->keys[temp_running_index];
		running_index++;
		temp_running_index++;
	}
	
	//if left child is not a leaf, we also need to copy the pointers from right child
	if (!l_child->leaf_status)
	{
		for (int i = 0; i <= r_child->num_of_keys; ++i)
		{
			l_child->child_ptr_array[l_child->num_of_keys  + i ] = r_child->child_ptr_array[i];
			
		}
	}

	//shift remaining keys in node appropriately (after one key has ben demoted)
	for (int i = index + 1; i < num_of_keys; ++i)
	{
		keys[i - 1] = keys[i];
	}
	//also shilft chilf pointer appropriately
	for (int i = index + 2; i <= num_of_keys; ++i)
		child_ptr_array[i - 1] = child_ptr_array[i];

	//adjust left child's number of keys appropriately
	l_child->num_of_keys += r_child->num_of_keys;
	//decrease parent keys by one
	num_of_keys--;

	//delete right child
	delete(r_child);
	return;
}
void btree_node::borrow(int index)
{
	//borrow from which ever child has sufficient keys
	if (index != 0 && child_ptr_array[index - 1]->num_of_keys >= min_deg)
	{
		left_borrow(index);
	}
	else if (index != num_of_keys && child_ptr_array[index + 1]->num_of_keys >= min_deg)
	{
		right_borrow(index);
	}
	else
	{
		//if neither does, merge!
		if (index != num_of_keys)
			merge(index);
		else
			merge(index - 1);
	}
	return;
}
void btree_node::left_borrow(int index)
{
	btree_node * r_child = child_ptr_array[index];
	btree_node * l_child = child_ptr_array[index - 1];
	

	r_child->keys.resize(r_child->num_of_keys + 1);
	r_child->keys[0] = keys[index];

	//copy appropriate pointer also if necessary
	if (!(r_child->leaf_status))
		r_child->child_ptr_array[0] = l_child->child_ptr_array[l_child->num_of_keys];

	//get the last key of left child	
	keys[index] = l_child->keys[l_child->num_of_keys - 1];

	//if left child is not a leaf, copy its pointers appropriately
	if (!l_child->leaf_status)
	{
		for (int i = l_child->num_of_keys; i >= 0; --i)
			l_child->child_ptr_array[i + 1] = l_child->child_ptr_array[i];
	}
	
	//if parent itself is not a leaf, 
	if (!leaf_status)
		r_child->child_ptr_array[0] = l_child->child_ptr_array[l_child->num_of_keys];
		
	//adjust number of keys sizes asa ppropriate
	r_child->num_of_keys += 1;
	//l_child->child_ptr_array[l_child->num_of_keys] = NULL;
	l_child->child_ptr_array += 1;
	l_child->num_of_keys -= 1;
	l_child->keys.resize(l_child->num_of_keys);
	return;
}
void btree_node::right_borrow(int index)
{
	btree_node * l_child = child_ptr_array[index];
	btree_node * r_child = child_ptr_array[index + 1];

	//prepare left child for additional key adn assign value
	l_child->keys.resize(num_of_keys + 1);
	l_child->keys[l_child->num_of_keys] = keys[index];
	//copy appropriate pointer also if necessary
	if (!(l_child->leaf_status))
		l_child->child_ptr_array[(l_child->num_of_keys) + 1] = r_child->child_ptr_array[0];

	
	keys[index] = r_child->keys[0];
	
	//move right childs keys to the left
	for (int i = 1; i< r_child->num_of_keys; ++i)
		r_child->keys[i - 1] = r_child->keys[i];

	//if right child is not  leaf, move right child's child pointer to the left
	if (!r_child->leaf_status)
	{
		for (int i = 1; i <= r_child->num_of_keys; ++i)
			r_child->child_ptr_array[i - 1] = r_child->child_ptr_array[i];
	}
	//update number of keys as appropriate
	l_child->num_of_keys += 1;
	r_child->num_of_keys -= 1;
	r_child->keys.resize(r_child->num_of_keys);
	return;
}
bool btree_node::search(int target)
{
	bool found = true;
	int running_index = 0;
	/*while (running_index < num_of_keys && keys_array[running_index] < target)*/
	while (running_index < num_of_keys && keys[running_index] < target)
	{
		running_index += 1;
	}
	if (running_index < num_of_keys)
	{
		/*if (keys_array[running_index] == target)*/
		if (keys[running_index] == target)
		{
			found = true;
		}
		else if (!leaf_status)
		{
			found = child_ptr_array[running_index]->search(target);
		}
		else
		{
			found = false;
		}
	}
	else
	{
		if (leaf_status)
		{
			found = false;
		}
		else
		{
			found = child_ptr_array[running_index]->search(target);
		}
	}
	return found;
}
void btree_node::destroy()
{
	if (!leaf_status)
	{
		for (int i = 0; i <= num_of_keys; i++)
		{
			if (!child_ptr_array[i]->leaf_status)
			{
				child_ptr_array[i]->destroy();
				btree_node * temp = child_ptr_array[i];
				child_ptr_array[i] = NULL;
				delete temp;
			}
			else
			{
				btree_node * temp = child_ptr_array[i];
				child_ptr_array[i] = NULL;
				delete temp;
			}
		}
	}
	else
	{
		return;
	}
}
