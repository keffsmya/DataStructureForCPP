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

	//LeetCode_102_BinaryTreeLevelOrderTraversalII
	vector<vector<int>> BinaryTreeLevelOrderTraversal(TreeNode* root);

	//LeetCode_107_BinaryTreeLevelOrderTraversalII
	vector<vector<int>> BinaryTreeLevelOrderTraversalII(TreeNode* root);

	//LeetCode_226_InvertBinaryTree
	TreeNode* invertTree(TreeNode* root);
	void invertTreeNode(TreeNode* node);
	//LeetCode_257_BinaryTreePaths
	vector<string> binaryTreePaths(TreeNode* root);
	void binaryTreePaths(vector<string>& result, TreeNode* root, string t);

	//LeetCode_563_BinaryTreeTilt
	int findTilt(TreeNode* root);
	int GetBTSum(TreeNode* node);

	//LeetCode_104_MaximunDepthofBinaryTree
	int maxDepth(TreeNode* root);
	int getThemaxlength(TreeNode* node);

	//LeetCode_572_SubtreeofAnotherTree
	bool isSubtree(TreeNode* s, TreeNode* t);
	bool isSubtreetraverse(TreeNode* s, TreeNode* t);

	//LeetCode_110_BalancedBinaryTree
	bool isBalanced(TreeNode* root);
	bool isBlancedTraverse(TreeNode* root);

	//LeetCode_101_SymmetricTree
	bool isSymmetric(TreeNode* root);
	bool isMirror(TreeNode* t1, TreeNode* t2);

	//LeetCode_508_MostFrequentSubtreeSum
	vector<int> findFrequentTreeSum(TreeNode* root);
	int countSubtreeSums(TreeNode* node, map<int, int> &counts, int& maxCount)£»£»

private:
	int dfs(TreeNode* node, int& lup);
}*pBinaryTree;