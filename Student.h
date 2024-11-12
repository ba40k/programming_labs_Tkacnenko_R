#pragma once
#include <iostream>
class Student
{
private:
	char* name;
	int course;
	int group;
	const int creditId;
	static int studentCounter;
	int id;
public:
	Student() = delete;
	Student(const char* _name, const int _course,
		const int _group, const int _creditId);
	Student(const Student& other);
	~Student();

	const char* const getName() const;
	const int getCourse() const;
	const int getGroup() const;
	const int getCreditId() const;
	const int getId() const;

	void setName(const char* _name) ;
	void setCourse(const int _course) ;
	void setGroup(const int _group) ;

	virtual double calculateAverage();
	
};
std::ostream& operator<< (std::ostream& out, Student& st);