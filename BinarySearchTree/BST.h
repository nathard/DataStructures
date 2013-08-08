#ifndef _BST_H
#define _BST_H

#include <iostream>

template <class KEYTYPE, class DATATYPE>
class BST
{
private:
	struct Node
	{
		KEYTYPE key;
		DATATYPE data;
		Node *left;
		Node *right;
		Node(const KEYTYPE &key, const DATATYPE &data);
	};
	Node *_TreeRoot;
	void DestructorWorker(const Node *node);
	unsigned int HeightWorker(const Node *node) const;
	void InOrderWorker(std::ostream &ostr, const Node *node) const;

public:
	BST(void);
	~BST(void);
	bool Find(const KEYTYPE key, DATATYPE *output) const;
	unsigned int Height(void) const;
	void InOrder(std::ostream &ostr);
	void Insert(const KEYTYPE key, const DATATYPE data);
};

#endif // _BST_H
