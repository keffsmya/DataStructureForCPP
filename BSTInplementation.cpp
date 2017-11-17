#include <vector>
#include <string>
#include <memory>
#include "stdafx.h"
#include "DataStructure.h"
#include "BSTInplementation.h"
#include <iostream>
#include <map>
#include <set>

using namespace std;


bool BSTree::isEmpty()
{
	return RootPtr == NULL;
}


pTreeNode BSTreeOperation::insertNode(pTreeNode Root, TNElementType &val)
{
	
	if (!Root)
	{
		return NULL;
	}
	//这是值小于根节点值的情况下
	if ((Root->val)>val)
	{
		if (Root->left)
		{
			
			insertNode(Root->left, val);
		}
		else
		{
			pTreeNode newNodeL = new TreeNode(val);
			Root->left = newNodeL;
			Root->left->father = Root;
			//cout << "创建了个新的左树节点，" << "键值为：" << " " << val << "  父节点是 ：" << Root << endl;
			return newNodeL;

		}
	}
	else if (val > Root->val)
	{
		if (Root->right)
		{
			insertNode(Root->right, val);
		}
		else
		{
			pTreeNode newNodeR = new TreeNode(val);
			Root->right = newNodeR;
			Root->right->father = Root;
			//cout << "创建了个新的右树节点，" << "键值为：" << " " << val << "  父节点是 ：" << Root << endl;
			return newNodeR;
		}
	}
	


}


int BSTreeOperation::CalculateTheNodeDepth(pTreeNode Root,pTreeNode node)
{
	
	if (Root) return 0;

	if (Root == node) return 1;

	int d;
	d = CalculateTheNodeDepth(Root->left, node);
	if (d > 0) return d + 1;
	d = CalculateTheNodeDepth(Root->right, node);
	if (d > 0) return d + 1;

	return 0;
}

void BSTreeOperation::TraverseBSTreePreorder(pTreeNode Root)
{
	if (!Root)
	{
		return;
	}
	/*前序遍历所做的操作*/

	cout <<" "<< Root->val << " "<<endl;

	/*******************/
	
	if (Root->left)
	{
		TraverseBSTreePreorder(Root->left);
	}
	
	if (Root->right)
	{
		TraverseBSTreePreorder(Root->right);
	}
	
}

void BSTreeOperation::TraverseBSTreeInorder(pTreeNode Root)
{
	

	if (Root->left)
	{
		TraverseBSTreePreorder(Root->left);
	}
	/*中序遍历所做的操作*/

	cout <<""<< Root->val <<""<< endl;

	/*******************/
	if (Root->right)
	{
		TraverseBSTreePreorder(Root->right);
	}
}

void BSTreeOperation::TraverseBSTreePostorder(pTreeNode Root)
{
	if (Root->left)
	{
		TraverseBSTreePostorder(Root->left);
	}
	if (Root->right)
	{
		TraverseBSTreePostorder(Root->right);
	}
	/*后序遍历所做的操作*/

	cout << "" << Root->val << "" << endl;

	/*******************/
}

///这个是适用于包括普通二叉树和BST，都可以达到效果
pTreeNode BSTreeOperation::ConvertBSTtoGreaterTree(pTreeNode Root)
{
	if (!Root) return Root;
	if (Root->right)	ConvertBSTtoGreaterTree(Root->right);
		
	BSTreeOperation::BST_to_GT_Sum += Root->val;
	cout << "此节点从 " << Root->val << " 变成 " << BSTreeOperation::BST_to_GT_Sum << endl;
	Root->val = BSTreeOperation::BST_to_GT_Sum;

	if(Root->left)  ConvertBSTtoGreaterTree(Root->left);
	
	return Root;
}


TreeNode* BSTreeOperation::trimBST(TreeNode* root, int L, int R)
{
	if (!root) return NULL;

	if (root->val > R) return trimBST(root->left, L, R);
	if (root->val < L) return trimBST(root->right, L, R);
}


#pragma region BSTreeOperation中与LeetCode相关的BST_TwoSum
bool BSTreeOperation::TwoSum(pTreeNode root, int k)
{
	vector<int> nums;
	TraverseInroderForTwoSum(root, nums);
	return FindTargetInASortedArray(nums, k);
	
}

void BSTreeOperation::TraverseInroderForTwoSum(TreeNode* root, vector<int>& vec)
{
	if (!root) return;
	 TraverseInroderForTwoSum(root->left,vec);
	vec.push_back(root->val);
	 TraverseInroderForTwoSum(root->right,vec);
}

bool BSTreeOperation::FindTargetInASortedArray(vector<int>& vec, int target)
{
	for (int i = 0, j = (int)vec.size()-1; i < j;)
	{
		int sum = vec[i] + vec[j];
		if (target == sum) return true;
		if (target > sum) i++;
		else j--;
	}

	return false;
}
#pragma endregion






BSTree::BSTree(TNElementType val)
{
	RootPtr = (pTreeNode)malloc(sizeof(TreeNode));
	RootPtr->val = val;
}