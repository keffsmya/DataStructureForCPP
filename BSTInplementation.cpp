#include <vector>
#include <string>
#include <memory>
#include "stdafx.h"
#include "DataStructure.h"
#include "BSTInplementation.h"
#include <iostream>
#include <map>

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
			//cout << "�����˸��µ������ڵ㣬" << "��ֵΪ��" << " " << val << "  ���ڵ��� ��" << Root << endl;
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
	/*ǰ����������Ĳ���*/

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
	

	if (Root->LeftChild != NULL)
	{
		TraverseBSTreePreorder(Root->LeftChild);
	}
	/*������������Ĳ���*/

	cout <<""<< Root->value <<""<< endl;

	/*******************/
	if (Root->RightChild != NULL)
	{
		TraverseBSTreePreorder(Root->RightChild);
	}
}

void BSTreeOperation::TraverseBSTreePostorder(pTreeNode Root)
{
	if (Root->LeftChild != NULL)
	{
		TraverseBSTreePostorder(Root->LeftChild);
	}
	if (Root->RightChild != NULL)
	{
		TraverseBSTreePostorder(Root->RightChild);
	}
	/*������������Ĳ���*/

	cout << "" << Root->value << "" << endl;

	/*******************/
}


pTreeNode BSTreeOperation::ConvertBSTtoGreaterTree(pTreeNode Root)
{
	if (Root)
	{
		ConvertBSTtoGreaterTree(Root->RightChild);
		BSTreeOperation::BST_to_GT_Sum += Root->value;
		//cout << "�˽ڵ�� " << Root->value << " ��� " << BSTreeOperation::BST_to_GT_Sum << endl;
		Root->value = BSTreeOperation::BST_to_GT_Sum;
		
		ConvertBSTtoGreaterTree(Root->LeftChild);
	}
	return Root;
}

BSTree::BSTree(TNElementType val)
{
	RootPtr = (pTreeNode)malloc(sizeof(TreeNode));
	RootPtr->value = 10;
}