#include <vector>
#include <string>
#include <memory>
#include <queue>
#include <map>
#include "ArrayInplementation.h"
using namespace std;

#pragma region 	LeetCode_88_MergyTwoArray
void ArrayOperation::mergyTwoSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = m - 1, j = n - 1, tar = m + n - 1;
	while (j >= 0) {
		nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
		/*
		//�ڱ�֤i>0����£�ֻҪnums1[i]>nums2[j]
		//��Ϊ�����Դ��Լ����������ʼ����
		if (i > 0 && nums1[i] > nums2[j])
		{
			//���������nums[i]��Ļ����ض���nums[i]������������
			nums1[tar] = nums1[i];
			//Ȼ��Ͳ����ظ�ѡ�񣬶�����ǰ��һλ
			i--;
		}
		//ͬ��
		else
		{
			nums1[tar] = nums2[j];
			j--;
		}
		tar--;
		*/
	}
}


#pragma endregion


#pragma region LeetCode_717_1-bitand2-bitCharacters
bool ArrayOperation::isOneBitCharacter(vector<int>& bits) {
	int ones = 0;

	//�Ȳ��ù������λ��
	for (int i = (int)bits.size() - 2; i >= 0 && bits[i] != 0; i--)
	{
		ones++;
	}
	if (ones % 2 > 0) return false;
	return true;
}
#pragma endregion

#pragma region 
int ArrayOperation::findShortestSubArray(vector<int>& nums) {
	map<int, int> record;

	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
	{
		record[*iter]++;
	}


}

#pragma endregion