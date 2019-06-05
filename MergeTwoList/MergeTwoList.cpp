// MergeTwoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(nullptr){}
};


class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		ListNode* res = nullptr;
		if (pHead1 == nullptr && pHead2 == nullptr)
			return nullptr;
		else if (pHead1 == nullptr && pHead2 != nullptr)
			return pHead2;
		else if (pHead1 != nullptr && pHead2 == nullptr)
			return pHead1;
		ListNode* tHead1 = pHead1;
		ListNode* tHead2 = pHead2;
		if (tHead1->val <= tHead2->val)
		{
			res = tHead1;
			tHead1 = tHead1->next;
		}
		else
		{
			res = tHead2;
			tHead2 = tHead2->next;
		}
		ListNode* temp = res;
		while (tHead1 != nullptr && tHead2 != nullptr)
		{
			ListNode* pToLink = nullptr;
			if (tHead1->val <= tHead2->val)
				pToLink = tHead1;
			else
				pToLink = tHead2;
			temp->next = pToLink;
			temp = temp->next;
			if (pToLink == tHead1)
				tHead1 = tHead1->next;
			else
				tHead2 = tHead2->next;
		}
		if (temp->next == nullptr && tHead2 != nullptr)
		{
			temp->next = tHead2;
		}
		else if (temp->next == nullptr && tHead1 != nullptr)
		{
			temp->next = tHead1;
		}
		return res;
	}

	void myPrint(ListNode* res) {
		ListNode* temp = res;
		while (temp != nullptr)
		{
			cout << temp->val << endl;
			temp = temp->next;
		}
	}
};

ListNode* addNode(ListNode** pHead, int v) {
	if (*pHead == nullptr)
		*pHead = new ListNode(v);
	else
	{
		ListNode* temp = *pHead;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new ListNode(v);
	}
	return *pHead;
}

int main()
{
	ListNode* l1=nullptr;
	addNode(&l1, 3);
	addNode(&l1, 5);
	addNode(&l1, 7);
	Solution s;
	ListNode* l2 = nullptr;
	addNode(&l2, 4);
	addNode(&l2, 6);
	addNode(&l2, 8);
	ListNode* res=s.Merge(l1, l2);

	s.myPrint(res);


    std::cout << "Hello World!\n"; 
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
