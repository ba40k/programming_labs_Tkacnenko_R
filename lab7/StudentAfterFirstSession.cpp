#include "StudentAfterFirstSession.h"

StudentAfterFirstSession::StudentAfterFirstSession(const char* _name, const int _course,
	const int _group, const int _creditId, const int* const _marks) : Student(_name, _course, _group, _creditId)
{
	firstSessionMarks = new int[4];
	for (int i = 0; i < 4; i++)
	{
		firstSessionMarks[i] = _marks[i];
	}
}

StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& other) : Student(other)
{
	for (int i = 0; i < 4; i++)
	{
		this->firstSessionMarks[i] = other.firstSessionMarks[i];
	}
}
StudentAfterFirstSession::~StudentAfterFirstSession()
{
	delete[] firstSessionMarks;
	firstSessionMarks = nullptr;
}

const int* const StudentAfterFirstSession::getFirstSessionMarks() const
{
	return firstSessionMarks;
}
void StudentAfterFirstSession::setFirstSessionMarks(const int* const newMarks)
{
	for (int i = 0; i < 4; i++)
	{
		firstSessionMarks[i] = newMarks[i];
	}
}

void StudentAfterFirstSession::setFirstSessionMark(int number, int val)
{
	if (number < 4)
	{
		firstSessionMarks[number] = val;
		return;
	}
	throw "array out of range";
}

int StudentAfterFirstSession::getFirstSessionMark(int number) const
{
	if (number < 4)
	{
		return firstSessionMarks[number];
	}
	throw "array out of range";
}
std::ostream& operator<< (std::ostream& out, StudentAfterFirstSession& st)
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
	out << "==================\n";
	return out;
}
double StudentAfterFirstSession::calculateAverage()
{
	double sum = 0;
	double total = 4;
	for (int i = 0; i < 4; i++)
	{
		sum += firstSessionMarks[i];
	}
	return sum / total;
}