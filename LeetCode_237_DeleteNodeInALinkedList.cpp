#include "stdafx.h"
#include "LeetCode_237_DeleteNodeInALinkedList.h"


void LeetCode_237_DeleteNodeInALinkedList::deleteNode(ListNode* Node)
{
	//将Node->next 的内容取出来赋给Node
	*Node = *Node->next;
	//方便理解就是这个指针的地址换成下一个节点指针的地址
}