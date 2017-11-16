#include "stdafx.h"
#include "LeetCode_6_ZigZagConversion.h"
#include <string>
using namespace std;

string LeetCode_6_ZigZagConversion::ZigZagconvert(string s, int numRows)
{
	if (numRows <= 1)
	{
		return s;
	}

	string *pStr = new string[numRows];
	const int slength = (int)s.length();
	int pst_row = 0, step = 0;
	for (int i = 0; i < slength; i++)
	{
		//把s这个字符串的第i位推入pstr这个指针指向的字符串数组的第pst_row个字符串中保存起来
		pStr[pst_row].push_back(s[i]);
		//如果是第一行，那么久确定方向是往下的
		if (pst_row == 0) step = 1;
		//如果是最后一行，方向就方向
		if (pst_row == numRows - 1) step = -1;
	}
	//这个做法是为了原路输出，不占用多的内存，当然也可以新开辟一个字符串
	s.clear();

	for (int j = 0; j < numRows; j++)
	{
		s.append(pStr[j]);
	}


	delete[] pStr;
	return s;
}

