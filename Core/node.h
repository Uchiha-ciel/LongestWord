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
	int maxLength;                //���ýڵ���·��
	char word[100];               //����
	//int isLink[26];
	Node* _linkNode;
	Node(char inputWord[]);
	char getHead() { return headChar; }
	char getTail() { return tailChar; }
	int getWordLength() { return wordLength; }
};