#pragma once
#include <vector>
#include "Common.h"
#include "node.h"

using namespace std;

class Core
{
private:
	int _if_c;
	//int searchHead;
	int isExistEdge[26][26];
	int topSortArray[26];
	int InDegreeNum[26];
	vector<Node*> *sameHeadNode;
	vector<Node*> topo;
public:
	Core(int if_c);
	void trans2object(char* words[], int len, bool enable_loop);
	void topSort();
	void getMaxPath(Node* &preNode,int len);
	int gen_chain(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	static int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);  // 计算最多单词数量的
	static int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);  // 计算最多字母数量的
};