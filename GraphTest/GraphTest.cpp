// GraphTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

template <class T>
struct GraphNode {
	int label;
	T data;
	vector<GraphNode *> neighbors;
	GraphNode(int x): label(x){ }
	GraphNode(int x,T temp):label(x){
		data = temp;
	}
};

template <class T>
void DFS_graph(GraphNode<T>* node, int visit[]) {
	visit[node->label] = 1;
	cout << node->label << "(" << node->data << ")" << "; ";
	for (int i = 0; i < node->neighbors.size(); i++) {
		if (visit[node->neighbors[i]->label] == 0) {
			DFS_graph(node->neighbors[i], visit);
		}
	}
}

template <class T>
void BFS_Graph(GraphNode<T>* node, int visit[]) {
	queue<GraphNode<T> *> Q;
	Q.push(node);
	visit[node->label] = 1;
	while (!Q.empty()) {
		GraphNode<T>* node = Q.front();
		Q.pop();
		cout << node->label << "(" << node->data << ")" << "; ";
		for (int i = 0; i < node->neighbors.size(); i++) {
			if (visit[node->neighbors[i]->label] == 0) {
				Q.push(node->neighbors[i]);
				visit[node->neighbors[i]->label] = 1;
			}
		}
	}
}


int main()
{
	const int MAX_N = 5;
	GraphNode<string> *Graph[MAX_N];
	for (int i = 0; i < MAX_N; i++) {
		string temp{ "data"+ to_string(i)};
		Graph[i] = new GraphNode<string>(i,temp);
	}
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[3]);
	int visit[MAX_N] = { 0 };
	for (int i = 0; i < MAX_N; i++) {
		if (visit[i] == 0) {
			cout << "From Lable<" << Graph[i]->label << "> :";
			DFS_graph(Graph[i], visit);
			cout << endl;
		}
	}

	cout << "-----------------------" << endl;
	int visitB[MAX_N] = { 0 };
	for (int i = 0; i < MAX_N; i++) {
		if (visitB[i] == 0) {
			cout << "From Lable<" << Graph[i]->label << "> :";
			BFS_Graph(Graph[i], visitB);
			cout << endl;
		}
	}

	for (int i = 0; i < MAX_N; i++)
		delete Graph[i];
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
