// FindMedianFromDataStream.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;


class MedianFinder
{
public:
	MedianFinder()
	{
	}

	void addNum(int num)
	{
		if (max_heap.empty())
		{
			max_heap.push(num);
			return;
		}
		if (max_heap.size() == min_heap.size())
		{
			if (num < max_heap.top())
				max_heap.push(num);
			else
			{
				min_heap.push(num);
			}
		}
		else if (max_heap.size() > min_heap.size())
		{
			if (num > max_heap.top())
				min_heap.push(num);
			else
			{
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(num);
			}
		}
		else if (max_heap.size() < min_heap.size())
		{
			if (num < min_heap.top())
				max_heap.push(num);
			else
			{
				max_heap.push(min_heap.top());
				min_heap.pop();
				min_heap.push(num);
			}
		}
	}

	double findMedian()
	{
		double res = 0;
		if (max_heap.size() == min_heap.size())
			res = (max_heap.top() + min_heap.top()) / 2.0;
		else if (min_heap.size() > max_heap.size())
			res = min_heap.top();
		else
			res = max_heap.top();
		return res;
	}
private:
	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>> max_heap;
};



int main()
{
	MedianFinder M;
	M.addNum(3);
	M.addNum(4);
	M.addNum(1);
	M.addNum(2);
	M.addNum(7);

	double res = M.findMedian();
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
