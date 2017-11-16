#include "malloc.h"
#include <string>
#include "stdafx.h"
using namespace std;

class  LeetCode_4_LongestPalindromeSubstring
{
public:
//	string longestParlindrome(string s)
//	{
//
//
//#ifdef DivideAndConquer
//		//如果这个字符串为空，那么直接范围空字符串
//		if (s.empty()) return "";
//		//如果字符串只有一个字符，那么直接返回这个字符串就行，因为只有一个
//		if (s.size() == 1) return s;
//		//设置最小其实位置和最大覆盖长度
//		int min_start = 0, max_len = 1;
//		//从左向右开始遍历
//		for (int i = 0; i < s.size();) {
//			//
//			if (s.size() - i <= max_len / 2) break;
//			int j = i, k = i;
//			//先从左往右便利可以得到的最长子串，这一步是用来检测有没有重复的字符，也算是回文字符串的一种，算是基础，当然可能会有很多个，所以要检测出所有的可能
//			while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
//			//然后把i移动到k+1，也就是刚好最长覆盖长度的后面一个
//			i = k + 1;
//			//然后又开始从左从右扩展，如果这基础回文的左边和右边刚好相等的话，就把这两位也包括进去，然后继续检测，知道检测完最长的长度
//			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
//			
//			int new_len = k - j + 1;
//			//每次都和上一次的结果进行对比
//			if (new_len > max_len) { min_start = j; max_len = new_len; }
//		}
//		//最后直接使用substr方法返回指定的字符串
//		return s.substr(min_start, max_len);
//
//
//#endif
//
//
//
//	}
};