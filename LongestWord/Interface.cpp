#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include "Input.h"
#include "Words.h"
#include "Node.h"

/*
bool is_element_in_vector(vector<Node> v, Node node) {
	vector<Node>::iterator it;
	it = find(v.begin(), v.end(), node);
	if (it != v.end()) {
		return true;
	}
	else {
		return false;
	}
}
*/

void trans2object(char* words[],int len)
{

}

int gen_chain(char* words[], int len, char* result[], char head, char tail, bool enable_loop,bool flag)    
{
	int i;
	int lengthNow = 0;
	Node* node = new Node[100000];
	vector<Node> topo;                                 //拓补排序结果
	for (i = 0; i < len; i++)
	{
		//cout << wordList->listSize << endl;
		cout << words[i] << endl;
		node[i].formNode(words[i]);
	}
	for (i = 0; i < len; i++)
	{
		node[i].createGraph(node, len);
	}
	//拓补排序
	int j, k;
	for (i = 0; i < len; i++)							//vSize次循环  
	{
		j = 0;
		while (j < len && node[j].getIn() != 0)
			j++;										//找到入度为0的顶点  
		topo.push_back(node[j]);                        //保存  
		node[j].setIn(-1);
		//indegree[j] = -1;								// 设结点j为入度为-1，以免再次输出j  

		for (k = 0; k < node[j].nextNode.size(); k++)                      //更新其他入度点  
			node[j].nextNode[k].setIn(node[j].nextNode[k].getIn() - 1);
	}
	if (topo.size() < len)
		cout << "存在环" << endl;
	else
	{
		//初始化
		int x, y, z, v1, v2, max = 0, **path, *p;
		Node nodeNow;
		//vector<Node> maxPath;
		vector<Node> p;
		//maxPath = new int[vSize];            //保存最长路径，表示到顶点N的最长路径
		//p = new int[vSize];                  //用来处理最长路线的选择顶点
		//path = new int*[vSize];	           //用来保存点到点的最长路径矩阵
		/*
		for (x = 0; x < vSize; x++)
			path[x] = new int[vSize];
		for (x = 0; x < vSize; x++)
			for (y = 0; y < vSize; y++)
				path[x][y] = 0;
		for (x = 0; x < vSize; x++)
		{
			maxPath[x] = 0;
			p[x] = 0;
		}
		*/
		//关键代码，求最长路径
		for (y = 0; y < len; y++)
		{
			nodeNow = topo[y];
			for (z = 0; z < y; z++)
			{
				if (topo[z].getTail() == nodeNow.getHead() && topo[z].maxLength > 0)
					lengthNow = topo[z].maxLength + nodeNow.getLength();
				//node1 = topo[z];
				if (lengthNow > nodeNow.maxLength)
				{

				}
				if (is_element_in_vector(node1.nextNode, node2))                     //表示有路
				{
					if (node1.maxPath + node2.getLength() > node2.maxPath)
						node2.maxPath = node1.maxPath + node2.getLength();

					if (node2.maxPath > max)
					{
						max = node2.maxPath;       //保存长度
						path[v1][v2] = max;         //一个点到另一个点的最长路径
					}
				}
			}
		}

		//求最长路线
		stack<Node> s;//保存线路
		for (x = len - 1; x > 0;)
		{
			for (y = 0; y < len; y++)
			{
				p[y] = path[y][x];
			}
			sort(p, p + len);
			int maxValue = p[y - 1];
			if (maxValue != 0)
			{
				for (y = 0; y < len; y++)
				{
					if (path[y][x] == maxValue)
					{
						s.push(x);
						x = y;
						if (x == 0)
							s.push(x);
						break;
					}
				}
			}
		}

		//输出结果
		cout << endl << "最长路径的长度是：" << max << endl << "最长路径为：";
		int len = s.size();
		for (x = 0; x < len; x++)
		{
			if (x != 0) cout << " -> ";
			cout << v[s.top()];
			s.pop();
		}
		cout << endl << endl;
	}
}

int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)     //单词数量最多
{
	cout << "最多单词" << endl;
	return gen_chain(words, len, result, head, tail, enable_loop, true);
}

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)      //字母数量最多
{
	cout << "最多字母" << endl;
	return gen_chain(words, len, result, head, tail, enable_loop, false);
}