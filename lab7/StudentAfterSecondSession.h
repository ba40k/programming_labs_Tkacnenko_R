#pragma once
#include "StudentAfterFirstSession.h"

class StudentAfterSecondSession : public StudentAfterFirstSession
{
private:
	int* secondSessionMarks;
public:
	StudentAfterSecondSession(const char* _name, const int _course,
		const int _group, const int _creditId, const int* const marks1, const  int* const marks2);
	StudentAfterSecondSession(const StudentAfterSecondSession& other);
	~StudentAfterSecondSession();

	const int* const getSecondSessionMarks() const;
	int getSecondSessionMark(int number) const;
	void setSecondSessionMarks(const int* const newMarks);
	void setSecondSessionMark(int number, int val);

	double calculateAverage() override;
};
std::ostream& operator<< (std::ostream& out, StudentAfterSecondSession& st);