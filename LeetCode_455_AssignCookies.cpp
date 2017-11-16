#include "stdafx.h"
#include "LeetCode_455_AssignCookies.h"
#include <Array>

using namespace std;
//Input: [1, 2, 3], [1, 1]
//
//	Output : 1
//
//	Explanation : You have 3 children and 2 cookies.The greed factors of 3 children are 1, 2, 3.
//	And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
//	You need to output 1.

//Input: [1, 2], [1, 2, 3]
//
//	Output : 2
//
//	Explanation : You have 2 children and 3 cookies.The greed factors of 2 children are 1, 2.
//	You have 3 cookies and their sizes are big enough to gratify all of the children,
//	You need to output 2.
int LeetCode_455_AssignCookies::findContentChildren(vector<int>& g, vector<int>& s)
{
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int i = g.size() - 1, j = s.size() - 1, count = 0;
	while (i >= 0 && j >= 0)
	{
		//在g[i]>s[j]的时候，说明贪心程度太高了，不能满足，所以会去掉这个贪心的小孩
		if (g[i]>s[j]) i--;
		//
		else 
			//如果这种情况下，g[i]<=s[j],说明满足了，i--,j--,所以count++
			if (g[i--] <= s[j--]) count++;
	}
	return count;
	/*
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int i = 0;
	//bool型返回值转化成int型，true为1，false为0
	for (int j = 0; i < g.size() && j < s.size(); j++) i += g[i] <= s[j];
	return i;
	*/
}


 bool  LeetCode_455_AssignCookies::selftDefinedSort(int& n1, int&n2)  
{
	return n1 < n2;
}