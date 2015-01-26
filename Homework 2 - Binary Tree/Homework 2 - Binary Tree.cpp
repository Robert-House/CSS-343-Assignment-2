// Homework 2 - Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BSTree.h"


int _tmain(int argc, _TCHAR* argv[])
{
	BSTree *temp = new BSTree("test.txt");
	std::cout << *temp;
	return 0;
}

