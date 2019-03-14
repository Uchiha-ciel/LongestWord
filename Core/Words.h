#pragma once
#include <iostream>
#include <string>

using namespace std;

class Words
{
public:
	char words[20000][100];
	int listSize;
	Words();
	void saveWord(string filePath);
};