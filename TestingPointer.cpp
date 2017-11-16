#include "stdafx.h"
#include <iostream>
#include "TestingPointer.h"
#include "DataStructure.h"
using namespace std;
void TestingPointer::Test()
{
	ListNode* Node = new ListNode(10);
	ListNode* ptr2 = Node;

	cout << "Node这个指针的值为：" << Node << "\n";
	cout << "ptr2这个指针的值为：" << ptr2 << "\n";
	cout << "对Node这个指针取地址的值为：" << &Node << "\n";
	cout << "对ptr2这个指针取地址的值为：" << &ptr2 << "\n";
	cout << "Node这个指针再取值的值为：" << Node << "\n";
	cout << "ptr2这个指针再取值的值为：" << ptr2 << "\n";
}