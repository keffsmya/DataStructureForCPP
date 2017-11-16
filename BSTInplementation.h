#pragma once
#include <vector>
#include <string>
#include <memory>
#include "stdafx.h"
#include "DataStructure.h"

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

	/*这是和LeetCode相关的操作*/
	pTreeNode ConvertBSTtoGreaterTree(pTreeNode Root);
	TNElementType BST_to_GT_Sum = 0;

};

class NMTreeOperation
{

};


