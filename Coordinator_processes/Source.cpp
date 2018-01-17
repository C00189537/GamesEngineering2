#include <iostream>
#include <vector>
#include <stdio.h>	
#include <tchar.h>
#include <windows.h>
#include <string>
#include "Worker\Source.cpp"
#include <sstream>
#include <iterator>
#include <cctype>
#include <algorithm>
#include <cstring>


void coordinator();
std::vector<double> worker(double row[3], double matrix[3][3]);


//int main()
//{
//	coordinator();
//	system("pause");
//}
std::string Transformer(double d)
{
	std::ostringstream doubleStr;
	doubleStr << d;
	return doubleStr.str();
}

void coordinator()
{
	STARTUPINFO startInfo;
	PROCESS_INFORMATION processInfo;


	ZeroMemory(&startInfo, sizeof(startInfo));
	startInfo.cb = sizeof(startInfo);
	ZeroMemory(&processInfo, sizeof(processInfo));


	double a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double b[3][3] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	double c[3][3];

	for (int i = 0; i < 3; i++)
	{
		std::vector<double> temp;
		temp = worker(a[i], b);

		std::vector<std::string> tempAsString;
		std::transform(temp.begin(), temp.end(), std::back_inserter(tempAsString), Transformer);
		std::copy(tempAsString.begin(), tempAsString.end(), std::ostream_iterator<std::string>(std::cout, " "));

		std::vector<char *> lsStrings;
		for (int i = 0; i < tempAsString.size(); i++)
		{
			char * cstr = new char[tempAsString.at(i).length() + 1];
			std::strcpy(cstr, tempAsString.at(i).c_str());
			lsStrings.push_back(cstr);
		}
		CreateProcess("../Worker/Debug/Worker.exe", lsStrings.at(1), NULL, NULL, false, 0, NULL, NULL, &startInfo, &processInfo);

		for (int j = 0; j < 3; j++)
		{
			c[i][j] = temp.at(j);

			std::cout << c[i][j] << " ";
		}
		std::cout << std::endl;
		temp.clear();
	}
}

