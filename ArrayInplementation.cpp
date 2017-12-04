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
		//在保证i>0情况下，只要nums1[i]>nums2[j]
		//因为都个自从自己的最大数开始遍历
		if (i > 0 && nums1[i] > nums2[j])
		{
			//所以如果是nums[i]大的话，必定是nums[i]是数组里最大的
			nums1[tar] = nums1[i];
			//然后就不再重复选择，而是往前进一位
			i--;
		}
		//同理
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

	//先不用管最后两位，
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