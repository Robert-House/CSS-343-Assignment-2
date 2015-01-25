#pragma once

class TreeData
{
public:
	TreeData(char c);
	~TreeData();

	// Accessors
	char getChar() const;
	unsigned int getOccurance() const;

	bool operator==(const TreeData *other);
	bool operator!=(const TreeData *other);
	bool operator<(const TreeData *other);
	bool operator>(const TreeData *other);

private:
	char _char = ' ';
	unsigned int _occurance = 0;
};