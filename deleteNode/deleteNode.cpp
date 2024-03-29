// deleteNode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;



class solution {

private:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int v) :val(v), next(nullptr) {}
	};
	ListNode* pHead=nullptr;
	ListNode* currNode = nullptr;

public:
	ListNode *deleteDuplication() {
		if (pHead == nullptr)
			return nullptr;
		ListNode* preNode = nullptr;
		ListNode* pNode = pHead;
		while (pNode != nullptr) {
			bool deleteNode = false;
			ListNode* pNext = pNode->next;
			if (pNext != nullptr && pNode->val == pNext->val)
				deleteNode = true;
			if (!deleteNode) {
				preNode = pNode;
				pNode = pNode->next;
			}
			else {
				int value = pNode->val;
				ListNode* pToDelete = pNode;
				while (pToDelete != nullptr && pToDelete->val == value) {
					pNext = pToDelete->next;
					delete pToDelete;
//					pToDelete = nullptr;
					pToDelete = pNext;
				}
				if (preNode == nullptr)
					pHead = pNext;
				else
					preNode->next = pNext;
				pNode = pNext;
			}
		}
		return pHead;
	}

	void addNode(int val) {
		if (pHead == nullptr) {
			pHead = new ListNode(val);
			currNode = pHead;
		}
		else {
			currNode->next = new ListNode(val);
			currNode = currNode->next;
		}
	}


	void printListNode() {
		ListNode *temp = pHead;
		while (temp != nullptr) {
			cout << temp->val << endl;
			temp = temp->next;
		}
	}
};




int main()
{
	solution s;
	int size = sizeof(s);
	cout << "the size of s is " << size << endl;
	cout << "---------------" << endl;

	s.addNode(1);
	s.addNode(2);
	s.addNode(2);
	s.addNode(5);
	s.addNode(6);
	s.addNode(7);
	s.printListNode();
	s.deleteDuplication();
	cout << "------------------" << endl;
	s.printListNode();
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
