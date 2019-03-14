#include "Input.h"
#include <string>

using namespace std;

Input::Input()
{
	is_w = false;
	is_c = false;
	headChar = '\0';
	tailChar = '\0';
	cout << headChar << endl;
	is_r = false;
}

void Input::spilt(int npara,vector<string> para)
{
	int i;
	int flag = 0;
	for (i = 1; i < npara - 1; i++)
	{
		if (para[i] == "LongestWord.exe");
		else if (para[i] == "-w")
		{
			if(flag == 0)
				is_w = true;
			else
			{
				cout << "para error" << endl;
				exit(1);
			}
			flag = 1;
		}
		else if (para[i] == "-c")
		{
			if (flag == 0)
				is_c = true;
			else
			{
				cout << "para error" << endl;
				exit(1);
			}
			flag = 1;
		}
		else if (para[i] == "-h")
		{
			headChar = para[++i][0];
		}
		else if (para[i] == "-t")
		{
			tailChar = para[++i][0];
		}
		else if (para[i] == "-r")
		{
			is_r = true;
		}
		else 
		{
			cout << "para error" << endl;
			exit(1);
		}
	}
	filePath = para[i];
}
