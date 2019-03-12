#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

using namespace std;

void Node::formNode(char inputWord[])
{
	strcpy(word,inputWord);
	head = (inputWord[0] >= 'a' && inputWord[0] <= 'z') ? inputWord[0] : inputWord[0] - 'A' + 'a';
	tail = (inputWord[strlen(inputWord - 1)] >= 'a' && inputWord[strlen(inputWord - 1)] <= 'z') ? inputWord[strlen(inputWord - 1)] : inputWord[0] - 'A' + 'a';
	wordLength = strlen(inputWord);
	//in = 0;
	//out = 0;
	maxLength = 0;
	//cout << inputWord << endl;
	//cout << head << endl;
	//cout << tail << endl;
	//cout << wordLength << endl;
}

void Node::createGraph(Node node[],int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (this->getTail() == node[i].getHead() && strcmpi(this->word,node[i].word) != 0
)
		{
			this->setOut(this->getIn()+1);
			node[i].setIn(this->getOut()+1);
			this->nextNode.push_back(node[i]);
		}
	}
}

