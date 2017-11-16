#include "stdafx.h"
#include "LeetCode_14_LongestCommonPrefix.h"

string LeetCode_14_LongestCommonPrefix::longestCommonPrefix(vector<string> &strs)
{
	string ret_prefix = "";
	
	//��һ��forѭ����,
	for (int idx = 0; strs.size()>0; ret_prefix += strs[0][idx], idx++)
		for (int i = 0; i<strs.size(); i++)
			//���������ǰ׺��idxλ���Ѿ�������ĳһ��str��ȫ��������
			if (idx >= strs[i].size() || (i > 0 && strs[i][idx] != strs[i - 1][idx]))
				return ret_prefix;
	return ret_prefix;
}