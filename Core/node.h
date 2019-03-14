#pragma once
#include <iostream>

using namespace std;

class Node
{
private:
	char headChar;
	char tailChar;
	int wordLength;
public:
	int maxLength;                //到该节点的最长路径
	char word[100];               //单词
	//int isLink[26];
	Node* _linkNode;
	Node(char inputWord[]);
	char getHead() { return headChar; }
	char getTail() { return tailChar; }
	int getWordLength() { return wordLength; }
};