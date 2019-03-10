#include <iostream>
#include <string>
#include "Input.h"
#include "Words.h"
#include "Node.h"

int main(int argc, char * argv[])
{
	int i = 0;
	char* tempWords[100000];
	Input* input = new Input();
	input->spilt(argv);
	Words* wordList = new Words();
	wordList->saveWord(input->getPath());
	for (i = 0; i < wordList->listSize; i++)
	{
		tempWords[i] = wordList->words[i];
	}
	//wordList->hhh(tempWords);
	//node的对象数组
	Node* node = new Node[100000];
	for (i = 0; i < wordList->listSize; i++)
	{
		cout << wordList->listSize << endl;
		cout << wordList->words[i] << endl;
		node[i].formNode(wordList->words[i]);
	}
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