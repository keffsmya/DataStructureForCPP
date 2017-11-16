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
		//��s����ַ����ĵ�iλ����pstr���ָ��ָ����ַ�������ĵ�pst_row���ַ����б�������
		pStr[pst_row].push_back(s[i]);
		//����ǵ�һ�У���ô��ȷ�����������µ�
		if (pst_row == 0) step = 1;
		//��������һ�У�����ͷ���
		if (pst_row == numRows - 1) step = -1;
	}
	//���������Ϊ��ԭ·�������ռ�ö���ڴ棬��ȻҲ�����¿���һ���ַ���
	s.clear();

	for (int j = 0; j < numRows; j++)
	{
		s.append(pStr[j]);
	}


	delete[] pStr;
	return s;
}

