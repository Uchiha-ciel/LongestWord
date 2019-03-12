#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Input
{
private:
	bool is_w;
	bool is_c;
	char headChar;
	char tailChar;
	bool is_r;
	string filePath;
public:
	Input();
	void spilt(int npara,vector<string> para);
	string getPath();
	bool getWpara();
	bool getCpara();
	char getHeadChar();
	char getTailChar();
	bool getRpara();
};