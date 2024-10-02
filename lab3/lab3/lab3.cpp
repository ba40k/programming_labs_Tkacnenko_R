#include <iostream>
void print(int** matrix, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
void erase_matrix_row(int** &matrix,int &n, int m, int row)
{
	int** new_matrix = new int*[n-1];
	bool erasing_row_passed = 0;
	for (int i = 0; i < n ; ++i)
	{
		
		if (i != row)
		{
			//new_matrix[i - erasing_row_passed] = new int[m];
			new_matrix[i-erasing_row_passed] = matrix[i];
		}
		else
		{
			erasing_row_passed = 1;
		}
	}
	
	delete[] matrix[row];
	matrix = new_matrix;
	new_matrix = nullptr;
	
	n--;
}
void erase_matrix_column(int** &matrix, int n, int &m, int column)
{
	int** new_matrix = new int* [n];
	bool erasing_column_passed = 0;
	for (int i = 0; i < n; ++i)
	{		
		bool erasing_column_passed = 0;
		new_matrix[i] = new int [m - 1];
		for (int j = 0; j < m; ++j)
		{
			if (j == column)
			{
				erasing_column_passed = 1;
				continue;
			}
			new_matrix[i][j - erasing_column_passed] = matrix[i][j];
		}
		delete[] matrix[i];
	}
	
	delete[] matrix;
	matrix = new_matrix;
	m--;
}
void subtask1(int**& dynamic_matrix, int &n, int &m)
{
	for (int i = 0; i < n; ++i)
	{
		bool only_nulls = 1;
		for (int j = 0; j < m; ++j)
		{
			only_nulls = (dynamic_matrix[i][j] == 0);
			if (!only_nulls)
			{
				break;
			}
		}
		if (only_nulls)
		{
			erase_matrix_row(dynamic_matrix, n, m, i);
			i--;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		bool only_nulls = 1;
		for (int j = 0; j < n; ++j)
		{
			only_nulls = (dynamic_matrix[j][i] == 0);
			if (!only_nulls)
			{
				break;
			}
		}
		if (only_nulls)
		{
			erase_matrix_column(dynamic_matrix, n, m, i);
			i--;
		}
	}
}
int subtask2(int**& dynamic_matrix, int& n, int& m)
{
	int res = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (dynamic_matrix[i][j] == 0)
			{
				return i;
			}
		}
	}
	return res;
}
int main()
{
	int n, m;
	std::cout << "Enter number of rows of your square matrix \n";
	std::cin >> n;
	m = n;
	int** dynamic_matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		dynamic_matrix[i] = new int[m];
	}
	std::cout << "Enter the matrix elements which places below and on main diagonal \n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			std::cin >> dynamic_matrix[i][j];
			dynamic_matrix[j][i] = dynamic_matrix[i][j];
		}
	}
	std::cout << '\n';
	std::cout << "This is your matrix : \n";
	print(dynamic_matrix,n,m);
	
	subtask1(dynamic_matrix, n, m);
	
	std::cout << "All rows and columns which contains only nulls was deleted\n";

	print(dynamic_matrix, n, m);
	if (subtask2(dynamic_matrix, n, m) == -1)
	{
		std::cout << "There is no rows which contains null : (\n";
	}
	else
	{
		std::cout << "Number of first row which contains null is " << subtask2(dynamic_matrix, n, m);
	}
}