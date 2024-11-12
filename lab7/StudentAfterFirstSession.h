#pragma once
#include "Student.h"

class StudentAfterFirstSession : public Student
{
private:
	int* firstSessionMarks;
public:
	StudentAfterFirstSession(const char* _name, const int _course,
		const int _group, const int _creditId, const int* const _marks);
	StudentAfterFirstSession(const StudentAfterFirstSession& other);
	~StudentAfterFirstSession();

	const int* const getFirstSessionMarks() const;
	int getFirstSessionMark(int number) const;
	void setFirstSessionMarks(const int* const newMarks);
	void setFirstSessionMark(int number, int val);

    double calculateAverage() override;
};
std::ostream& operator<< (std::ostream& out, StudentAfterFirstSession& st);