
#include <iostream>
#include <string>

#include "Student.h"

Student::Student(const unsigned int &studentID, const std::string &givenName, const std::string &familyName)
	: _StudentID(studentID), _GivenName(givenName), _FamilyName(familyName)
{
}

Student::Student(const Student &src)
	: _StudentID(src._StudentID), _GivenName(src._GivenName), _FamilyName(src._FamilyName)
{
}

unsigned int Student::GetStudentID() const
{
	return _StudentID;
}

std::string Student::GetGivenName() const
{
	return _GivenName;
}

std::string Student::GetFamilyName() const
{
	return _FamilyName;
}

void Student::SetStudentID(const unsigned int &value)
{
	_StudentID = value;
}

void Student::SetGivenName(const std::string &value)
{
	_GivenName = value;
}

void Student::SetFamilyName(const std::string &value)
{
	_FamilyName = value;
}

std::ostream &operator<<(std::ostream &ostr, const Student &student)
{
	ostr << student.GetStudentID() << ": " << student.GetFamilyName() << ", " << student.GetGivenName();
	return ostr;
}

Student &Student::operator=(const Student &rhs)
{
	this->_StudentID = rhs._StudentID;
	this->_FamilyName = rhs._FamilyName;
	this->_GivenName = rhs._GivenName;
	return *this;
}

bool Student::operator<(const Student &rhs) const
{
	return this->_StudentID < rhs._StudentID;
}

bool Student::operator>(const Student &rhs) const
{
	return this->_StudentID > rhs._StudentID;
}
