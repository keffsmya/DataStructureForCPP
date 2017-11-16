#include "stdafx.h"
#include "LeetCode_16_3SumCloset.h"
#include <vector>
#include <Algorithm>
int LeetCode_16_3SumCloset::threeSumClosest(vector<int>& nums, int target)
{
	if (nums.size() < 3) return 0;
	int closet = nums[0] + nums[1] + nums[2];
	std::sort(nums.begin(),nums.end());

	for (int i = 0; i < (int)nums.size()-2;)
	{
		//这一步很重要，用于检测是否有重复
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		int front = i + 1;
		int back = (int)nums.size() - 1;
		while (front < back)
		{
			int cursum = nums[i] + nums[front] + nums[back];
			if (cursum == target) return cursum;
			if (abs(target - cursum) < abs(target - closet))
			{
				closet = cursum;
			}

			if (cursum < target)
				--back;
			else
				++front;
		}
	}
	return closet;
}
