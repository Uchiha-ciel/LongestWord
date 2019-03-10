#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Words
{
public:
	char words[100000][100];
	int listSize;
	Words();
	void saveWord(string filePath);
	//void hhh(char* words[]);
};