#include <iostream>
#include <string>
#include "Input.h"
#include "Words.h"
#include "Common.h"

int main(int argc, char * argv[])
{
	int i = 0;
	int numOfChain = 0;
	char* tempWords[100000];
	char* longestWordChain[100000] = { 0 };
	Input* input = new Input();
	input->spilt(argv);
	Words* wordList = new Words();
	wordList->saveWord(input->getPath());
	for (i = 0; i < wordList->listSize; i++)
	{
		tempWords[i] = wordList->words[i];
	}
	if (input->getWpara)
	{
		numOfChain = gen_chain_word(tempWords, wordList->listSize, longestWordChain, input->getHeadChar, input->getTailChar, input->getRpara);
		for (i = 0; i < numOfChain; i++)
		{
			cout << longestWordChain[i] << endl;
		}
	}
	else if (input->getCpara)
	{
		numOfChain = gen_chain_char(tempWords, wordList->listSize, longestWordChain, input->getHeadChar, input->getTailChar, input->getRpara);
		for (i = 0; i < numOfChain; i++)
		{
			cout << longestWordChain[i] << endl;
		}
	}
	getchar();
}