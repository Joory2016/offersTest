﻿// Leet147_insertSortLink.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};
class Solution {

public:

	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* dummyHead = new ListNode(head->val);
		dummyHead->next = head;
		ListNode* curr = head->next;
		while (curr != nullptr && curr->next != nullptr) {
			ListNode* pre = dummyHead;
			ListNode* temp = pre->next;
			while (temp->val < curr->val) {
				pre = pre->next;
				temp = pre->next;
				if (temp == curr) {
					curr = curr->next;
					continue;
				}
			}
			pre->next = curr;
			ListNode* pNext = curr->next;
			curr->next = temp;
			while (temp != curr) {
				temp = temp->next;
			}
			temp->next = pNext;
			curr = pNext;
		}
		return dummyHead->next;
	}
};

int main()
{
	ListNode *head = new ListNode(4);
	ListNode *p1 = new ListNode(2);
	ListNode *p2 = new ListNode(1);
	ListNode *p3 = new ListNode(3);
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	ListNode *temp = Solution().insertionSortList(head);

    std::cout << "Hello World!\n"; 
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
