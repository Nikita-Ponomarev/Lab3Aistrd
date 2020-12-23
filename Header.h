#pragma once
#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;
class Iterator
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};
class BST
{
	
	class BST* left;
	class BST* right;
	class BST* next;
	friend class Tree;
	friend class Iterator;
public:
	int key;
	BST()
	{
		left = NULL;
		right = NULL;
		next = NULL;
	}
};
class Tree
{
	class BST* current;
	class BST* root;
	Iterator* bftiterator;
	Iterator* dftiterator;
	friend class Iterator;
public:
	class BST* start;
	class bft_iterator : public Iterator
	{
		class BST* begin;
	public:
		bft_iterator(BST* start);

		int next() override
		{
			if (!has_next())
				throw out_of_range("no more elements\n");
			if (begin->next != NULL)
			{
				begin = begin->next;
			}
			return begin->key;
		}
		bool has_next() override
		{
			if (begin->next == NULL)
			{
				return false;
			}
			else return true;
		}
		~bft_iterator()
		{
			delete begin;
		}
	};
	class dft_iterator : public Iterator
	{
		class BST* begin;
	public:
		dft_iterator(BST* start);

		int next() override
		{
			if (!has_next())
				throw out_of_range("no more elements\n");
			if (begin->next != NULL)
			{
				begin = begin->next;
			}
			return begin->key;
		}
		bool has_next() override
		{
			if (begin->next == NULL)
			{
				return false;
			}
			else return true;
		}
		dft_iterator()
		{
			delete begin;
		}
	};
	Iterator* create_bft_iterator()
	{
		bftiterator = new bft_iterator(start);
		return bftiterator;
	}
	Iterator* create_dft_iterator()
	{
		dftiterator = new dft_iterator(start);
		return dftiterator;
	}
	Tree()
	{
		root = NULL;
		current = NULL;
		start = NULL;
	}
	~Tree()
	{
		delete root;
		delete current;
		delete start;
		delete bftiterator;
		delete dftiterator;
		cout << "The destructor has finished deleting the specified elements." << endl;
	}
	void get_root(int);
	void insert(int);
	bool contains(int);
	void remove(int);
	void create_queue();
	void create_stack();
	void deleting_tree();
};
