#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node::Node(char inputWord[])
{
	strcpy(word,inputWord);
	headChar = (inputWord[0] >= 'a' && inputWord[0] <= 'z') ? inputWord[0] : inputWord[0] - 'A' + 'a';
	tailChar = (inputWord[strlen(inputWord) - 1] >= 'a' && inputWord[strlen(inputWord) - 1] <= 'z') ? inputWord[strlen(inputWord) - 1] : inputWord[strlen(inputWord) - 1] - 'A' + 'a';
	wordLength = strlen(inputWord);
	maxLength = 0;
	//isLink[26] = { 0 };
	_linkNode = nullptr;
}


