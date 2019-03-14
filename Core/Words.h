#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Words
{
public:
	char words[20000][100];
	int listSize;
	Words();
	void saveWord(string filePath);
};