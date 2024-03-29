// MergeSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
#include <ctime>

using namespace std;


class MergeSortC {
public:
	void mergeSort(vector<int>& vec) {
		if (vec.size() < 2)
			return;
		int mid = vec.size() / 2;
		vector<int> subVec1;
		vector<int> subVec2;
		for (int i = 0; i < mid; i++)
			subVec1.push_back(vec[i]);
		for (int i = mid; i < vec.size(); i++)
			subVec2.push_back(vec[i]);
		mergeSort(subVec1);
		mergeSort(subVec2);
		vec.clear();
		mergeSortTwoVec(subVec1, subVec2, vec);
	}

private:
	void mergeSortTwoVec(vector<int>& subVec1, vector<int>& subVec2, vector<int>& resVec) {
		int len1 = subVec1.size();
		int len2 = subVec2.size();
		int i = 0, j = 0;
		while( i < len1&&j < len2) {
			if (subVec1[i] <= subVec2[j]) {
				resVec.push_back(subVec1[i]);
				i++;
			}
			else {
				resVec.push_back(subVec2[j]);
				j++;
			}
		}
		for (; i < len1; i++)
			resVec.push_back(subVec1[i]);
		for (; j < len2; j++)
			resVec.push_back(subVec2[j]);
	}

};


int main()
{
	vector<int> a;
	vector<int> b;

	srand(time(NULL));

	for (int i = 0; i < 100000; i++) {
		int num = (rand()*rand()) % 1000003;
		a.push_back(num);
		b.push_back(num);
	}
	MergeSortC().mergeSort(a);

	sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++) {
		assert(a[i] == b[i]);
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
