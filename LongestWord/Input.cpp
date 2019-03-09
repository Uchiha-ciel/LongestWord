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

void Input::spilt()
{
	char cmdInput[1000];
	cin.getline(cmdInput, 1000);
	string in = string(cmdInput);

	//cout << in << endl;
	int i = 0;
	while (i < in.size())
	{
		if (in.at(i) == '-')
		{
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
	}
	filePath = in.substr(i, in.size());
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