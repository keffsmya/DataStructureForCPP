#pragma once
#include <vector>
#include <string>
#include <memory>
#include "stdafx.h"
#include <queue>
#include <map>
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
	int countSubtreeSums(TreeNode* node, map<int, int> &counts, int& maxCount);

	//LeetCode_404_SumofLeftLeaves
	int sumOfLeftLeaves(TreeNode* root);
	int countLeftLeavesSum(TreeNode* root);

	//LeetCode_513_FindBottomLeftTreeValue
	int findBottomLeftValue(TreeNode* root);
	void findBottomLeftValue(TreeNode* root, int& maxDepth, int& leftVal, int depth);

	//LeetCode_671_SecondMinimunNodeInaBinaryTree
	int findSecondMinimumValue(TreeNode* root);
	void findSecondMinimumValue(TreeNode* root, vector<int>& q);
	int dfs_secondMinVal(TreeNode* p, int first);


	//LeetCode_617_MergeTwoBinaryTrees
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);

	//LeetCode_450_DeleteNodeinaBST
	TreeNode* deleteNode(TreeNode* root, int key);


	//LeetCode_116_PopulatingNextRightPointersInEachNode
	void connect(TreeLinkNode *root);
	void getLinkTreeIntoMap(TreeLinkNode* root, map<int, TreeLinkNode*> m);

	void connect_II(TreeLinkNode *root);
	
	// Encodes a tree to a single string.
	string serialize(TreeNode* root);

	void inorderDFS(TreeNode* root, string& order);

	TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue);
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data);


	//LeetCode_113_PathSumII
	vector<vector<int>> pathSum(TreeNode* root, int sum);
	void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths);


	//LeetCode_337_HouseRobberIII
	int rob(TreeNode* root);
	int tryRob(TreeNode* root, int& l, int& r);
private:
	int dfs(TreeNode* node, int& lup);
}*pBinaryTree;