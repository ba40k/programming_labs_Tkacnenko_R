#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>
int Student::studentCounter = 0;
Student::Student(const char* _name, const int _course,
	const int _group, const int _creditId)
	: creditId(_creditId),course(_course),group(_group)
{
	name = new char[100];
	strcpy(name, _name);
	studentCounter++;
	id = studentCounter;
};

Student::Student(const Student& other)
	:creditId(other.creditId)
{
	strcpy(this->name, other.name);
	this->course = other.course;
	this->group = other.group;
	this->id = other.id;
}
Student::~Student()
{
	delete[] name;
	name = nullptr;
}
const char* const Student::getName() const 
{
	return name;
}
const int Student::getCourse() const
{
	return course;
}
const int Student::getGroup() const
{
	return group;
}
const int Student::getCreditId() const
{
	return creditId;
}
const int Student::getId() const
{
	return id;
}
void Student::setName(const char* _name)
{
	strcpy(name, _name);
}
void Student::setCourse(const int _course)
{
	course = _course;
}
void Student::setGroup(const int _group)
{
	group = _group;
}

std::ostream& operator<< (std::ostream& out, Student& st)
{
	out << "==================\n";
	out << "Name = " << st.getName() << '\n';
	out << "Id = " << st.getId() << '\n';
	out << "Course = " << st.getCourse() << '\n';
	out << "Credit ID = " << st.getCreditId() << '\n';
	out << "==================\n";
	return out;
}
double Student::calculateAverage()
{
	return -1;
}