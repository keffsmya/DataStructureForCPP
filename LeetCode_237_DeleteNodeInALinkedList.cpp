#include "stdafx.h"
#include "LeetCode_237_DeleteNodeInALinkedList.h"


void LeetCode_237_DeleteNodeInALinkedList::deleteNode(ListNode* Node)
{
	//��Node->next ������ȡ��������Node
	*Node = *Node->next;
	//�������������ָ��ĵ�ַ������һ���ڵ�ָ��ĵ�ַ
}