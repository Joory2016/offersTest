// LeetCode125_isPalindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int r = s.length()-1;
		int l = 0;
		while (l < r) {
			if ((s[l] >= 'a'&& s[l] <= 'z') || (s[l] >= 'A'&& s[l] <= 'Z') || (s[l] >= '0'&& s[l] <= '9')) {
				if ((s[r] >= 'a'&& s[r] <= 'z') || (s[r] >= 'A'&& s[r] <= 'Z') || (s[r] >= '0'&& s[r] <= '9')) {
					if (toupper(s[l]) != toupper(s[r]))
						return false;
					else {
						l++;
						r--;
					}
				}
				else
					r--;
			}
			else
				l++;

		}
		return true;
	}
};




int main()
{
	string a = "A man, a plan, a canal: Panama";
	bool res=Solution().isPalindrome(a);


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
