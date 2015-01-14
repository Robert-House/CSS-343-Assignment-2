#pragma once

#include "TreeData.h"

using namespace std;

class BSTree
{
public:
	BSTree();
	BSTree(const BSTree &source);
	~BSTree();

	// Operator Overloads
	void operator=(const BSTree &source); // Should already exist. Use default copy constructor
	bool operator==(const BSTree &rightSide);
	bool operator!=(const BSTree &rightSide);

	// Accessors
	const TreeData* retrieve();

private:
	struct Node
	{
		Node *next;
		TreeData *item;
	};
};