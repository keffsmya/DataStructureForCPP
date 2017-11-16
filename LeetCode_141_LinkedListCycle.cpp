#include "stdafx.h"
#include "LeetCode_141_LinkedListCycle.h"


bool LeetCode_141_LinkedListCycle::hasCycle(ListNode *head)
{

	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{
		
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast)
		{
			return true;
		}
	}
	return false;
}
