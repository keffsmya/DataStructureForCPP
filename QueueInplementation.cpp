#include "stdafx.h"
#include "DataStructure.h"
#include<stdio.h>
#include<stdlib.h>
#include "malloc.h"
using namespace std;

//�Զ��еĵ�����ʵ��
//����˳���ͷ��β��pHead--------->pHead->pNext------->pTail


class QueueInplementation
{
	//ʹ��typedef���Զ�����������ñ���������ʹ��
	typedef struct Node
	{
		int data;
		struct Node* pNext;
	}NODE, *PNODE, *PNode, *pnode,*pNode;
	///LINKEDLIST������Сʶ������
	///*PNODE��������ָ��ʹ��,��Nodeǰ�����һ��p��ʾ��ָ��

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
		else      //����ڴ����ʧ��
		{
			printf("�ڴ����ʧ��!�����˳�!\n");
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
		//ȡ������������ʲô
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
			//�����Ψһ�Ľڵ�����ʲô

			//
			return;
		}

		pNode tNode = pQueue->pHead;
	

		while (tNode != pQueue->pHead)
		{
			//�Ե�ǰ��tNode���в���
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

		//�������Ҫһ�ν��׺�β��һ�Ĳ���
		pQueue->pHead = pQueue->pTail;
		return;
	}
};