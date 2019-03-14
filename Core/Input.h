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
	void spilt(int npara, vector<string> para);
	string getPath() { return filePath; }
	bool getWpara() { return is_w; }
	bool getCpara() { return is_c; }
	char getHeadChar() { return headChar; }
	char getTailChar() { return tailChar; }
	bool getRpara() { return is_r; }
};