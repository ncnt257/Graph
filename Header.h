#pragma once
#ifndef Header_h
#define Header_h
#include<iostream>
#include<fstream>
#include<string>
#include <deque>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;
struct Graph
{
	vector<int> vlist;//dinh
	map<int, vector<int>> adjlist;//danh sach ke cua dinh
};
Graph readGraphMF(string file_name);
Graph readGraphLF(string file_name);

bool checkDG(Graph gr);

int calcDeg(Graph gr, int vertex);

int calcDegP(Graph gr, int vertex);

int calcDegM(Graph gr, int vertex);

bool checkSimpleGraph(Graph gr);

bool checkCompleteGraph(Graph gr);

void DFS(Graph gr, int vertex, bool* visited);

void BFS(Graph gr, int vertex, bool* visited);




#endif // !Header_h
