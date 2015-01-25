#pragma once

#include "TreeData.h"
#include <string>

using namespace std;

class BSTree
{
public:
	BSTree();
	BSTree(string filePath);
	BSTree(const BSTree &source);
	~BSTree();

	// Operator Overloads
	void operator=(const BSTree &source); // Should already exist. Use default copy constructor
	bool operator==(const BSTree &rightSide);
	bool operator!=(const BSTree &rightSide);

	// Accessors
	const TreeData* retrieve(const TreeData &data) const;
	int depth(const TreeData &data) const;
	int descendants(const TreeData &) const;
	bool isEmpty() const;

	// Mutators
	bool insert(TreeData *data);
	bool remove(TreeData *data);
	void makeEmpty();

private:
	struct Node
	{
		Node *right;
		Node *left;
		TreeData *item;
	};

	Node *_head;
	bool LoadFromFile(string filePath);
	bool NukeItFromOrbit();
	bool rInsert(Node* node, TreeData *data);
	bool rRemove(Node* node, TreeData *data);
};