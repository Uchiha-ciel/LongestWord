#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Input.h"
#include "Words.h"

int main()
{
	Input* input = new Input();
	input->spilt();
	Words* wordList = new Words();
	wordList->saveWord(input->getPath());
	/*
	cout << "w" << input->getWpara() << endl;
	cout << "r" << input->getRpara() << endl;
	cout << "c" << input->getCpara() << endl;
	cout << "h" << input->getHeadChar() << endl;
	cout << "t" << input->getTailChar()<< endl;
	cout << input->getPath() << endl;
	*/
	getchar();
}