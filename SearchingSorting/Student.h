
#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>

class Student
{
private:
	unsigned int _StudentID;
	std::string _GivenName;
	std::string _FamilyName;
public:
	Student(const unsigned int &studentID, const std::string &givenName, const std::string &familyName);
	Student(const Student &src);
	unsigned int GetStudentID() const;
	std::string GetGivenName() const;
	std::string GetFamilyName() const;
	void SetStudentID(const unsigned int &value);
	void SetGivenName(const std::string &value);
	void SetFamilyName(const std::string &value);
	Student &operator=(const Student &rhs);
	bool operator<(const Student &rhs) const;
	bool operator>(const Student &rhs) const;
};

std::ostream &operator<<(std::ostream &ostr, const Student &student);

#endif _STUDENT_H
