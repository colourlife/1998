#define _CRT_SECURE_NO_WARNINGS = 1
#pragma once
#include "HuffmanTree.hpp"
#include <iostream>
#include <vector>
using namespace std;

struct CharInfo{
	CharInfo(size_t _charCount = 0)
	:_charCount(_charCount)
	{}
	CharInfo operator+(const CharInfo& info)
	{
		return CharInfo(_charCount + info._charCount);
	}
	bool operator>(const CharInfo& info)
	{
		return (_charCount > info._charCount);
	}
	bool operator!=(const CharInfo& info)const
	{
		return (_charCount != info._charCount);
	}
	bool operator==(const CharInfo& info) const
	{
		return (_charCount == info._charCount);
	}


	unsigned char _ch;
	long long _charCount;
	string _strCode;
};

typedef struct CharInfo CharInfo;
class FileCompressHuff{
	
public:
	void CompressHuff(const string& strFilePath);
	void UnCompressHuff(const string& strFilePath);
	void GetCharNode(HuffmanTreeNode<CharInfo> *_Proot);
	void WriteHead(const string& strFilePath, FILE* fOut);
	bool ReadLine(FILE* fIn, string &line);
private:
	vector<CharInfo> v;
};