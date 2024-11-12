#include <iostream>
#include <string>
#include "Student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"
const int MAX_SIZE = 100;
int main()
{
	int n;
	std::cin >> n;

	Student* arr[MAX_SIZE];

	for (int i = 0; i < n; i++)
	{
		char* name = new char[100] ;
		std::cin >> name;
		int group, course, creditId;
		std::cin  >> group >> course >> creditId;

		int type = 0; // 0 - student, 1 - student after  1, 2 - student after 2
		std::cin >> type;

		if (type == 0)
		{
			arr[i] = new Student(name, course, group, creditId);
			delete[] name;
			continue;
		}

		int marks1[4];
		for (int i = 0; i < 4; i++)
		{
			std::cin >> marks1[i];
		}
		if (type == 1)
		{
			arr[i] = new StudentAfterFirstSession(name, course, group, creditId, marks1);
			delete[] name;
			continue;
		}

		int marks2[5];
		for (int i = 0; i < 5; i++)
		{
			std::cin >> marks2[i];
		}
		
		arr[i] = new StudentAfterSecondSession(name, course, group, creditId, marks1, marks2);
		delete[] name;
		continue;
		

	}

	int group;
	std::cin >> group;
	int marks1[4] = { 1,1,1,1 };
	int marks2[5] = {2,2,2,2,2};
	StudentAfterFirstSession* arr2[5];
	arr2[0] = new StudentAfterSecondSession("Kirill", 1, 1, 1, marks1, marks2);
	arr2[1] = new StudentAfterSecondSession("Egor", 1, 1, 13, marks1, marks2);
	arr2[2] = new StudentAfterSecondSession("Vasya", 1, 3, 777, marks1, marks2);
	arr2[3] = new StudentAfterSecondSession("Gena", 1, 4, 100, marks1, marks2);
	arr2[4] = new StudentAfterSecondSession("Vova", 1, 2, 10, marks1, marks2);
	double av1 = 0, av2 = 0;
	double total1=0;
	for (int i = 0; i < 5; i++)
	{
		if (arr2[i]->getGroup() != group)
		{
			continue;
		}
		total1++;
		if (i < 4)
		{

			av1 += arr2[i]->calculateAverage();
		}
		av2 += ((StudentAfterSecondSession*)arr2[i])->calculateAverage();
	}
	std::cout << av1 / total1 << ' ' << av2 / total1 << '\n';

	double average = 0;
	double total = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i]->calculateAverage() == -1)
		{
			continue;
		}
		average += arr[i]->calculateAverage();
		total++;
	}
	if (total == 0)
	{
		return 0;
	}
	std::cout << average / total;


}