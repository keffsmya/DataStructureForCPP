#include "stdafx.h"
#include "LeetCode_19_RemoveNthNodeFromEndofList.h"
#include "DataStructure.h"

using namespace std;
///what a elegant code

///从链表的尾部开始数
ListNode* LeetCode_19_RemoveNthNodeFromEndofList::removeNthFromEnd(ListNode* head, int n)
{
	///定义了一个只想head地址的指针的指针，这样删除起来就很方便
	//ListNode* t1_1 = head;
	//ListNode** t2_2 = &t1_1;

	ListNode** t1 = &head, *t2 = head;
	

	///使用这个t2当游标到第N位
	for (int i = 1; i < n; ++i)
	{
		t2 = t2->next;
	}
	while (t2->next != NULL)
	{
		t1 = &((*t1)->next);
		t2 = t2->next;
	}
	*t1 = (*t1)->next;
	return head;
	
}