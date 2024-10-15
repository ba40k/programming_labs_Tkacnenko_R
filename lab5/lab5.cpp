#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	
	bool isReadFromFile = 0;
	bool isWriteInFile = 0;

	cout << "Do you want input from file? : \nY/N \n";

	char answer;
	cin >> answer;

	isReadFromFile = (answer == 'Y');

	cout << "Do you want output from file? : \nY/N \n";

	
	cin >> answer;
	isWriteInFile = (answer == 'Y');
	string input_file_name;
	string output_file_name;
	
	if (isReadFromFile)
	{
		cout << "Enter input file name : \n";
		cin >> input_file_name;
	}

	if (isWriteInFile)
	{
		cout << "Enter output file name : \n";
		cin >> output_file_name;
	}
	
	ifstream inStream(input_file_name);
	ofstream outStream(output_file_name);
	
	
	vector<string> strings;
	if (!isReadFromFile)
	{
		cout << "Enter strings, separate strings by spaces : \n";
	}
	
	if (!isReadFromFile)
	{
		
		string last ;
		string cur;
		string eat_trash;
		getline(cin, eat_trash);
		getline(cin, cur);
		cur.push_back(' ');
		for (int i = 0; i < cur.size(); i++)
		{
			if (cur[i] == ' ')
			{
				if (strings.size() == 0 || strings.back() != last)
				{
					strings.emplace_back(last);
					
				}
				last.clear();
				continue;
			}
			last.push_back(cur[i]);
		}

	}
	else
	{
		bool show_file = 0;
		cout << "Show input file? :\n";
		cout << "Y/N\n";
		char ans;
		cin >> ans;
		string cur, last;
		if (ans == 'Y')
		{
			cout << "\n=========\n";
		}
		while (getline(inStream,cur))
		{
			if (ans == 'Y')
			{
					cout << cur << '\n';
			}
			cur.push_back(' ');
			for (int i = 0; i < cur.size(); i++)
			{
				if (cur[i] == ' ')
				{


					if (strings.size() == 0 || strings.back() != last)
					{
						strings.emplace_back(last);

					}
					last.clear();
					continue;
				}
				last.push_back(cur[i]);
			}		
		}
		if (ans == 'Y')
		{
			cout << "\n=========\n";
		}
	}
	
	
	if (!isWriteInFile)
	{
		cout << "Your string without several same in a row: \n";
		for (auto& s : strings)
		{
			cout << s << '\n';
		}
	}
	else
	{
		cout << "Show output file? : \n";
		cout << "Y/N\n";
		char ans;
		cin >> ans;

		if (ans=='Y')
		{
			cout << "\n=========\n";
			string trash;
			ifstream temp(output_file_name);
			while (getline(temp, trash))
			{
				if (isWriteInFile)
				{
					cout << trash << '\n';
				}
			}
			cout << "\n=========\n";
			temp.close();
		}
		outStream << "Your string without several same in a row: \n";
		for (auto& s : strings)
		{
			outStream << s << '\n';
		}
	}
	inStream.close();
	outStream.close();

}