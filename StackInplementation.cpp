#include "stdafx.h"
#include "DataStructure.h"
#include<stdio.h>
#include<stdlib.h>
#include "malloc.h"
using namespace std;


class StackInplementation
{
	//使用typedef给自定义的链表设置别名，方便使用
	typedef struct Node
	{
		int data;
		struct Node* pNext;
	}NODE,*PNODE,*PNode,*pnode;
	///LINKEDLIST用来减小识别问题
	///*PNODE用来方便指针使用,在Node前面添加一个p表示是指针


	typedef struct Stack
	{
		PNODE pTop;
		pnode pBottom;
	}STACK,*pStack,*PSTACK;


	void initStack(PSTACK pStack)    //对栈进行初始化的函数
	{
		//创建一个空结点，让pTop指向它
		pStack->pTop = (PNODE)malloc(sizeof(NODE));
		if (NULL != pStack->pTop)
		{
			//将pBottom也指向空节点
			pStack->pBottom = pStack->pTop;
			//清空空结点的指针域
			pStack->pTop->pNext = NULL;
		}
		else      //如果内存分配失败
		{
			printf("内存分配失败!程序退出!\n");
			exit(-1);
		}
		return;
	}


	void pushStack(PSTACK pStack, int val)  //入栈的函数
	{
		PNode pNew = (PNode)malloc(sizeof(Node));
		pNew->data = val;
		pNew->pNext = pStack->pTop;
		pStack->pTop = pNew;
		return;
	}

	bool popStack(PSTACK pStack, int * pVal)//出栈的函数，*pVal用来保存出栈的元素内容
	{
		if (pStack->pTop==pStack->pBottom)
		{
			return false;
		}

		PNode rNode = pStack->pTop;
		*pVal = pStack->pTop->data;
		pStack->pTop = pStack->pTop->pNext;
		free(rNode);
		rNode = NULL;
		return true;

	}

		
	void traverseStack(PSTACK pStack)   //遍历栈的函数
	{
		PNode tNode = pStack->pTop;

		while (tNode != pStack->pBottom)
		{
			//DoSomething
			tNode->data;
			//DoSomething
			tNode = tNode->pNext;
		}
		return;
	}


	void clearStack(PSTACK pStack)
	{
		if (pStack->pTop == pStack->pBottom)
		{
			return;
		}

		PNode cNode1 = pStack->pTop;
		PNode cNode2 = NULL;
		while (cNode1 == pStack->pBottom)
		{
			cNode2 = cNode1->pNext;
			free(cNode1);
			cNode1 = cNode2;
		}

		//单纯的便利完成还不行，还需要指针两个头指针指向同一个节点
		pStack->pTop = pStack->pBottom;
		return;
	}

};