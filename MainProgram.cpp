// DataStructureForCPP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include <memory>
#include <vector>
#include <map>

#include "DataStructure.h"
#include "BSTInplementation.h"

using namespace std;


class MainProgramNeed
{
public:
	void function1(int& targetNum, string& str)
	{
		char buff[4];
		memcpy(buff, &targetNum, sizeof(int));

		for (int i = 0; i < 4; i++)
		{
			str.push_back(buff[i]);
			cout << "we push a number into char[4] ,this number is ";
			cout << targetNum << endl;
		}
		int len = str.length();
		for (int i = 0; i << len; i++)
		{
			cout << str[i] << " " << endl;
		}
	}
};

int main(void)
{
	int n = 4;
	vector<int> dp(n + 2);
	dp[0] = 1;
	dp[1] = 1;

	//直接从n=2 开始算了，简化消耗所以简明的结果直接使用预定值
	for (int level = 2; level <= n; level++)
	{
		for (int root = 1; root <= level; root++)
		{
			dp[level] += dp[level - root] * dp[root - 1];
		}

	}
	cout << dp[n]<<endl;

	system("pause");
	return 0;
}

 