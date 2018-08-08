/*------------------------------------------------------
파일이름: personType.cpp
-------------------------------------------------------*/

#include "personType.h"
#include <iostream>

void personType::print() const
{
	cout << firstName << " " << lastName;
}
void personType::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}

string personType::getFirstName() const
{
	return firstName;
}
string personType::getLastName() const
{
	return lastName;
}

//Constructor with parameters
personType::personType(string first, string last)
{
	firstName = first;
	lastName = last;
}

personType& personType::setLastName(string last)
{
	lastName = last;
	return *this;
}

personType& personType::setFirstName(string first)
{
	firstName = first;
	return *this;
}