#define _CRT_SECURE_NO_WARNINGS = 1
#include "FileCompressHuff.h"
#include "HuffmanTree.hpp"



int main()
{
	FileCompressHuff hf;
	hf.CompressHuff("1.cpp");
	hf.UnCompressHuff("1.hzp");

	return 0;
}