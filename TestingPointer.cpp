#include "stdafx.h"
#include <iostream>
#include "TestingPointer.h"
#include "DataStructure.h"
using namespace std;
void TestingPointer::Test()
{
	ListNode* Node = new ListNode(10);
	ListNode* ptr2 = Node;

	cout << "Node���ָ���ֵΪ��" << Node << "\n";
	cout << "ptr2���ָ���ֵΪ��" << ptr2 << "\n";
	cout << "��Node���ָ��ȡ��ַ��ֵΪ��" << &Node << "\n";
	cout << "��ptr2���ָ��ȡ��ַ��ֵΪ��" << &ptr2 << "\n";
	cout << "Node���ָ����ȡֵ��ֵΪ��" << Node << "\n";
	cout << "ptr2���ָ����ȡֵ��ֵΪ��" << ptr2 << "\n";
}