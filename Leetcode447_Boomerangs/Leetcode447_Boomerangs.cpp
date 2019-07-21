// Leetcode447_Boomerangs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int res = 0;
		for (int i = 0; i < points.size(); i++) {
			unordered_map<int, int> record;
			for (int j = 0; j < points.size(); j++) {
				if (j != i)
					record[dis(points[i], points[j])]++;
			}
			for (unordered_map<int, int>::iterator it = record.begin();
				it != record.end(); it++) {
				if (it->second >= 2)
					res += (it->second)*(it->second - 1);
			}
		}
		return res;
	}
private:
	int dis(vector<int>& p1, vector<int>& p2) {
		return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
	}
};



int main()
{
	vector<int> a1{ 0,0 };
	vector<int> a2{ 1,0 };
	vector<int> a3{ 2,0 };

	vector<vector<int>> points{ a1,a2,a3 };
	int res=Solution().numberOfBoomerangs(points);
	map<int, int> M;
	M.insert(make_pair(2, 1));
	M.insert(make_pair(5, 2));
	M.insert(make_pair(8, 3));
	M.insert(make_pair(1, 4));
	for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
		cout << "[" << it->first << "," << it->second <<"]"<< endl;
	}

	cout << "--------------------------" << endl;
	unordered_map<int, int> uM;
	uM.insert(make_pair(2, 1));
	uM.insert(make_pair(5, 2));
	uM.insert(make_pair(8, 3));
	uM.insert(make_pair(1, 4));

	for (auto it : uM) {
		cout << "[" << it.first << "," << it.second <<"]"<< endl;
	}

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
