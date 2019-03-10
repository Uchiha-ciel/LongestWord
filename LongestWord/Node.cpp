#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

using namespace std;

void Node::formNode(char inputWord[])
{
	strcpy(word,inputWord);
	head = inputWord[0];
	tail = inputWord[strlen(inputWord - 1)];
	wordLength = strlen(inputWord);
	//cout << inputWord << endl;
	//cout << head << endl;
	//cout << tail << endl;
	//cout << wordLength << endl;
}