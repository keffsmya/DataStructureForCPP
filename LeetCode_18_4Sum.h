#pragma once
#include <Algorithm>
#include <vector>

using namespace std;
class LeetCode_18_4Sum
{
public:
	int len = 0;

	vector<vector<int>> fourSum(vector<int>& nums, int target);


	vector<vector<int>> kSum(vector<int>& nums, int target, int k, int index);
};