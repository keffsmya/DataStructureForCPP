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
	//����ֵС�ڸ��ڵ�ֵ�������
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
			//cout << "�����˸��µ������ڵ㣬" << "��ֵΪ��" << " " << val << "  ���ڵ��� ��" << Root << endl;
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
			//cout << "�����˸��µ������ڵ㣬" << "��ֵΪ��" << " " << val << "  ���ڵ��� ��" << Root << endl;
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
	/*ǰ����������Ĳ���*/

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
	/*������������Ĳ���*/

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
	/*������������Ĳ���*/

	cout << "" << Root->val << "" << endl;

	/*******************/
}

///����������ڰ�����ͨ��������BST�������ԴﵽЧ��
pTreeNode BSTreeOperation::ConvertBSTtoGreaterTree(pTreeNode Root)
{
	if (!Root) return Root;
	if (Root->right)	ConvertBSTtoGreaterTree(Root->right);
		
	BSTreeOperation::BST_to_GT_Sum += Root->val;
	cout << "�˽ڵ�� " << Root->val << " ��� " << BSTreeOperation::BST_to_GT_Sum << endl;
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


#pragma region BSTreeOperation����LeetCode��ص�BST_TwoSum
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