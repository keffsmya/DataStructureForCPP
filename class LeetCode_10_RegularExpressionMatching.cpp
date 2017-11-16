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


	///����һ��vector<vector<bool>>���͵Ķ���
	///������ľ���danamicprogramming(m + 1, ����)���ǵ�һ��vector��5�ֹ��캯���е�һ�֣���ζ���ǹ���m+1��������������ÿһ�����������и�ֵ
	///vector<bool>(n + 1, false)Ҳ���õ���ͬ���Ĺ��캯��������ʼ����ͬʱ�Ե��������и�ֵ��ֻ�������︳ֵ����bool
	///�����ܹ���(m+1)*(n+1)�ֽ��
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
	