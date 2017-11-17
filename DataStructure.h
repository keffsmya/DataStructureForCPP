#pragma once
//������ڵ�
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) 
	{
		val = x;
		next = nullptr;
	}
};


//BST���ڵ㣨˫����ڵ㣩
typedef int TNElementType;
typedef struct TreeNode
{
public:
	TNElementType val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* father;

public:
	TreeNode()
	{
		val = 0;
		left = right = father = NULL;
	}
	TreeNode(TNElementType value)
	{
		val = value;
		left = right = father = NULL;
	}
}*pTreeNode;


typedef class BSTree
{
public:
	BSTree();
	BSTree(TNElementType val);
	bool isEmpty();
	pTreeNode RootPtr;
}*pBSTree;