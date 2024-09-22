#include <iostream>
#include <ctime>
const int ARRAY_SIZE = 1e3 + 1;
double array[ARRAY_SIZE];
double min(double a, double b)
{
	return a < b ? a : b;
}
double random_double()
{
	double x = rand() * rand();
	x /= rand();
	x *= pow(-1, rand()%2);
	return x;
}
void print_array(int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i]<<' ';
	}
}
bool is_local_min(int i, int size)
{
	if (i == 0)
	{
		return array[i] < array[i+1];
	}
	if (i == size - 1)
	{
		return array[size - 1] < array[size - 2];
	}
	return array[i] < array[i + 1] && array[i] < array[i - 1];
}
void swap(int i, int j)
{
	double temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void sort(int start, int end)
{
	int sz = end - start + 1;
	if (sz <2)
	{
		return;
	}
	if (sz == 2)
	{
		if (abs(array[end]) < abs(array[start]))
		{
			swap(end, start);
		}
		return;
	}
	if (sz == 3)
	{
		
			for (int i = start; i <= end; ++i)
			{
				for (int j = i; j + 1 <= end; ++j)
				{
					if (abs(array[j]) > abs(array[j + 1]))
					{
						swap(i, i + 1);
					}
				}
			}
		
	}
	bool sorted = 1;
	int comparand = start;
	double val = abs(array[end]);
	for (start; start < end; start++)
	{
		if (abs(array[start]) <= val)
		{
			swap(start, comparand);
			comparand++;
			sorted = 0;
		}
	}
	swap(comparand,end);
	if (sorted)
	{
		return;
	}
	sort(0, comparand-1);
	sort(comparand + 1, end);
}
int main()
{
	std::cout << "Enter array size\n";
	int size; 
	std::cin >> size;
	
	std::cout << "Do you want to fill array randomly?\n";
	std::cout << "Y/N?\n";
	char user_ans;
	std::cin >> user_ans;
	srand(time(0));
	for (int i = 0; i < size; ++i)
	{
		if (user_ans == 'Y')
		{
			array[i] = random_double();
		}
		else
		{
			std::cin >> array[i];
		}
	}
	std::cout << "array is : ";
	print_array(size);
	std::cout << '\n';


	if (size == 1)
	{
		std::cout << "Can't find any local minimum\n";
	}
	else
	{
		std::cout << "local mins : ";
		for (int i = 0; i < size; ++i)
		{
			if (is_local_min(i, size))
			{
				std::cout << i << ' ';
			}
		}
		std::cout << '\n';
	}

	long long minimal = 1e18;

	for (int i = 0;i < size; ++i)
	{
		minimal = min(minimal, array[i]);
	}

	bool is_was_minimum = 0;
	long long sum = 0;
	for (int i = 0; i < size; ++i)
	{
		if (is_was_minimum)
		{
			sum += array[i];
		}
		if (array[i] == minimal)
		{
			is_was_minimum = 1;
		}
	}
	std::cout << "sum after first minimum is " << sum << '\n';

	sort(0, size - 1);

	std::cout << "sorted by a modulo: \n";

	print_array(size);




}