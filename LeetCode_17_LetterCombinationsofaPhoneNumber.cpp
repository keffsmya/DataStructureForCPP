#include "stdafx.h"
#include "LeetCode_17_LetterCombinationsofaPhoneNumber.h"
#include <string>
#include <vector>
#include <unordered_map>


vector<string> LeetCode_17_LetterCombinationsofaPhoneNumber::letterCombinations(string digits)
{
	vector<string> result;
	if (digits.empty()) return vector<string>();
	static const vector<string> v = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	result.push_back("");

	for (int i = 0; i < (int)digits.size(); ++i)
	{
		//并不是相减得到，其中涉及到ASCII的问题
		//'0'的ASCII码值为48
		//使用一下方法就可得到整形的数字
		int num = digits[i] - '0';
		//这里可以判定是否是数字，因为不在这个范围内说明这个字符并不是包含数字的字符
		if (num < 0 || num > 9) break;
		//
		const string& candidate = v[num];
		//判断candidate是否为空来判别是否输入了1或者0
		if (candidate.empty()) continue;
		//新建一个vector<string>类型的容器类
		vector<string> tmp;

		//char型相加是string类型
		//char型相减为ascii相减，可以转换成整形
		for (int j = 0; j < candidate.size(); ++j) {
			for (int k = 0; k < (int)result.size(); ++k) {
				tmp.push_back(result[k] + candidate[j]);
			}
		}
		//最后把tmp中的深拷贝到result中
		result.swap(tmp);
	}
	return result;

}