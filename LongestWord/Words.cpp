#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdlib.h>  
#include "Words.h"

using namespace std;

Words::Words()
{
	listSize = 0;
	words[20000][100] = { 0 };
}

void Words::saveWord(string filePath)
{
	char buffer[256];
	ifstream in(filePath);
	if (!in.is_open())
	{
		cout << "Error opening file"; 
		exit(1);
	}
	while (!in.eof())
	{
		in.getline(buffer, 120);
		string line = string(buffer);
		int i = 0;
		int j = 0;
		while (i < int(line.size()))
		{
			while (!isalpha(line.at(i)) && j == 0)
				i++;
			if (!isalpha(line.at(i)))
			{
				words[listSize][j] = '\0';
				//cout << words[listSize] << endl;
				listSize++;
				i++;
				j = 0;
				continue;
			}
			words[listSize][j] = line.at(i);
			if (i == int(line.size() - 1) && isalpha(line.at(i)))
			{
				words[listSize][j + 1] = '\0';
				//cout << words[listSize] << endl;
				listSize++;
				break;
			}
			i++;
			j++;
		}
	}
}