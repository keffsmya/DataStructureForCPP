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




#pragma region LeetCode_173_BinarySearchTreeIterator

/*Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

	Credits :
	Special thanks to @ts for adding this problem and creating all test cases.*/

//根据BST的特性，最小的数必定是树最左边的那个子节点，所以只需要便利所有的左子节点就行
//处于栈顶的那个就是想要的

BSTIterator::BSTIterator(TreeNode* root)
{
	find_next(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext()
{
	if (stk.empty()) return false;
	return true;
}

/** @return the next smallest number */
//再找到当前的最小数的情况下，就需要对接下来的树再进行一个遍历
//便利的对象分情况，第一种就是那个最小节点没有右子节点，在这种情况下，比她小的只有他的父节点，因为BST左<中<右
//第二种情况下，如果有右子节点的情况下，情况就不一定，所以需要将当前最小节点的右节点做为根节点进行一次遍历
//得到的最后一个就是下一次所需要的最小的（处于栈顶），至于为什么，因为【当前最小节点】和他的【父节点】的关系导致
//【当前最小节点】的右节点是要大于【当前最小节点】和小于他的最大右节点，同样的这个【右节点】的子节点也满足这个关系
//这种情况下还有两种分支，如果这个右节点是一个叶节点，那么最小的反而是这个右节点，这种情况下右节点也要加入到stack栈顶
//另外一种，
int BSTIterator::next()
{
	TreeNode* top = stk.top();
	stk.pop();
	if (top->right)
		find_next(top->right);
	return top->val;
}

void BSTIterator::find_next(TreeNode* root)
{
	TreeNode* p = root;
	while (p)
	{
		stk.push(p);
		p = p->left;
	}
}

#pragma endregion