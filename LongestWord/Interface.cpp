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
	vector<Node> topo;                                 //�ز�������
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
	//�ز�����
	int j, k;
	for (i = 0; i < len; i++)							//vSize��ѭ��  
	{
		j = 0;
		while (j < len && node[j].getIn() != 0)
			j++;										//�ҵ����Ϊ0�Ķ���  
		topo.push_back(node[j]);                        //����  
		node[j].setIn(-1);
		//indegree[j] = -1;								// ����jΪ���Ϊ-1�������ٴ����j  

		for (k = 0; k < node[j].nextNode.size(); k++)                      //����������ȵ�  
			node[j].nextNode[k].setIn(node[j].nextNode[k].getIn() - 1);
	}
	if (topo.size() < len)
		cout << "���ڻ�" << endl;
	else
	{
		//��ʼ��
		int x, y, z, v1, v2, max = 0, **path, *p;
		Node nodeNow;
		//vector<Node> maxPath;
		vector<Node> p;
		//maxPath = new int[vSize];            //�����·������ʾ������N���·��
		//p = new int[vSize];                  //���������·�ߵ�ѡ�񶥵�
		//path = new int*[vSize];	           //��������㵽����·������
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
		//�ؼ����룬���·��
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
				if (is_element_in_vector(node1.nextNode, node2))                     //��ʾ��·
				{
					if (node1.maxPath + node2.getLength() > node2.maxPath)
						node2.maxPath = node1.maxPath + node2.getLength();

					if (node2.maxPath > max)
					{
						max = node2.maxPath;       //���泤��
						path[v1][v2] = max;         //һ���㵽��һ������·��
					}
				}
			}
		}

		//���·��
		stack<Node> s;//������·
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

		//������
		cout << endl << "�·���ĳ����ǣ�" << max << endl << "�·��Ϊ��";
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

int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)     //�����������
{
	cout << "��൥��" << endl;
	return gen_chain(words, len, result, head, tail, enable_loop, true);
}

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)      //��ĸ�������
{
	cout << "�����ĸ" << endl;
	return gen_chain(words, len, result, head, tail, enable_loop, false);
}