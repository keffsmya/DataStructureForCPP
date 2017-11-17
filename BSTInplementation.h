#pragma once
#include <vector>
#include <string>
#include <memory>
#include <set>
#include "stdafx.h"
#include "DataStructure.h"

using namespace std;
class BSTreeOperation
{
public:
	pTreeNode insertNode(pTreeNode Root, TNElementType &val);
	void deleteNode(pTreeNode Root, TNElementType &val);
	pTreeNode searchNode(pTreeNode Root, TNElementType &val);
	int CalculateTheNodeDepth(pTreeNode Root, pTreeNode node);
public:
	void TraverseBSTreePreorder(pTreeNode Root);
	void TraverseBSTreeInorder(pTreeNode Root);
	void TraverseBSTreePostorder(pTreeNode Root);

public:
	/*变换相关*/

	/*对现有的BST进行裁剪，限定值的范围，返回剩下的节点，不一定是原来的根节点，以为根节点也可能被删掉*/
	TreeNode* trimBST(TreeNode* root, int L, int R);

	void ConvertBSTtoAVLT(pTreeNode Root);


public:

	/*这是和LeetCode相关的操作*/
	
	
	
	//LeetCode_687_ConvertBSTtoGreaterTree
	//将一个BST树中每一个点的数加上比他的大的节点的数再赋值回去
	pTreeNode ConvertBSTtoGreaterTree(pTreeNode Root);
	TNElementType BST_to_GT_Sum = 0;


	///LeetCode_653_TwoSumIV-InputisaBST
	//看这个BST中是否存在两个数加起来和目标值相同
	bool TwoSum(pTreeNode root, int k);
	void TraverseInroderForTwoSum(TreeNode* root,vector<int>& vec);
	bool FindTargetInASortedArray(vector<int>& vec, int target);


	
};

class NMTreeOperation
{

};


