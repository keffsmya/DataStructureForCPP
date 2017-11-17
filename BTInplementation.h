#pragma once
#include <vector>
#include <string>
#include <memory>
#include "stdafx.h"
#include "DataStructure.h"


typedef class BinaryTree
{
public:
	int longestUnivaluePath(TreeNode* root);

private:
	int dfs(TreeNode* node, int& lup);
}*pBinaryTree;