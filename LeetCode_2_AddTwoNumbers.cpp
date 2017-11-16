#include "LeetCode_2_AddTwoNumbers.h"
#include "stdafx.h"
#include "DataStructure.h"

//You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8

//ListNode* LeetCode_2_AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//
//	ListNode* newHead = new ListNode(0);
//	ListNode* p1 = l1;
//	ListNode* p2 = l2;
//	ListNode* Current = newHead; int shift = 0;
//	while (p1||p2)
//	{
//		int x = (p1) ? p1->val : 0;
//		int y = (p2) ? p2->val : 0;
//		int sum = x + y+shift;
//		shift = (sum) / 10;
//
//		Current->next = new ListNode(sum%10);
//		
//		p1 = p1->next ? p1->next : nullptr;
//		p2 = p2->next ? p2->next : nullptr;
//		Current = Current->next;
//
//	}
//
//	return newHead->next;
//}
