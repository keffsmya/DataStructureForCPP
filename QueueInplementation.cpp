#include "stdafx.h"
#include "DataStructure.h"
#include<stdio.h>
#include<stdlib.h>
#include "malloc.h"
using namespace std;

//对队列的单链表实现
//采用顺序从头到尾即pHead--------->pHead->pNext------->pTail


class QueueInplementation
{
	//使用typedef给自定义的链表设置别名，方便使用
	typedef struct Node
	{
		int data;
		struct Node* pNext;
	}NODE, *PNODE, *PNode, *pnode,*pNode;
	///LINKEDLIST用来减小识别问题
	///*PNODE用来方便指针使用,在Node前面添加一个p表示是指针

	typedef struct Queue
	{
		pNode pHead;
		PNode pTail;
	}*pQueue,*PQUEUE;


	void InitializeQueue(PQUEUE pQueue)
	{
		pNode node = (pNode)malloc(sizeof(Node));
		if (pQueue->pTail != NULL)
		{
			pQueue->pHead = pQueue->pTail;
			pQueue->pTail->pNext = NULL;
		}
		else      //如果内存分配失败
		{
			printf("内存分配失败!程序退出!\n");
			exit(-1);
		}
		return;
	}


	void Enqueue(PQUEUE pQueue, int* pval)
	{
		pNode enode = (pNode)malloc(sizeof(Node));
		enode->data = *pval;
		pQueue->pTail->pNext = enode;
		pQueue->pTail = enode;
		return;
	}


	bool PopQueue(PQUEUE pQueue,int* pval)
	{
		if (pQueue->pHead == pQueue->pTail)
		{
			return false;
		}

		pNode rnode = pQueue->pHead;
		//取出来后用来干什么
		*pval = rnode->data;
		//
		pQueue->pHead = rnode->pNext;
		free(rnode);
		rnode = NULL;
		return true;
	}

	void traverseQueue(PQUEUE pQueue)
	{
		if (pQueue->pHead == pQueue->pTail)
		{
			//对这个唯一的节点做点什么

			//
			return;
		}

		pNode tNode = pQueue->pHead;
	

		while (tNode != pQueue->pHead)
		{
			//对当前的tNode进行操作
			tNode->data;
			//
			tNode = tNode->pNext;
			

		}
		return;
	}



	void ClearQueue(PQUEUE pQueue)
	{
		if (pQueue->pHead == pQueue->pTail)
		{
			return;
		}

		pNode clearNode1 = pQueue->pHead;
		pNode clearNode2 = NULL;

		while (clearNode1 != pQueue->pTail)
		{
			clearNode2 = clearNode1->pNext;
			free(clearNode1);
			clearNode1 = clearNode2;
		}

		//最后还是需要一次将首和尾合一的操作
		pQueue->pHead = pQueue->pTail;
		return;
	}
};