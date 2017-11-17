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
	if ((Root->value)>val)
	{
		if (Root->LeftChild)
		{
			
			insertNode(Root->LeftChild, val);
		}
		else
		{
			pTreeNode newNodeL = new TreeNode(val);
			Root->LeftChild = newNodeL;
			Root->LeftChild->Father = Root;
			//cout << "创建了个新的左树节点，" << "键值为：" << " " << val << "  父节点是 ：" << Root << endl;
			return newNodeL;

		}
	}
	else if (val > Root->value)
	{
		if (Root->RightChild)
		{
			insertNode(Root->RightChild, val);
		}
		else
		{
			pTreeNode newNodeR = new TreeNode(val);
			Root->RightChild = newNodeR;
			Root->RightChild->Father = Root;
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
	d = CalculateTheNodeDepth(Root->LeftChild, node);
	if (d > 0) return d + 1;
	d = CalculateTheNodeDepth(Root->RightChild, node);
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

	cout <<" "<< Root->value << " "<<endl;

	/*******************/
	
	if (Root->LeftChild)
	{
		TraverseBSTreePreorder(Root->LeftChild);
	}
	
	if (Root->RightChild)
	{
		TraverseBSTreePreorder(Root->RightChild);
	}
	
}

void BSTreeOperation::TraverseBSTreeInorder(pTreeNode Root)
{
	

	if (Root->LeftChild)
	{
		TraverseBSTreePreorder(Root->LeftChild);
	}
	/*中序遍历所做的操作*/

	cout <<""<< Root->value <<""<< endl;

	/*******************/
	if (Root->RightChild)
	{
		TraverseBSTreePreorder(Root->RightChild);
	}
}

void BSTreeOperation::TraverseBSTreePostorder(pTreeNode Root)
{
	if (Root->LeftChild)
	{
		TraverseBSTreePostorder(Root->LeftChild);
	}
	if (Root->RightChild)
	{
		TraverseBSTreePostorder(Root->RightChild);
	}
	/*后序遍历所做的操作*/

	cout << "" << Root->value << "" << endl;

	/*******************/
}

///这个是适用于包括普通二叉树和BST，都可以达到效果
pTreeNode BSTreeOperation::ConvertBSTtoGreaterTree(pTreeNode Root)
{
	if (!Root) return Root;
	if (Root->RightChild)	ConvertBSTtoGreaterTree(Root->RightChild);
		
	BSTreeOperation::BST_to_GT_Sum += Root->value;
	cout << "此节点从 " << Root->value << " 变成 " << BSTreeOperation::BST_to_GT_Sum << endl;
	Root->value = BSTreeOperation::BST_to_GT_Sum;

	if(Root->LeftChild)  ConvertBSTtoGreaterTree(Root->LeftChild);
	
	return Root;
}


TreeNode* BSTreeOperation::trimBST(TreeNode* root, int L, int R)
{
	if (!root) return NULL;

	if (root->value > R) return trimBST(root->LeftChild, L, R);
	if (root->value < L) return trimBST(root->RightChild, L, R);
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
	 TraverseInroderForTwoSum(root->LeftChild,vec);
	vec.push_back(root->value);
	 TraverseInroderForTwoSum(root->RightChild,vec);
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
	RootPtr->value = 10;
}