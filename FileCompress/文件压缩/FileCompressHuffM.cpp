#define _CRT_SECURE_NO_WARNINGS = 1

#include "FileCompressHuff.h"
#include "HuffmanTree.hpp"
#include <string>
#include <assert.h>
#include<algorithm>

void FileCompressHuff::GetCharNode(HuffmanTreeNode<CharInfo> *_Proot)
{
	if (_Proot == nullptr)
		return;
	GetCharNode(_Proot->_lchild);
	GetCharNode(_Proot->_rchild);
	if (_Proot->_lchild == nullptr &&_Proot->_rchild == nullptr)
	{
		HuffmanTreeNode<CharInfo> * cur = _Proot;
		HuffmanTreeNode<CharInfo> * parent = cur->_parenet;
		while (parent)
		{
			if (parent->_lchild == cur)
				v[_Proot->_weight._ch]._strCode += '0';
			else
				v[_Proot->_weight._ch]._strCode += '1';
			cur = parent;
			parent = cur->_parenet;
		}
	}
}
void FileCompressHuff::WriteHead(const string& strFilePath, FILE* fOut)
{
	
	char szcount[32];
	string strHead = strFilePath.substr(strFilePath.rfind('.'));
	strHead += '\n';
	
	size_t linecount = 0;
	
	string strCharInfo;
	for (size_t i = 0; i < 256; ++i)
	{
		if (v[i]._charCount)
		{
			linecount++;
			strCharInfo += v[i]._ch;
			strCharInfo += ',';
			_itoa(v[i]._charCount, szcount, 10);
			strCharInfo += szcount;
			strCharInfo += '\n';
		}
	}
	_itoa(linecount, szcount, 10);
	strHead += szcount;
	strHead += '\n';
	strHead += strCharInfo;
	fwrite(strHead.c_str(), 1, strHead.size(), fOut);
}

void FileCompressHuff::CompressHuff(const string& strFilePath)
{
	//1.��ȡԭ�ļ���ÿ���ַ����ֵĴ���
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (fIn == nullptr)
	{
		cout << "�ļ���ʧ��";
		return;
	}
	unsigned char *pReadBuff = new unsigned char[1024];
	v.resize(256);
	for (size_t i = 0; i < 256; ++i)
	{
		v[i]._ch = i;
	}
	while (1)
	{
		size_t rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;
		for (size_t i = 0; i < rdSize; ++i)
		{
			v[pReadBuff[i]]._charCount++;
		}
	}

	//2.��ÿ���ַ����ֵĴ�����ΪȨֵ������������

	HuffmanTree<CharInfo> ht(v,0);

	//3.���ݹ���������ȡÿ���ַ��ı���

	GetCharNode(ht._Proot);
	for (size_t i = 0; i < v.size(); ++i)
	{
		reverse(v[i]._strCode.begin(), v[i]._strCode.end());
	}
	//4.����ÿ���ַ��ı������¸�дԭ�ļ�
	FILE* fOut = fopen("1.hzp", "wb");
	assert(fOut);
	fseek(fIn, 0, SEEK_SET);
	unsigned char buff[1024] = {0};
	char bitcount = 0;
	unsigned char ch = 0;
	WriteHead(strFilePath, fOut);
	while (1)
	{
		size_t ChSize = fread(buff, 1, 1024, fIn);
		if (0 == ChSize)
			break;
		for (size_t i = 0; i < ChSize; ++i)
		{
			string& strCode = v[buff[i]]._strCode;
			for (size_t j = 0; j < strCode.size(); ++j)
			{
				ch <<= 1;
				if (strCode[j] == '1')
					ch |= 1;
				bitcount++;
				if (bitcount == 8)
				{
					fputc(ch, fOut);
					bitcount = 0;
				}
			}
		}
	}
	if (bitcount > 0 && bitcount < 8)
	{
		ch <<= (8 - bitcount);
		fputc(ch, fOut);
	}
	fclose(fIn);
	fclose(fOut);
}

bool FileCompressHuff::ReadLine(FILE* fIn, string &line)
{
	unsigned char ch = fgetc(fIn);
	if (ch == EOF)
		return false;
	while (ch != EOF && ch != '\n')
	{
		line += ch;
		ch = fgetc(fIn);
	}
	return true;
}

void FileCompressHuff::UnCompressHuff(const string& strFilePath)
{
	string strhead = strFilePath.substr(strFilePath.rfind('.'));
	if (strhead != ".hzp")
	{
		cout << "��ѹ�ļ���ʽ��ƥ��" << endl;
		return;
	}
	v.resize(256);
	for (size_t i = 0; i < 256; ++i)
	{
		v[i]._ch = i;
		v[i]._charCount = 0;
	}

	FILE *fIn = fopen(strFilePath.c_str(), "rb");
	string configname;
	strhead.clear();
	ReadLine(fIn, strhead);
	configname = "2" +  strhead;

	FILE *fOut = fopen(configname.c_str(), "wb");
	string line;

	ReadLine(fIn, line);
	 long long count = atoi(line.c_str());

	line.clear();

	while (count--&&ReadLine(fIn, line))
	{
		
		if (line.empty())
		{
			line += '\n';
			continue;
		}
		int index = line.rfind(',');
		v[(unsigned char)line[0]]._charCount = atoi(line.substr(2).c_str());
		if (line[0] == '\n')
			count+=1;
		line.clear();
	}

	HuffmanTree<CharInfo> ht(v, 0);

	//3.���ݹ���������ȡÿ���ַ��ı���

	GetCharNode(ht._Proot);
	for (size_t i = 0; i < v.size(); ++i)
	{
		reverse(v[i]._strCode.begin(), v[i]._strCode.end());
	}
	
	//4.д�ļ�
	HuffmanTreeNode<CharInfo> *cur;
	
	cur = ht._Proot;

	long long charcount = cur->_weight._charCount;
	int pos = 7;
	int c = 0;
	unsigned char ch = fgetc(fIn);
	while (!feof(fIn))
	{
		if (cur->_lchild == nullptr && cur->_rchild == nullptr)
		{
			charcount--;
			fputc(cur->_weight._ch, fOut);
			cur = ht._Proot;
			if (charcount == 0)
				break;
		}
		if ((ch & (1<< pos)) == 0)
		{
			cur = cur->_lchild;
			c++;
		}
		else
		{
			cur = cur->_rchild;
			c++;
		}
		if (c == 8)
		{
			pos = 7;
			ch = fgetc(fIn);
			c = 0;
			continue;
		}
		pos--;
	}
}
