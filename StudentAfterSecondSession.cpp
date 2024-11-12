#include "StudentAfterSecondSession.h"
StudentAfterSecondSession::StudentAfterSecondSession(const char* _name, const int _course,
	const int _group, const int _creditId, const int* const _marks1, const int* const _marks2)
	: StudentAfterFirstSession(_name,_course,_group,_creditId,_marks1)
{
	secondSessionMarks = new int[5];
	for (int i = 0; i < 5; i++)
	{
		secondSessionMarks[i] = _marks2[i];
	}
}
StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession& other) : StudentAfterFirstSession(other)
{
	for (int i = 0; i < 5; i++)
	{
		this->secondSessionMarks[i] = other.secondSessionMarks[i];
	}
}
StudentAfterSecondSession::~StudentAfterSecondSession()
{
	delete[] secondSessionMarks;
	secondSessionMarks = nullptr;
}
const int* const StudentAfterSecondSession::getSecondSessionMarks() const
{
	return secondSessionMarks;
}
void StudentAfterSecondSession::setSecondSessionMarks(const int* const newMarks)
{
	for (int i = 0; i < 5; i++)
	{
		secondSessionMarks[i] = newMarks[i];
	}
}
void StudentAfterSecondSession::setSecondSessionMark(int number, int val)
{
	if (number < 5)
	{
		secondSessionMarks[number] = val;
		return;
	}
	throw "array out of range";
}

int StudentAfterSecondSession::getSecondSessionMark(int number) const
{
	if (number < 5)
	{
		return secondSessionMarks[number];
	}
	throw "array out of range";
}
std::ostream& operator<< (std::ostream& out, StudentAfterSecondSession& st)
{
	out << "==================\n";
	out << "Name = " << st.getName() << '\n';
	out << "Id = " << st.getId() << '\n';
	out << "Course = " << st.getCourse() << '\n';
	out << "Credit ID = " << st.getCreditId() << '\n';
	out << "First Session Marks = ";
	for (int i = 0; i < 4; i++)
	{
		out << st.getFirstSessionMark(i) << ' ';
	}
	out << '\n';
	out << "Second Session Marks = ";
	for (int i = 0; i < 5; i++)
	{
		out << st.getSecondSessionMark(i) << ' ';
	}
	out << "==================\n";
	return out;
}
double StudentAfterSecondSession::calculateAverage()
{
	double sum = 0;
	double total = 9;
	for (int i = 0; i < 9; i++)
	{
		if (i < 4)
		{
			sum += getFirstSessionMark(i);
			continue;
		}
		sum += getSecondSessionMark(i - 4);
	}
	return sum / total;
}