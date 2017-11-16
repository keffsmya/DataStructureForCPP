#include "stdafx.h"
#include "DataStructure.h"
#include <vector>
#include <algorithm>
#include "LeetCode_23_MergeKSortedList.h"
using namespace std;

struct CompareListNode
{
	bool operator()(const ListNode* p, const ListNode*q) const
	{
		return p->val > q->val;
	}
};


ListNode* LeetCode_23_MergeKSortedList::mergeKLists(vector<ListNode*>& lists)
{
	//ListNode head(-1);
	////建立一个链表来存引用
	//vector<ListNode*> vec_helper;

	//for (int i = 0; i < (int)lists.size(); i++)
	//{
	//	if (lists[i] != NULL)
	//	{
	//		vec_helper.push_back(lists[i]);
	//	}
	//}

	//make_heap(vec_helper.begin(), vec_helper.end(), CompareListNode());
	//ListNode* pTail = &head;

	//while (vec_helper.size > 0)
	//{
	//	//获取vec_helper的第一Element的引用
	//	ListNode* pNode = vec_helper.front();
	//	//然后把pTail的next指针指向刚才的引用
	//	pTail->next = pNode;
	//	//然后让pTail引用到刚才的引用
	//	pTail = pTail->next;
	//	make_heap(vec_helper.begin(), vec_helper.end(), CompareListNode());
	//	vec_helper.pop_back();
	//	if (pNode->next)
	//	{
	//		vec_helper.push_back(pNode->next);
	//		push_heap(vec_helper.begin(), vec_helper.end(), CompareListNode());
	//	}
	//}
	return NULL;
}


