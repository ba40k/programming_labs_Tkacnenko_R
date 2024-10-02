#include <iostream>
#include <cstdio>
using namespace std;
char* my_strpbrk(char* string, const char* strCharSet)
{
	int have_char[256];
	for (int i = 0; i < 256; i++)
	{
		have_char[i] = 0;
	}
	for (int i = 0; strCharSet[i] != '\0'; i++)
	{
		have_char[(int)strCharSet[i]]++;
	}
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (have_char[(int)string[i]])
		{
			char* res = &string[i];
			return res;
		}
	}
	return NULL;
}
void find_substring_with_mno(char* s, int size, int mno) // mno - max number of ones
{
	pair<int, int> prev_interval = { -1,-1 };
	pair<int, int> cur_interval = { -1,-1 };

	int start = 0;
	int end = 0;
	int cur = 0;
	for (int i = 0; i <= size; i++)
	{
		cur += (s[i] == '1');
		if (s[i] == ' ' || s[i] == '\0')
		{
			end = i - 1;
			
			if (cur == mno)
			{
				prev_interval = cur_interval;
				cur_interval = { start,end };
			}
			start = i + 1;
			cur = 0;
		}
	}
	if (prev_interval.first == -1)
	{
		for (int i = cur_interval.first; i <= cur_interval.second; i++)
		{
			printf("%c", s[i]);
		}
	}
	else
	{
		for (int i = prev_interval.first; i <= prev_interval.second; i++)
		{
			printf("%c", s[i]);
		}
	}
	printf("\n");


}
int main()
{
	// A task, example of my_strpbrk work
	//freopen("input.txt", "r",stdin);
	char* some_chars = new char[256];
	some_chars[255] = '\0';
	for (int i = 1; i < 256; i++)
	{
		some_chars[i - 1] = char(i);
	}
	char* english_alphabet = new char[27];
	english_alphabet[26] = '\0';
	for (int i = 0; i < 26; i++)
	{
		english_alphabet[i] = (char)('a' + i);
	}
	auto pointer = my_strpbrk(some_chars, english_alphabet);
	printf("%c", *pointer);
	printf("\n");
	// B task

	int size;
	printf("Enter size of string: \n");
	scanf_s("%d", &size);
	char* s = new char[301];
	s[size] = '\0';
	printf("Enter the string: \n");
	char eat_trash = getchar();
	for (int i = 0; i < size; i++)
	{
		s[i] = getchar();
	}

	int max_number_of_ones = 0;
	int cur = 0;
	for (int i = 0; i < size; i++)
	{
		cur += (s[i] == '1');
		if (s[i] == '\0' || s[i] == ' ')
		{
			max_number_of_ones = max(max_number_of_ones, cur);
			cur = 0;
		}
	}
	
	find_substring_with_mno(s, size, max_number_of_ones);
	delete[] s;
	delete[] some_chars;
	delete[] english_alphabet;


}