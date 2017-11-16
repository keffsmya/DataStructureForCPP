#include "stdafx.h"
#include "LeetCode_10_RegularExpressionMatching.h"
#include <string>
#include <vector>
#include <memory>


using namespace std;


bool LeetCode_10_RegularExpressionMatching::isMatch(string str, string pattern)
{
#define DynamicProgramming 1
#ifdef DynamicProgramming


	int m = str.length(); int n = pattern.length();


	///声明一个vector<vector<bool>>类型的对象
	///而后面的就是danamicprogramming(m + 1, ？？)就是第一个vector的5种构造函数中的一种，意味着是构造m+1个迭代器，并对每一个迭代器进行赋值
	///vector<bool>(n + 1, false)也采用的是同样的构造函数，即初始化的同时对迭代器进行赋值，只不过这里赋值的是bool
	///所以总共有(m+1)*(n+1)种结果
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

	dp[0][0] = true;
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (pattern[j - 1] == '*')
				dp[i][j] = dp[i][j - 2] || (i > 0 && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && dp[i - 1][j]);
			else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
			return dp[m][n];



#else

	return false;
#endif

}
	