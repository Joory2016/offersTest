// CombinationSumII40.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		vector<vector<int>> res;
		vector<int> temp;
		set<vector<int>> res_set;
		sort(candidates.begin(), candidates.end());
		compute(0, target, temp, candidates, res, res_set);
		return res;
	}

private:
	void compute(int start, int target, vector<int> &temp, vector<int> &candidates, vector<vector<int>> &res, set<vector<int>> &res_set) {
		int n = candidates.size();
		for (int i = start; i < n; i++) {
			if (target > 0) {
				temp.push_back(candidates[i]);
				compute(i + 1, target - candidates[i], temp, candidates, res, res_set);
				temp.pop_back();
			}
			else if (target < 0)
				return;
			else if (res_set.find(temp) == res_set.end()) {
				res.push_back(temp);
				res_set.insert(temp);
				return;
			}
		}
	}
};



int main()
{
	vector<vector<int>> res;
	vector<int> test{ 2,5,2,1,2 };
	res = Solution().combinationSum2(test, 5);

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
