#pragma once
#include "stdafx.h"
#include <string>
using namespace std;


class LeetCode_8_StringtoInteger
{
	int myAtoi(string str) {
		long result = 0;
		int indicator = 1;
		//从每一个字符开始遍历
		for (int i = 0; i<str.size();)
		{
			//返回第一个不包含' '的字符串
			i = str.find_first_not_of(' ');
			if (str[i] == '-' || str[i] == '+')
				indicator = (str[i++] == '-') ? -1 : 1;
			while ('0' <= str[i] && str[i] <= '9')
			{
				result = result * 10 + (str[i++] - '0');
				if (result*indicator >= INT_MAX) return INT_MAX;
				if (result*indicator <= INT_MIN) return INT_MIN;
			}


			return result*indicator;
		}
	}
};