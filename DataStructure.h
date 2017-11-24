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

typedef struct TreeLinkNode 
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
}*pTreeLinkNode;



typedef class BSTree
{
public:
	BSTree();
	BSTree(TNElementType val);
	bool isEmpty();
	pTreeNode RootPtr;
}*pBSTree;



