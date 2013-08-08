#include <cstdlib>
#include <iostream>
#include "BST.h"

template<class KEYTYPE, class DATATYPE>
BST<KEYTYPE, DATATYPE>::Node::Node(const KEYTYPE &key, const DATATYPE &data)
	: key(key), data(data), left(NULL), right(NULL)
{
	/*
	** ALL FUNCTIONALITY PROVIDED, SEE INITIALISATION LIST
	*/
}

template<class KEYTYPE, class DATATYPE>
BST<KEYTYPE, DATATYPE>::BST(void)
{
	_TreeRoot = NULL; // Initialize root of tree to NULL
}

template<class KEYTYPE, class DATATYPE>
void BST<KEYTYPE, DATATYPE>::DestructorWorker(const Node *node)
{

	if (node != NULL)
	{
		DestructorWorker(node->left); // delete left node references
		DestructorWorker(node->right); // delete right node references
		delete node; // remove node
		node = NULL; // set final node to null
	}
}

template<class KEYTYPE, class DATATYPE>
BST<KEYTYPE, DATATYPE>::~BST(void)
{
	DestructorWorker(_TreeRoot); // destroy tree using recursive method
}

template<class KEYTYPE, class DATATYPE>
bool BST<KEYTYPE, DATATYPE>::Find(const KEYTYPE key, DATATYPE *output) const
{
	
	// initialize vars & ptrs
	Node *current;
	bool found = false;

	// Commence search
	if (_TreeRoot == NULL)
		return found; // false if tree is empty
	else
	{
		current = _TreeRoot;
		// traverse BST for search key
		while (current != NULL && !found)
		{
			*output = current->data; // assign student data to output

			if (current->key == key)
				
				found = true; // search result found
			
			else if (current->key > key)
				current = current->left; // traverse left tree
			else
				current = current->right; // traverse right tree
		}
	}

	return found;
}

template<class KEYTYPE, class DATATYPE>
unsigned int BST<KEYTYPE, DATATYPE>::HeightWorker(const Node *node) const
{
	unsigned int result = 0; // variable to return height

	// Commence height operation
	if (node != NULL)
	{
		
		if (node->left == NULL && node->right == NULL)
			result = 1; // return result for single node
		else
		{
			result = HeightWorker(node->left); // count height of left tree
			unsigned int rightHeight = HeightWorker(node->right);
			if(rightHeight > result)
				result = rightHeight; // count height of right tree
			result++;
		}
	}

	return result;
}

template<class KEYTYPE, class DATATYPE>
unsigned int BST<KEYTYPE, DATATYPE>::Height(void) const
{
	return HeightWorker(_TreeRoot); // execute recursive height function on tree root
}

template<class KEYTYPE, class DATATYPE>
void BST<KEYTYPE, DATATYPE>::InOrderWorker(std::ostream &ostr, const Node *node) const
{
	// Traverse BST and output in order
	if(node != NULL)
	{
		InOrderWorker(ostr, node->left); // traverse left tree
		ostr << node->data << std::endl;
		InOrderWorker(ostr, node->right); // traverse right tree
	}
}

template<class KEYTYPE, class DATATYPE>
void BST<KEYTYPE, DATATYPE>::InOrder(std::ostream &ostr)
{
	InOrderWorker(ostr, _TreeRoot); // execute recursive In-Order function on tree root
}

template<class KEYTYPE, class DATATYPE>
void BST<KEYTYPE, DATATYPE>::Insert(const KEYTYPE key, const DATATYPE data)
{
	// Initialize tracking nodes
	Node *current;
	Node *trailCurrent;

	// Initialize insertion node
	Node *newNode = new Node(key, data);
	newNode->key = key;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	// Commence insertion
	if (_TreeRoot == NULL)
		_TreeRoot = newNode; // Start at tree root
	else
	{
		current = _TreeRoot;

		while (current != NULL)
		{
			trailCurrent = current; // track current node

			if (current->key == key)
			{
				//Display appropriate error for duplicate entry
				return;
			}
			else if (current->key > key)
				current = current->left; // insert current node into left tree
			else
				current = current->right; // otherwise right tree
		}

		if (trailCurrent->key > key)
			trailCurrent->left = newNode; // insert parent node into left tree
		else
			trailCurrent->right = newNode; // otherwise right tree
	}
}

#include "Student.h"
template class BST<unsigned int, Student>;
