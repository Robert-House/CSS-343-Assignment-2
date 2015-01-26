// Homework 2 - Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BSTree.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	BSTree *temp = new BSTree("test.txt");
	//cout << *temp;
	TreeData *data = new TreeData(' ');
	cout << temp->depth(*data);
	temp->makeEmpty();
	return 0;
}

