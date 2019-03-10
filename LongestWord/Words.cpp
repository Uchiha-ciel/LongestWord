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
	//words[100000] = { 0 };
}

void Words::saveWord(string filePath)
{
	char buffer[256];
	char word[100];
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
		//int k;
		while (i < line.size())
		{
			while (!isalpha(line.at(i)) && j == 0)
			
	i++;
			if (!isalpha(line.at(i)))
			{
				//word[j] = '\0';
				words[listSize][j] = '\0';
				//if (word[0] != '\0')
				//{
				//	strcpy(words[listSize],word);
				//	for (k = 0; k < j; k++)
				//		words[listSize][k] = word[k];
				//	words[listSize][k] = '\0';
					cout << words[listSize] << endl;
					listSize++;
				//}
				i++;
				//memset(word, '\0', sizeof(word));
				j = 0;
				continue;
			}
			//word[j] = line.at(i);
			words[listSize][j] = line.at(i);
			if (i == line.size() - 1 && isalpha(line.at(i)))
			{
				//word[j+1] = '\0';
				words[listSize][j + 1] = '\0';
				//if (word[0] != '\0')
				//{
				//	words[listSize] = word;
					cout << words[listSize] << endl;
					listSize++;
				//}
				//memset(word, '\0', sizeof(word));
				j = 0;
				break;
			}
			i++;
			j++;
		}
	}
}

/*
void Words::hhh(char* words[])
{
	for (int i = 0; i < listSize; i++)
	{
		cout << words[i] << endl;
	}
}
*/