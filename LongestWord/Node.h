#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Node
{
private:
	char word[100];
	char head;
	char tail;
	int wordLength;
	int in;
	int out;

public:
	void formNode(char inputWord[]);
	char getHead() { return head; }
	char getTail() { return tail; }
	int getLength() { return wordLength; }
};