#include "stdafx.h"
#include "DataStructure.h"
#include<stdio.h>
#include<stdlib.h>
#include "malloc.h"
using namespace std;


class StackInplementation
{
	//ʹ��typedef���Զ�����������ñ���������ʹ��
	typedef struct Node
	{
		int data;
		struct Node* pNext;
	}NODE,*PNODE,*PNode,*pnode;
	///LINKEDLIST������Сʶ������
	///*PNODE��������ָ��ʹ��,��Nodeǰ�����һ��p��ʾ��ָ��


	typedef struct Stack
	{
		PNODE pTop;
		pnode pBottom;
	}STACK,*pStack,*PSTACK;


	void initStack(PSTACK pStack)    //��ջ���г�ʼ���ĺ���
	{
		//����һ���ս�㣬��pTopָ����
		pStack->pTop = (PNODE)malloc(sizeof(NODE));
		if (NULL != pStack->pTop)
		{
			//��pBottomҲָ��սڵ�
			pStack->pBottom = pStack->pTop;
			//��տս���ָ����
			pStack->pTop->pNext = NULL;
		}
		else      //����ڴ����ʧ��
		{
			printf("�ڴ����ʧ��!�����˳�!\n");
			exit(-1);
		}
		return;
	}


	void pushStack(PSTACK pStack, int val)  //��ջ�ĺ���
	{
		PNode pNew = (PNode)malloc(sizeof(Node));
		pNew->data = val;
		pNew->pNext = pStack->pTop;
		pStack->pTop = pNew;
		return;
	}

	bool popStack(PSTACK pStack, int * pVal)//��ջ�ĺ�����*pVal���������ջ��Ԫ������
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

		
	void traverseStack(PSTACK pStack)   //����ջ�ĺ���
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

		//�����ı�����ɻ����У�����Ҫָ������ͷָ��ָ��ͬһ���ڵ�
		pStack->pTop = pStack->pBottom;
		return;
	}

};