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
	TNElementType value;
	TreeNode* LeftChild;
	TreeNode* RightChild;
	TreeNode* Father;

public:
	TreeNode()
	{
		value = 0;
		LeftChild= RightChild = Father = NULL;
	}
	TreeNode(TNElementType val)
	{
		value = val;
		LeftChild = RightChild = Father = NULL;
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