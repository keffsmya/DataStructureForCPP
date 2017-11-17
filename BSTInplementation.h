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
	/*�任���*/

	/*�����е�BST���вü����޶�ֵ�ķ�Χ������ʣ�µĽڵ㣬��һ����ԭ���ĸ��ڵ㣬��Ϊ���ڵ�Ҳ���ܱ�ɾ��*/
	TreeNode* trimBST(TreeNode* root, int L, int R);

	void ConvertBSTtoAVLT(pTreeNode Root);


public:

	/*���Ǻ�LeetCode��صĲ���*/
	
	
	
	//LeetCode_687_ConvertBSTtoGreaterTree
	//��һ��BST����ÿһ����������ϱ����Ĵ�Ľڵ�����ٸ�ֵ��ȥ
	pTreeNode ConvertBSTtoGreaterTree(pTreeNode Root);
	TNElementType BST_to_GT_Sum = 0;


	///LeetCode_653_TwoSumIV-InputisaBST
	//�����BST���Ƿ������������������Ŀ��ֵ��ͬ
	bool TwoSum(pTreeNode root, int k);
	void TraverseInroderForTwoSum(TreeNode* root,vector<int>& vec);
	bool FindTargetInASortedArray(vector<int>& vec, int target);


	
};

class NMTreeOperation
{

};


