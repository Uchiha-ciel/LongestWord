// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	vector<string> para;                       //命令行参数
	int i = 0;
	int numOfChain = 0;                        //返回的单词链长度
	char* tempWords[20000];                   //用于实现接口
	char* longestWordChain[20000] = { 0 };    //保存结果
	Input* input = new Input();                //输入类处理输入
	Words* wordList = new Words();             //单词列表类得到单词表
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
	if (input->getWpara())                     //单词数最多
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
	else if (input->getCpara())               //字母数最多
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
