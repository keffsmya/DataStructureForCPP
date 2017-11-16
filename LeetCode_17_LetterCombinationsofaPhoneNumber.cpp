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
		//����������õ��������漰��ASCII������
		//'0'��ASCII��ֵΪ48
		//ʹ��һ�·����Ϳɵõ����ε�����
		int num = digits[i] - '0';
		//��������ж��Ƿ������֣���Ϊ���������Χ��˵������ַ������ǰ������ֵ��ַ�
		if (num < 0 || num > 9) break;
		//
		const string& candidate = v[num];
		//�ж�candidate�Ƿ�Ϊ�����б��Ƿ�������1����0
		if (candidate.empty()) continue;
		//�½�һ��vector<string>���͵�������
		vector<string> tmp;

		//char�������string����
		//char�����Ϊascii���������ת��������
		for (int j = 0; j < candidate.size(); ++j) {
			for (int k = 0; k < (int)result.size(); ++k) {
				tmp.push_back(result[k] + candidate[j]);
			}
		}
		//����tmp�е������result��
		result.swap(tmp);
	}
	return result;

}