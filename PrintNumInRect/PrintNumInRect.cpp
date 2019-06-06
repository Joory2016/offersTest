// PrintNumInRect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>


using namespace std;



class Solution
{

public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		int rows = matrix.size();
		if (rows == 0)
			return res;
		int cols = matrix[0].size();
		int start = 0;
		while (cols > start * 2 && rows > start * 2)
		{
			printRing(matrix, res, start);
			++start;
		}
		return res;
	}

private:
	void printRing(const vector<vector<int> > &matrix, vector<int> &res, int start)
	{
		int rows = matrix.size();
		int cols = matrix[0].size();

		int endX = cols - 1 - start;
		int endY = rows - 1 - start;

		for (int i = start; i <= endX; i++)
			res.push_back(matrix[start][i]);

		if (start < endY)
		{
			for (int i = start + 1; i <= endY; i++)
				res.push_back(matrix[i][endX]);
		}

		if (start < endX && start < endY)
		{
			for (int i = endX - 1; i >= start; --i)
				res.push_back(matrix[endY][i]);
		}

		if (start < endX && start < endY - 1)
		{
			for (int i = endY - 1; i >= start + 1; --i)
				res.push_back(matrix[i][start]);
		}
	}

};

void makeRect(vector<vector<int>> & matrix)
{
	vector<int> v1{ 1,2,3 };
	vector<int> v2{ 5,6,7 };
	vector<int> v3{ 9,10,11 };
	vector<int> v4{ 13,14,15 };
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);
}

void printRect(vector<vector<int>> & matrix)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			cout << matrix[i][j] << " ";
	cout << endl;
}


void myprint(const vector<int> & res)
{
	for (vector<int>::const_iterator it = res.cbegin(); it != res.cend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



int main()
{
	vector<int> res;
	vector<vector<int>> matrix;
	makeRect(matrix);
	//printRect(matrix);
	Solution s;
	res = s.printMatrix(matrix);
	myprint(res);
    std::cout << "Hello World!\n"; 
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
