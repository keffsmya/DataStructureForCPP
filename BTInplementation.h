#pragma once
#include <vector>
#include <string>
#include <memory>
#include "stdafx.h"
#include "DataStructure.h"

using namespace std;
typedef class BinaryTree
{
public:
	//LeetCode_687_LongestUnivaluePath
	int longestUnivaluePath(TreeNode* root);

	//LeetCode_637_AverageofLevelInBinaryTree
	vector<double> averageOfLevels(TreeNode* root);

	//LeetCode_100_SameTree
	bool isSameTree(TreeNode* p, TreeNode* q);
private:
	int dfs(TreeNode* node, int& lup);
}*pBinaryTree;