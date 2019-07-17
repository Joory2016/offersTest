// Leetcode209_minSubArrayLen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>&nums) {
		int l = 0, r = -1;	//滑动窗口的区间[l,r]
		int sum = 0;
		int res = nums.size() + 1;
		while (l < nums.size()) {
			if (r+1<nums.size() && sum < s) {
				sum += nums[++r];
			}
			else
				sum -= nums[l++];
			if (sum >= s)
				res = min(res, r - l + 1);
		}
		if (res == nums.size() + 1)
			return 0;
		return res;
	}
};




int main()
{
	vector<int> s{ 2,3,1,2,4,3 };
	int res=Solution().minSubArrayLen(7, s);


    std::cout << "Hello World!\n"; 
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
