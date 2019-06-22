// minArrowBurstBallons.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyCompare{
public:
	bool operator()(vector<int> a,vector<int> b) {
		return a[0] < b[0];
	}
};

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.size() == 0)
			return 0;
		sort(points.begin(), points.end(), MyCompare());
		
		int shootNum = 1;
		int shoot_begin = points[0][0];
		int shoot_end = points[0][1];

		for (int i = 1; i < points.size(); i++)
		{
			if (points[i][0] < shoot_end)
			{
				shoot_begin = points[i][0];
				if (shoot_end > points[i][1])
					shoot_end = points[i][1];
			}
			else {
				shootNum++;
				shoot_begin = points[i][0];
				shoot_end = points[i][1];
			}
		}
		return shootNum;
	}
};

int main()
{
	vector<int> b1{ 10,16 };
	vector<int> b2{ 2,8 };
	vector<int> b3{ 1,6 };
	vector<int> b4{ 7,12 };
	vector<vector<int>> point{ b1,b2,b3,b4 };

	int res = Solution().findMinArrowShots(point);
	cout << res << endl;
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
