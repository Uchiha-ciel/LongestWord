// Wordlist.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <fstream>
#include <string>
#include "Input.h"
#include "Words.h"
#include "core.h"

int main(int argc, char * argv[])
{
	ofstream fout;
	fout.open("solution.txt");
	vector<string> para;                       //�����в���
	int i = 0;
	int numOfChain = 0;                        //���صĵ���������
	char* tempWords[20000];                   //����ʵ�ֽӿ�
	char* longestWordChain[20000] = { 0 };    //������
	Input* input = new Input();                //�����ദ������
	Words* wordList = new Words();             //�����б���õ����ʱ�
	for (i = 0; i < argc; i++)
	{
		para.push_back(argv[i]);
	}
	input->spilt(argc, para);
	wordList->saveWord(input->getPath());
	for (i = 0; i < wordList->listSize; i++)
	{
		tempWords[i] = wordList->words[i];
	}
	if (input->getWpara())                     //���������
	{
		int flag = 0;
		numOfChain = Core::gen_chain_word(tempWords, wordList->listSize, longestWordChain, input->getHeadChar(), input->getTailChar(), input->getRpara());
		for (i = 0; i < numOfChain; i++)
		{
			if (input->getHeadChar() != '\0' && input->getTailChar() == '\0')
			{
				if (longestWordChain[i][0] == input->getHeadChar())
					flag = 1;
				if (flag)
				{
					if (i > 0 && strcmp(longestWordChain[i], longestWordChain[i - 1]) != 0)
						fout << longestWordChain[i] << endl;
					if (i == 0)
						fout << longestWordChain[i] << endl;
				}

			}
			else if (input->getHeadChar() == '\0' && input->getTailChar() != '\0')
			{
				if (i > 0 && strcmp(longestWordChain[i], longestWordChain[i - 1]) != 0)
					fout << longestWordChain[i] << endl;
				if (i == 0)
					fout << longestWordChain[i] << endl;
				if (longestWordChain[i][strlen(longestWordChain[i]) - 1] == input->getTailChar())
					break;
			}
			else if (input->getHeadChar() != '\0' && input->getTailChar() != '\0')
			{
				if (longestWordChain[i][0] == input->getHeadChar())
					flag = 1;
				if (flag)
				{
					if (i > 0 && strcmp(longestWordChain[i], longestWordChain[i - 1]) != 0)
						fout << longestWordChain[i] << endl;
					if (i == 0)
						fout << longestWordChain[i] << endl;
				}
				if (longestWordChain[i][strlen(longestWordChain[i]) - 1] == input->getTailChar())
					break;
			}
			else
			{
				if (i > 0 && strcmp(longestWordChain[i], longestWordChain[i - 1]) != 0)
					fout << longestWordChain[i] << endl;
				if (i == 0)
					fout << longestWordChain[i] << endl;
			}
		}
	}
	else if (input->getCpara())               //��ĸ�����
	{
		int flag = 0;
		numOfChain = Core::gen_chain_char(tempWords, wordList->listSize, longestWordChain, input->getHeadChar(), input->getTailChar(), input->getRpara());
		for (i = 0; i < numOfChain; i++)
		{
			if (input->getHeadChar() != '\0' && input->getTailChar() == '\0')
			{
				if (longestWordChain[i][0] == input->getHeadChar())
					flag = 1;
				if (flag)
				{
					if (i > 0 && strcmp(longestWordChain[i], longestWordChain[i - 1]) != 0)
						fout << longestWordChain[i] << endl;
					if (i == 0)
						fout << longestWordChain[i] << endl;
				}

			}
			else if (input->getHeadChar() == '\0'&& input->getTailChar() != '\0')
			{
				if (i > 0 && strcmp(longestWordChain[i], longestWordChain[i - 1]) != 0)
					fout << longestWordChain[i] << endl;
				if (i == 0)
					fout << longestWordChain[i] << endl;
				if (longestWordChain[i][strlen(longestWordChain[i]) - 1] == input->getTailChar())
					break;
			}
			else if (input->getHeadChar() != '\0' && input->getTailChar() != '\0')
			{
				if (longestWordChain[i][0] == input->getHeadChar())
					flag = 1;
				if (flag)
				{
					if (i > 0 && strcmp(longestWordChain[i], longestWordChain[i - 1]) != 0)
						fout << longestWordChain[i] << endl;
					if (i == 0)
						fout << longestWordChain[i] << endl;
				}
				if (longestWordChain[i][strlen(longestWordChain[i]) - 1] == input->getTailChar())
					break;
			}
			else
			{
				if (i > 0 && strcmp(longestWordChain[i], longestWordChain[i - 1]) != 0)
					fout << longestWordChain[i] << endl;
				if (i == 0)
					fout << longestWordChain[i] << endl;
			}
		}
	}
	fout.close();
	return 0;
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
