#pragma once

#include "TreeData.h"
#include <string>
#include <fstream>

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
	friend ostream& operator<<(ostream &out, const BSTree &tree);
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
		Node *right = nullptr;
		Node *left = nullptr;
		TreeData *item;
	};

	Node *_head;
	bool LoadFromFile(string filePath);
	bool NukeItFromOrbit();
	const TreeData* rRetrieve(Node *node, const TreeData &data) const;
	int rDepth(Node *node, const TreeData &data, int depth) const;
	bool rInsert(Node* node, TreeData *data);
	bool rRemove(Node* node, TreeData *data);
	void print(Node *node, ostream &out) const;
};