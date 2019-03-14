#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Node.h"
#include "core.h"

using namespace std;

Core::Core(int if_c)
{
	_if_c = if_c;
	topSortArray[26] = { 0 };
	InDegreeNum[26] = { 0 };
	isExistEdge[26][26] = { 0 };
	sameHeadNode = new vector<Node*>[26];      //26个vector
}

void Core::trans2object(char* words[],int len,bool enable_loop)
{
	int i;
	int headNum = -1;
	int tailNum = -1;
	bool ifSameWord = false;
	for (i = 0; i < len; i++)
	{
		Node* object = new Node(words[i]);
		headNum = object->getHead() - 'a';
		tailNum = object->getTail() - 'a';
		if (headNum == tailNum)
		{
			for (int j = 0; j < int(sameHeadNode[headNum].size()); j++)
			{
				if (strcmp(object->word,sameHeadNode[headNum][j]->word) == 0) {
					ifSameWord = true;
				}
			}
			sameHeadNode[headNum].insert(sameHeadNode[headNum].begin(), object);        //首尾字母相同就放在最前面
			if (!ifSameWord)
			{
				if (!enable_loop && isExistEdge[headNum][tailNum] > 0)
				{
					cout << "have cycle" << endl;
					exit(1);
				}
				else
				{
					isExistEdge[headNum][tailNum] = 1;
				}
			}
			ifSameWord = false;
		}
		else
		{
			sameHeadNode[headNum].push_back(object);                                 //结点放入相应的vector
			if (!enable_loop && isExistEdge[headNum][tailNum] < 0)
			{
				cout << "have cycle" << endl;
				exit(1);

			}
			else
			{
				if (isExistEdge[headNum][tailNum] == 0)
				{
					InDegreeNum[tailNum]++;
				}
				isExistEdge[headNum][tailNum] = 1;
				isExistEdge[tailNum][headNum] = -1;
			}
		}
	}
}

void Core::topSort()
{
	int i,j;
	int sortedIndex = 0;
	int removed[26] = { 0 };
	int noZero = 1;
	while(sortedIndex < 26)
	{
		for (i = 0; i < 26; i++)
		{
			if (InDegreeNum[i] == 0 && removed[i] == 0) 
			{
				noZero = 0;
				removed[i] = 1;
				topSortArray[sortedIndex] = i;
				sortedIndex++;
				for (j = 0; j < 26; j++)
				{
					if (i != j && sameHeadNode[i].size() > 0 && isExistEdge[i][j] > 0)
						InDegreeNum[j]--;
				}
			}
		}
		if (noZero)
		{
			cout << "have cycle" << endl;
			exit(1);
		}
	}
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < int(sameHeadNode[topSortArray[i]].size()); j++)
		{
			topo.push_back(sameHeadNode[topSortArray[i]][j]);
		}
	}
}

void Core::getMaxPath(Node* &linkNode,int len)
{
	int i, j;
	int length = 0;
	int maxLength = 0;
	for (i = 0; i < len; i++)
	{
		Node* nodeNow = topo[i];
		for (j = 0; j < i; j++)
		{
			if (topo[j]->getTail() == nodeNow->getHead())
			{
				if (_if_c)
				{
					length = topo[j]->maxLength + nodeNow->getWordLength();
				}
				else
				{
					length = topo[j]->maxLength + 1;
				}
				if (length > nodeNow->maxLength)
				{
					nodeNow->maxLength = length;
					nodeNow->_linkNode = topo[j];
				}
			}
		}
		if (_if_c)
		{
			if (nodeNow->maxLength < nodeNow->getWordLength())
			{
				nodeNow->maxLength = nodeNow->getWordLength();
			}
		}
		else
		{
			if (nodeNow->maxLength == 0)
			{
				nodeNow->maxLength = 1;
			}
		}
		if (nodeNow->maxLength > maxLength)
		{
			maxLength = nodeNow->maxLength;
			linkNode = nodeNow;
		}
	}
}

int Core::gen_chain(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	int i;

	
	Node *linkNode = nullptr;
	vector<Node*> longestPath;

	trans2object(words,len,enable_loop);  // 根据传入的字符指针数组构建相应的对象
	if (!enable_loop)
	{
		topSort();        //拓补排序
		getMaxPath(linkNode, len);
		while (linkNode != nullptr)
		{
			longestPath.insert(longestPath.begin(),linkNode);
			linkNode = linkNode->_linkNode;
		}
		for (i = 0; i < int(longestPath.size()); i++)
		{
			result[i] = longestPath[i]->word;
		}
		return int(longestPath.size());
	}
	else
	{
		cout << "have cycle" << endl;
		exit(1);
	}
}

int Core::gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)     //单词数量最多
{
	Core newCore = Core(0);
	return newCore.gen_chain(words, len, result, head, tail, enable_loop);
}

int Core::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)      //字母数量最多
{
	Core newCore = Core(1);
	return newCore.gen_chain(words, len, result, head, tail, enable_loop);
}