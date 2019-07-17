// Leetcode438_ findAnagrams.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int freq[256] = {0};
		vector<int> res;
		for (int i = 0; i < p.size(); i++)
			freq[p[i]]++;
		int l = 0, r = -1 ;
		while (l < s.size()) {
			if (r+1 < s.size() && freq[s[r+1]]!=0) {
				r++;
				freq[s[r]]--;
			}
			else {
				freq[s[l]]++;
				l++;
			}
			if (r - l + 1 == p.size())
				res.push_back(l);
		}
		return res;
	}
};


int main()
{
	string s = "cbaebabacd";
	string p = "abc";
	vector<int> res = Solution().findAnagrams(s, p);

	map<int, char> test;
	test.insert(make_pair(2, 'A'));
	auto it = test.begin();


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
