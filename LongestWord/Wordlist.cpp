// Wordlist.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <fstream>
#include <string>
#include "Input.h"
#include "Words.h"
#include "core.h"

bool Compare(char * a[], int alen, char * b[], int blen)
{
	int cnt;
	if (alen != blen)
		return false;
	for (cnt = 0; cnt < alen; cnt++)
	{
		if (strcmp(a[cnt], b[cnt]) != 0)
			return false;
	}
	return true;
}
/**
 * \brief 
 * \param argc 
 * \param argv 
 * \return 
 */
int main(int argc, char* argv[])
{
	/*
	char element1[] = "cd";
	char element2[] = "de";
	char element3[] = "ef";
	char element4[] = "drrrrrrrrrrr";
	char element5[] = "ada";
	char element6[] = "aba";
	char* test[] = { element1,element2,element3,element4,element5 };
	char* test_[] = { element1,element2,element3,element4,element5,element6 };
	char* anschar[] = { element5,element1,element4 };
	char* answord[] = { element5,element1,element2,element3 };
	char** reschar = new char*[10];
	char** resword = new char*[10];
	int res_word = Core::gen_chain_word(test, 5, resword, '\0', '\0', false);
	int res_char = Core::gen_chain_char(test, 5, reschar, '\0', '\0', false);
	Compare(reschar, res_char, anschar, 3);
	Compare(resword, res_word, answord, 4);
	int res_char_ = Core::gen_chain_char(test_, 6, reschar, '\0', '\0', false);
	*/

	ofstream fout;
	fout.open("solution.txt");
	vector<string> para;                       //�����в���
	auto i = 0;
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
