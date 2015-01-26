#include "TreeData.h"

TreeData::TreeData(char c)
{
	// Set char for this object on creation.
	_char = c;

	// This occurs at least once.
	_occurance = 1;
}

TreeData::~TreeData()
{

}

char TreeData::getChar() const
{
	return _char;
}

int TreeData::getOccurance() const
{
	return _occurance;
}

bool TreeData::operator==(const TreeData *other) const
{
	return (_char == other->_char);
}

bool TreeData::operator!=(const TreeData *other)
{
	// Return the opposite of the == operator.
	return !operator==(other);
}

bool TreeData::operator<(const TreeData *other)
{
	// Check for inequality using the ASCII value.
	if (_char < other->_char)
	{
		return true;
	}

	return false;
}

bool TreeData::operator>(const TreeData *other)
{
	// Just use the < operator.
	return operator<(other);
}

ostream& operator<<(ostream &out, const TreeData &data)
{
	out << "'" << data._char << ' ' << data._occurance << endl;

	return out;
}

TreeData& TreeData::operator++()
{
	_occurance++;
	return *this;
}

TreeData& TreeData::operator--()
{
	_occurance--;
	return *this;
}

void TreeData::addOne()
{
	_occurance++;
}