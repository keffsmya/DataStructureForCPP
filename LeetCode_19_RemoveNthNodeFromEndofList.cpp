#include "stdafx.h"
#include "LeetCode_19_RemoveNthNodeFromEndofList.h"
#include "DataStructure.h"

using namespace std;
///what a elegant code

///�������β����ʼ��
ListNode* LeetCode_19_RemoveNthNodeFromEndofList::removeNthFromEnd(ListNode* head, int n)
{
	///������һ��ֻ��head��ַ��ָ���ָ�룬����ɾ�������ͺܷ���
	//ListNode* t1_1 = head;
	//ListNode** t2_2 = &t1_1;

	ListNode** t1 = &head, *t2 = head;
	

	///ʹ�����t2���α굽��Nλ
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