// DataStructureForCPP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include <memory>
#include <vector>

#include "DataStructure.h"
#include "BSTInplementation.h"

using namespace std;

int main(void)
{
	//pBSTree MyTree = new BSTree(10);
	vector<pTreeNode> myvec;
	pTreeNode Root = new TreeNode(10);
	BSTreeOperation* BSTO_Ptr = new BSTreeOperation();
	int a = 0;

	
	for (int i = 0; i < 40; i++)
	{
		a = i;
		pTreeNode temp = BSTO_Ptr->insertNode(Root, a);
		myvec.push_back(temp);
		

	}


	system("pause");
	return 0;
}

