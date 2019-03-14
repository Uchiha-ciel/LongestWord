#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Core/Core.h"
#include "../Core/core0.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreUnitTest1
{		
	bool Compare(char * a[], int alen, char * b[], int blen) {
		int i;
		if (alen != blen)
			return false;
		for (i = 0; i < alen; i++) 
		{
			if (strcmp(a[i], b[i]))
				return false;
		}
		return true;
	}
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)//最初随意写的
		{
			char* test1[] = { "xsjnxd","sdchsd","csjdc","skcbds","scnsjd","scndjc","nxkasn","acn","ancdas","cnsjd" };
			int wordnum1 = 10;
			char* answer[] = { "ancdas","skcbds","scndjc","csjdc","cnsjd"};
			int answernum1 = 5;
			char **result1 = new char*[wordnum1];
			//Core* testcore1 = new Core();
			int resultnum1 = Core::gen_chain_word(test1,wordnum1,result1,'\0','\0',false);
			Assert::IsTrue(Compare(result1,resultnum1,answer,answernum1));
		}
		TEST_METHOD(TestMethod2)//与后一个测试gen_chain_char和gen_chain_word
		{
			char* test2[] = { "ab","bc","cd","drrrrrrrrrrrrrr","de","ef" };
			int wordnum2 = 6;
			char* answer[] = { "ab","bc","cd","drrrrrrrrrrrrrr" };
			int answernum2 = 4;
			char **result2 = new char*[wordnum2];
			int resultnum2 = Core::gen_chain_char(test2, wordnum2, result2, '\0', '\0', false);
			Assert::IsTrue(Compare(result2, resultnum2, answer, answernum2));
		}
		TEST_METHOD(TestMethod3)
		{
			char* test2[] = { "ab","bc","cd","drrrrrrrrrrrrrr","de","ef" };
			int wordnum2 = 6;
			char* answer[] = { "ab","bc","cd","de","ef" };
			int answernum2 = 5;
			char **result2 = new char*[wordnum2];
			int resultnum2 = Core::gen_chain_word(test2, wordnum2, result2, '\0', '\0', false);
			Assert::IsTrue(Compare(result2, resultnum2, answer, answernum2));
		}
		TEST_METHOD(TestMethod4)//头尾同字母单词
		{
			char* test[] = { "ab","bc","cd","de","ada","zh","tnt" };
			int wordnum = 7;
			char* answer[] = { "ada","ab","bc","cd","de" };
			int answernum = 5;
			char** result = new char*[wordnum];
			int resultnum = Core::gen_chain_word(test,wordnum,result,'\0','\0',false);
			Assert::IsTrue(Compare(result, resultnum, answer, answernum));
		}
	};
}