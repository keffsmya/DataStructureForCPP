#pragma once
#include <vector>
#include <string>
#include <memory>
#include "stdafx.h"
#include "DataStructure.h"


typedef class BinaryTree
{
public:
	//LeetCode_687_LongestUnivaluePath
	int longestUnivaluePath(TreeNode* root);

	//LeetCode_637_AverageofLevelInBinaryTree
	vector<double> averageOfLevels(TreeNode* root);
private:
	int dfs(TreeNode* node, int& lup);
}*pBinaryTree;