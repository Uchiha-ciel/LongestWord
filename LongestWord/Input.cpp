#include "Input.h"

using namespace std;

Input::Input()
{
	is_w = false;
	is_c = false;
	headChar = ' ';
	tailChar = ' ';
	is_r = false;
}

void Input::spilt(int npara,vector<string> para)
{
	/*
	char cmdInput[1000];
	cin.getline(cmdInput, 1000);
	string in = string(cmdInput);
	*/

	//cout << in << endl;
	int i;
	for ( i = 0; i < npara - 1; i++)
	{
		if (para[i] == "-w")
		{
			is_w = true;
		}
		if (para[i] == "-c")
		{
			is_c = true;
		}
		if (para[i] == "-h")
		{
			headChar = para[++i][0];
		}
		if (para[i] == "-t")
		{
			tailChar = para[++i][0];
		}
		if (para[i] == "-r")
		{
			is_r = true;
		}
		else 
		{
			printf("para error");
			exit(1);
		}
	}/*
			i++;
			if (in.at(i) == 'w')
			{
				is_w = true;
			}
			else if (in.at(i) == 'c')
			{
				is_c = true;
			}
			else if (in.at(i) == 'h')
			{
				i += 2;
				headChar = in.at(i);
			}
			else if (in.at(i) == 't')
			{
				i += 2;
				tailChar = in.at(i);
			}
			else if (in.at(i) == 'r')
			{
				is_r = true;
			}
			else
			{

			}
		}
		else if(in.at(i) != ' ')
		{
			break;
		}
		i++;
	*/
	filePath = para[i];
}

string Input::getPath()
{
	return filePath;
}

bool Input::getWpara()
{
	return is_w;
}

bool Input::getCpara()
{
	return is_c;
}

bool Input::getRpara()
{
	return is_r;
}

char Input::getHeadChar()
{
	return headChar;
}

char Input::getTailChar()
{
	return tailChar;
}