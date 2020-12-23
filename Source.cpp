#include "Header.h"
#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;
int main()
{
	int keys;
	Tree* tree = new Tree;
	cout << "Fill in the integer key of root of the binary search tree:\n";
	cin >> keys;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	tree->get_root(keys);
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter the key of inserting element:\n";
		cin >> keys;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		tree->insert(keys);
	}
	cout << "Enter the searching key:\n";
	cin >> keys;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	if (tree->contains(keys) == true)
		cout << "Element " << keys << " is contained in the tree.\n";
	else
		cout << "Element " << keys << " is not contained in the tree.\n";
	cout << "Enter the deleting key:\n";
	cin >> keys;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	if (tree->contains(keys) == true)
		tree->remove(keys);
	else
		cout << "Element " << keys << " is not contained in the tree.\n";
	tree->create_queue();
	cout << "\nbft_iteration:\n";
	Iterator* iter;
	iter = tree->create_bft_iterator();
	cout << "|" << tree->start->key << "|";
	while (iter->has_next())
		cout << iter->next() << "|";
	cout << endl;
	tree->create_stack();
	cout << "\ndft_iteration:\n";
	iter = tree->create_dft_iterator();
	cout << "|" << tree->start->key << "|";
	while (iter->has_next())
		cout << iter->next() << "|";
	cout << endl;
	tree->deleting_tree();
	cout << "Done.\n";
	delete iter;
}
void Tree::get_root(int key)
{
	if (root == NULL)
	{
		BST* elem = new BST;
		elem->key = key;
		root = elem;
		root->left = NULL;
		root->right = NULL;
	}
}
void Tree::insert(int key)
{
	current = root;
	if (key == current->key)
	{
		cout << "Error! This key is already contained in the tree!\n";
		return;
	}
point:
	while (current->left != NULL && current->right != NULL)
	{
		if (key < current->key)
		{
			current = current->left;
		}
		else if (key > current->key)
		{
			current = current->right;
		}
		else
		{
			cout << "Error! This key is already contained in the tree!\n";
			return;
		}
	}
	if (key < current->key)
	{
		if (current->left == NULL)
		{
			BST* elem = new BST;
			elem->key = key;
			elem->left = NULL;
			elem->right = NULL;
			current->left = elem;
		}
		else
		{
			current = current->left;
			goto point;
		}
	}
	else if (key > current->key)
	{
		if (current->right == NULL)
		{
			BST* elem = new BST;
			elem->key = key;
			elem->left = NULL;
			elem->right = NULL;
			current->right = elem;
		}
		else
		{
			current = current->right;
			goto point;
		}
	}
	else
	{
		if (key == current->key)
		{
			cout << "Error! This key is already contained in the tree!\n";
			return;
		}
	}
}
bool Tree::contains(int key)
{
	current = root;
	if (key == current->key)
	{
		return true;
	}
point:
	while (current->left != NULL && current->right != NULL)
	{
		if (key < current->key)
		{
			current = current->left;
		}
		else if (key > current->key)
		{
			current = current->right;
		}
		else
		{
			return true;
		}
	}
	if (key < current->key)
	{
		if (current->left == NULL)
		{
			return 0;
		}
		else
		{
			current = current->left;
			goto point;
		}
	}
	else if (key > current->key)
	{
		if (current->right == NULL)
		{
			return 0;
		}
		else
		{
			current = current->right;
			goto point;
		}
	}
	else
	{
		if (key == current->key)
		{
			return true;
		}
	}
}
void Tree::remove(int key)
{
	current = root;
	while (true)
	{
		if (key < current->key && current->left->key != key)
		{
			current = current->left;
		}
		else if (key > current->key && current->right->key != key)
		{
			current = current->right;
		}
		else
		{
			if (current->key == key)
			{
				if (current->left == NULL && current->right == NULL)
				{
					current = NULL;
					root = NULL;
				}
				else if (current->left == NULL && current->right != NULL)
				{
					current = current->right;
				}
				else if (current->left != NULL && current->right == NULL)
				{
					current = current->left;
				}
				else
				{
					BST* point;
					point = current;
					point = point->right;
					if (point->left == NULL)
					{
						current->key = point->key;
						current->right = point->right;
						return;
					}
					BST* point1;
					point1 = current;
					point1 = point1->right;
					while (point1->left != NULL)
						point1 = point1->left;
					while (point->left != point1)
						point = point->left;
					if (point1->right == NULL)
					{
						current->key = point1->key;
						point->left = NULL;
					}
					else
					{
						current->key = point1->key;
						point->left = point1->right;
					}
					point = NULL;
					point1 = NULL;
					delete point, point1;
				}
				return;
			}
			else if (current->right != NULL && current->right->key == key)
			{
				BST* point;
				point = current;
				point = point->right;
				if (point->left == NULL && point->right == NULL)
				{
					current->right = NULL;
				}
				else if (point->left == NULL && point->right != NULL)
				{
					current->right = point->right;
				}
				else if (point->left != NULL && point->right == NULL)
				{
					current->right = point->left;
				}
				else
				{
					point = point->right;
					if (point->left == NULL)
					{
						current->right->key = point->key;
						current->right->right = point->right;
						point = NULL;
						delete point;
						return;
					}
					BST* point1;
					point1 = point;
					while (point1->left != NULL)
						point1 = point1->left;
					while (point->left != point1)
						point = point->left;
					if (point1->right == NULL)
					{
						current->right->key = point1->key;
						point->left = NULL;
					}
					else
					{
						current->right->key = point1->key;
						point->left = point1->right;
					}
				}
				point = NULL;
				delete point;
				return;
			}
			else
			{
				BST* point;
				point = current;
				point = point->left;
				if (point->left == NULL && point->right == NULL)
				{
					current->left = NULL;
				}
				else if (point->left == NULL && point->right != NULL)
				{
					current->left = point->right;
				}
				else if (point->left != NULL && point->right == NULL)
				{
					current->left = point->left;
				}
				else
				{
					point = point->right;
					if (point->left == NULL)
					{
						current->left->key = point->key;
						current->left->right = point->right;
						point = NULL;
						delete point;
						return;
					}
					BST* point1;
					point1 = point;
					while (point1->left != NULL)
						point1 = point1->left;
					while (point->left != point1)
						point = point->left;
					if (point1->right == NULL)
					{
						current->left->key = point1->key;
						point->left = NULL;
					}
					else
					{
						current->left->key = point1->key;
						point->left = point1->right;
					}
					point = NULL;
					point1 = NULL;
					delete point,point1;
				}
				return;
			}
		}
	}
}
void Tree::create_queue()
{
	BST* marker;
	BST* finish;
	start = root;
	if (start == NULL)
	{
		return;
	}
	start->next = NULL;
	finish = start;
	marker = start;
	if (marker->left != NULL)
	{
		finish->next = marker->left;
		finish = finish->next;
		finish->next = NULL;
	}
	if (marker->right != NULL)
	{
		finish->next = marker->right;
		finish = finish->next;
		finish->next = NULL;
	}
	marker = marker->next;
	while (true)
	{
		if (marker->left != NULL)
		{
			finish->next = marker->left;
			finish = finish->next;
			finish->next = NULL;
		}
		if (marker->right != NULL)
		{
			finish->next = marker->right;
			finish = finish->next;
			finish->next = NULL;
		}
		if (marker->left == NULL && marker->right == NULL && marker->next == NULL)
		{
			break;
		}
		marker = marker->next;
	}
	marker = NULL;
	finish = NULL;
	delete marker;
	delete finish;
	return;
}
void Tree::create_stack()
{
	BST* stack;
	BST* prev;
	BST* finish;
	BST* marker;
	stack = NULL;
	start = root;
	finish = start;
	marker = root;
	finish->next = NULL;
	if (marker->right != NULL)
	{
		stack = marker->right;
		stack->next = NULL;
	}
	if (marker->left != NULL)
	{
		marker = marker->left;
		finish->next = marker;
		finish = finish->next;
	}
	while (true)
	{
		if (marker->right != NULL)
		{
			if (stack == NULL)
			{
				stack = marker->right;
				stack->next = NULL;
			}
			else
			{
				prev = marker->right;
				prev->next = stack;
				stack = prev;
			}
		}
		if (marker->left != NULL)
		{
			
			marker = marker->left;
			finish->next = marker;
			finish = finish->next;
		}
		else if (stack != NULL)
		{
			marker = stack;
			finish->next = marker;
			finish = finish->next;
			stack = stack->next;
		}
		else
			break;
	}
	stack = NULL;
	prev = NULL;
	finish = NULL;
	marker = NULL;
	delete stack;
	delete prev;
	delete finish;
	delete marker;
}
Tree::bft_iterator::bft_iterator(BST* start)
{
	begin = start;
}
Tree::dft_iterator::dft_iterator(BST* start)
{
	begin = start;
}
void Tree::deleting_tree()
{
	create_queue();
	while (start != NULL)
	{
		BST* deleter;
		deleter = start;
		deleter->left = NULL;
		deleter->right = NULL;
		start = start->next;
		delete deleter;
	}
	cout << "The destructor has finished deleting the specified elements." << endl;
}