// FindkthMaxValueByHeap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

class Solution{
public:
	int findKthLargest(vector<int> &nums, int k) {
		priority_queue<int, vector<int>, greater<int>> Q;
		for (int i = 0; i < nums.size(); i++) {
			if (Q.size() < k)
				Q.push(nums[i]);
			else if (Q.top() < nums[i]) {
				Q.pop();
				Q.push(nums[i]);
			}
		}
		return Q.top();
	}
};


int main()
{
	vector<int> v{ 3,4,6,2,8,9,10 };
	int num = Solution().findKthLargest(v, 3);
	cout << num << endl;
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
