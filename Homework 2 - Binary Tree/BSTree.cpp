#pragma once

#include "BSTree.h"

BSTree::BSTree()
{

}

BSTree::BSTree(string filePath)
{
	_head = nullptr;
	LoadFromFile(filePath);
}

BSTree::BSTree(const BSTree &source)
{

}

BSTree::~BSTree()
{
	// Its the only way to be sure.....
	NukeItFromOrbit();
}

// OPERATOR OVERLOADS
void BSTree::operator=(const BSTree &source)
{

}

bool BSTree::operator==(const BSTree &rightSide)
{
	return false;
}

bool BSTree::operator!=(const BSTree &rightSide)
{
	return false;
}

// Accessors
const TreeData* BSTree::retrieve(const TreeData &data) const
{
	return rRetrieve(_head, data);
}

int BSTree::depth(const TreeData &data) const
{
	return rDepth(_head, data, 0);
}

int BSTree::descendants(const TreeData &desc) const
{
	return -1;
}

bool BSTree::isEmpty() const
{
	// case: empty
	return (_head == nullptr);
}

bool BSTree::insert(TreeData *data)
{
	if (_head == nullptr)
	{
		// Create first node and assign the data
		// to the node
		Node *temp = new Node();
		temp->item = data;
		_head = temp;

		return true;
	}

	// Else, recursively run through the binary tree
	return rInsert(_head, data);
}

bool BSTree::remove(TreeData *data)
{
	if (_head == nullptr)
	{
		return false;
	}

	return rRemove(_head, data);
}

ostream& operator<<(ostream &out, const BSTree &tree)
{
	tree.print(tree._head, out);
	return out;
}


//
//
//Priavte Members
bool BSTree::LoadFromFile(string filePath)
{
	ifstream fin;
	TreeData *data;
	char tempChar = ' ';

	fin.open(filePath);

	while (fin.get(tempChar))
	{
		data = new TreeData(tempChar);
		insert(data);
	}

	return true;
}

const TreeData* BSTree::rRetrieve(Node *node, const TreeData &data) const
{
	if (*node->item == &data)
	{
		return node->item;
	}
	else if (*node->item < &data)
	{
		return rRetrieve(node->left, data);
	}
	else
	{
		return rRetrieve(node->right, data);
	}

	return nullptr;
}

int BSTree::rDepth(Node *node, const TreeData &data, int depth) const
{
	if (node == nullptr)
	{
		return -1;
	}
	else if (*node->item == &data)
	{
		return depth;
	}
	else if (&data < node->item)
	{
		rDepth(node->left, data, depth + 1);
	}
	else if (&data > node->item)
	{
		rDepth(node->right, data, depth + 1);
	}
	
	// Not found
	return -1;
}

bool BSTree::rInsert(Node *node, TreeData *data)
{
	if (*node->item == data)
	{
		node->item->addOne();
		return false;
	}
	
	// Pre-order traversal
	if (*data < node->item)
	{
		// Check left node. If null create a new node, Else continue on.
		if (node->left == nullptr)
		{
			node->left = new Node();
			node->left->item = data;
			return true;
		}
		else
		{
			return rInsert(node->left, data);
		}
	}
	else
	{
		// Check right node. If null create a new node, Else continue on.
		if (node->right == nullptr)
		{
			node->right = new Node();
			node->right->item = data;
			return true;
		}
		else
		{
			return rInsert(node->right, data);
		}
	}

	return false;
}

bool BSTree::rRemove(Node *node, TreeData *data)
{
	if (node->item == data)
	{
		node->item--;
		return true;
	}
	else if (node->item < data)
	{
		return rInsert(node->left, data);
	}
	else if (node->item > data)
	{
		return rInsert(node->right, data);
	}

	// TODO: ADD ADDITIONAL PERCOLATE CODE

	// Data not found
	return false;
}

void BSTree::makeEmpty()
{
	// Needs some humor, its the only way to be sure
	NukeItFromOrbit();
}

bool BSTree::NukeItFromOrbit()
{
	return true;
}

void BSTree::print(Node *node, ostream &out) const
{
	// In order traversal
	
	// Base Case
	if (node == nullptr)
	{
		return;
	}
	// Traverse down the left hand side
	print(node->left, out);

	// Print
	out << *node->item;

	// Traverse down the right
	print(node->right, out);
}