// Leet189_RotateArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k > nums.size())
			k = k % nums.size();
		int len = nums.size();
		for (int i = 0; i < k; i++) {
			int temp = nums[len - 1];
			for (int j = nums.size() - 1; j > 0; j--)
				nums[j] = nums[j - 1];
			nums[0] = temp;
		}
	}


	void rotate2(vector<int>& nums, int k) {
		if (k > nums.size())
			k = k % nums.size();
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.size() - 1);
	}

private:
	void reverse(vector<int>& nums, int l, int r) {
		while (l < r) {
			int temp = nums[l];
			nums[l] = nums[r];
			nums[r] = temp;
			l++;
			r--;
		}
	}

public:

	void readFromtest(string filePath,vector<int>& nums,int &k) {
		ifstream infile;
		infile.open(filePath);
		string buff;
		getline(infile, buff);
		
		// string->char *
		char *s_input = (char *)buff.c_str();
		const char * split = ",";
		// 以‘，’为分隔符拆分字符串
		char *p = strtok(s_input, split);
		int a;
		while (p != NULL) {
			// char * -> int
			a = atoi(p);
			//cout << a << endl;
			nums.push_back(a);
			p = strtok(NULL, split);
		}//end while
		string kbuff;
		getline(infile, kbuff);
		k = atoi(kbuff.c_str());
		infile.close();
	}

};





int main()
{
	Solution test;
	vector<int> nums;
	int k;
	string filePath = "E:\\ZhaoRui\\testCase\\RotateArray.txt";
	test.readFromtest(filePath, nums, k);

	clock_t startTime = clock();
	test.rotate2(nums, k);
	clock_t endTime = clock();
	cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << endl;

	startTime = clock();
	test.rotate(nums, k);
	endTime = clock();
	cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << endl;


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
