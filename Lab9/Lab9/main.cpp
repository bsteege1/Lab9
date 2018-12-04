//Brandon Steege
//Lab 9
//12/3/2018

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


int main()
{
	//initializing variables
	ifstream inFile;
	ofstream outFile("output.txt");
	string fileName;
	string item;
	map<string, int> tally;

	//prompting user to enter a file name
	cout << "Please enter a file name: " << endl;
	cin >> fileName;
	inFile.open(fileName);

	//if the file name does not exist or was typed incorrectly re-prompting the user to enter a new filename
	while (!inFile)
	{
		cout << "No such file exists! Please enter a file name: " << endl;
		cin >> fileName;
		inFile.open(fileName);
	}

	//while not end of file
	while (!inFile.eof())
	{
		inFile >> item; //sets item to current string in file
		if (!inFile.fail()) //controls the read procces
		{
			++tally[item];
		}
	}

	inFile.close(); //closes file

	if (outFile.is_open())
	{
		for (std::map<string, int>::iterator it = tally.begin(); it != tally.end(); ++it)
			for (int i(0); i <= it->second; i++)
			{
				outFile << it->first << " ";
			}
	}

	else cout << "Unable to open file";

	system("pause");

	return 0;
}
