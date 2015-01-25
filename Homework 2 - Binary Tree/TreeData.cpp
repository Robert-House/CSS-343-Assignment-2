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

unsigned int TreeData::getOccurance() const
{
	return _occurance;
}

bool TreeData::operator==(const TreeData *other)
{
	// Check if the contained chars are equal.
	if (_char == other->_char)
	{
		// Go one step further and check if the occurances
		// match.
		if (_occurance == other->_occurance)
		{
			return true;
		}
	}

	return false;
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