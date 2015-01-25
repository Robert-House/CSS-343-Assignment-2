#pragma once

#include "BSTree.h"

BSTree::BSTree()
{

}

BSTree::BSTree(string filePath)
{
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

}

bool BSTree::operator!=(const BSTree &rightSide)
{

}

// Accessors
const TreeData* BSTree::retrieve(const TreeData &data) const
{
	// If head is null, return nullptr
	if (_head == nullptr)
	{
		return nullptr;
	}

	
}

int BSTree::depth(const TreeData &data) const
{

}

int BSTree::descendants(const TreeData &desc) const
{

}

bool BSTree::isEmpty() const
{
	// case: empty
	if (_head == nullptr)
	{
		return true;
	}

	return false;
}

bool BSTree::insert(TreeData *data)
{
	if (_head == nullptr)
	{
		// Create first node and assign the data
		// to the node
		Node *temp = new Node();
		temp->item = data;

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


//
//
//Priavte Members
bool BSTree::LoadFromFile(string filePath)
{
	
}

bool BSTree::rInsert(Node *node, TreeData *data)
{
	if (node->item == data)
	{
		node->item++;
		return false;
	}
	else if (node == nullptr)
	{
		// create new node and insert
		Node *newNode = new Node();
		newNode->item = data;
		return true;
	}
	else if (node->item < data)
	{
		return rInsert(node->left, data);
	}
	else
	{
		return rInsert(node->right, data);
	}
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