// Core.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "core0.h"
#include "Core.h"

int Core::gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)     //单词数量最多
{
	core0 newCore = core0(0);
	return newCore.gen_chain_word(words, len, result, head, tail, enable_loop);
}

int Core::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)      //字母数量最多
{
	core0 newCore = core0(1);
	return newCore.gen_chain_char(words, len, result, head, tail, enable_loop);
}
