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
	////����һ��������������
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
	//	//��ȡvec_helper�ĵ�һElement������
	//	ListNode* pNode = vec_helper.front();
	//	//Ȼ���pTail��nextָ��ָ��ղŵ�����
	//	pTail->next = pNode;
	//	//Ȼ����pTail���õ��ղŵ�����
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


