#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Node
{
private:
	char head;
	char tail;
	int wordLength;
	//int in;
	//int out;
public:
	int maxLength;                //到该节点的最长路径
	char word[100];
	vector<Node> preNode;
	void formNode(char inputWord[]);
	void setIn(int newIn) { in = newIn; }
	void setOut(int newOut) { out = newOut; }
	int getIn() { return in; }
	int getOut() { return out; }
	char getHead() { return head; }
	char getTail() { return tail; }
	int getLength() { return wordLength; }
	void createGraph(Node node[],int len);
};