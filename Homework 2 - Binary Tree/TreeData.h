#pragma once
#include <iostream>

using namespace std;

class TreeData
{
public:
	TreeData(char c);
	TreeData(char c, int count);
	~TreeData();

	// Accessors
	char getChar() const;
	int getOccurance() const;

	bool operator==(const TreeData *other) const;
	bool operator!=(const TreeData *other);
	bool operator<(const TreeData *other);
	bool operator>(const TreeData *other);
	friend ostream& operator<<(ostream &out, const TreeData &data);
	TreeData& operator++();
	TreeData& operator--();
	void addOne();

private:
	char _char = ' ';
	int _occurance = 0;
};