#pragma once
//单链表节点
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


//BST树节点（双链表节点）
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