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
//		//�������ַ���Ϊ�գ���ôֱ�ӷ�Χ���ַ���
//		if (s.empty()) return "";
//		//����ַ���ֻ��һ���ַ�����ôֱ�ӷ�������ַ������У���Ϊֻ��һ��
//		if (s.size() == 1) return s;
//		//������С��ʵλ�ú���󸲸ǳ���
//		int min_start = 0, max_len = 1;
//		//�������ҿ�ʼ����
//		for (int i = 0; i < s.size();) {
//			//
//			if (s.size() - i <= max_len / 2) break;
//			int j = i, k = i;
//			//�ȴ������ұ������Եõ�����Ӵ�����һ�������������û���ظ����ַ���Ҳ���ǻ����ַ�����һ�֣����ǻ�������Ȼ���ܻ��кܶ��������Ҫ�������еĿ���
//			while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
//			//Ȼ���i�ƶ���k+1��Ҳ���Ǹպ�����ǳ��ȵĺ���һ��
//			i = k + 1;
//			//Ȼ���ֿ�ʼ���������չ�������������ĵ���ߺ��ұ߸պ���ȵĻ����Ͱ�����λҲ������ȥ��Ȼ�������⣬֪���������ĳ���
//			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
//			
//			int new_len = k - j + 1;
//			//ÿ�ζ�����һ�εĽ�����жԱ�
//			if (new_len > max_len) { min_start = j; max_len = new_len; }
//		}
//		//���ֱ��ʹ��substr��������ָ�����ַ���
//		return s.substr(min_start, max_len);
//
//
//#endif
//
//
//
//	}
};