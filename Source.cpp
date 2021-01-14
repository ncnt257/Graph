#include "Header.h"

Graph readGraphMF(string file_name)
{
	Graph gr;
	ifstream fin;
	fin.open(file_name, std::ifstream::in);
	int n;
	string lineinfo;
	getline(fin, lineinfo);
	n = stoi(lineinfo);
	int flag;
	for (int i = 0; i < n; i++)
	{
		gr.vlist.push_back(i);
		for (int j = 0; j < n; j++)
		{
			fin >> flag;
			if (flag == 1)
			{
				gr.adjlist[i].push_back(j);
			}
		}
	}
	fin.close();
	return gr;
}
Graph readGraphLF(string file_name)
{
	Graph gr;
	ifstream fin;
	fin.open(file_name, ifstream::in);
	string lineinfo;
	getline(fin, lineinfo);
	int n = stoi(lineinfo);
	for (int i = 0; i < n; i++)
	{
		gr.vlist.push_back(i);
		int m;
		fin >> m;
		for (int j = 0; j < m; j++)
		{
			int v;
			fin >> v;
			gr.adjlist[i].push_back(v);
		}
	}
	return gr;
}
bool checkDG(Graph gr)
{
	for (auto v : gr.vlist)
	{
		for (auto e : gr.adjlist[v])
		{
			

			if (find(gr.adjlist[e].begin(), gr.adjlist[e].end(), v) ==gr.adjlist[e].end())
			{
				return true;
			}
		}
	}
	return false;
}
int calcDeg(Graph gr, int vertex)
{
	if (checkDG(gr))
	{
		return NULL;
	}
	int flag = 0;
	//if (gr.adjlist[vertex].find(vertex) != gr.adjlist[vertex].end())
	if(find(gr.adjlist[vertex].begin(), gr.adjlist[vertex].end(), vertex) != gr.adjlist[vertex].end())
		flag = 1;
	return gr.adjlist[vertex].size()+flag;
}
int calcDegP(Graph gr, int vertex)
{
	if (!checkDG(gr))
	{
		return NULL;
	}
	int flag = 0;

	//if (gr.adjlist[vertex].find(vertex) != gr.adjlist[vertex].end())
	if(find(gr.adjlist[vertex].begin(), gr.adjlist[vertex].end(), vertex)!= gr.adjlist[vertex].end())
		flag = 1;
	return gr.adjlist[vertex].size() + flag;
}
int calcDegM(Graph gr, int vertex)
{
	if (!checkDG(gr))
	{
		return NULL;
	}
	int deg = 0;
	for (auto v : gr.vlist)
	{
		if (v == vertex && find(gr.adjlist[v].begin(), gr.adjlist[v].end(), vertex) != gr.adjlist[vertex].end())
		//if (v == vertex && gr.adjlist[v].find(vertex) != gr.adjlist[v].end())
		{
			deg += 2;
			continue;
		}

		//if (gr.adjlist[v].find(vertex) != gr.adjlist[v].end())
		if(find(gr.adjlist[v].begin(), gr.adjlist[v].end(), vertex) != gr.adjlist[v].end())
		{
			deg++;
		}
	}
	return deg;
}
bool checkSimpleGraph(Graph gr)
{
	for (auto v : gr.vlist)
	{
		if (find(gr.adjlist[v].begin(), gr.adjlist[v].end(),v) != gr.adjlist[v].end())
		{
			return false;
		}
		auto flag = unique(gr.adjlist[v].begin(), gr.adjlist[v].end());
		if (flag != gr.adjlist[v].end())
		{
			return false;
		}
	}
	return true;
}
bool checkCompleteGraph(Graph gr)//sai!!
{
	if (!checkSimpleGraph(gr))
	{
		return false;
	}
	int n = gr.vlist.size();
	int m = 0;
	for (auto v : gr.vlist)
	{
		m+= gr.adjlist[v].size();
	}
	if (!checkDG(gr))
	{
		if (m != 2* n * (n - 1) / 2)
		{
			return false;
		}
		return true;
	}
	if (m != n * (n - 1) / 2)
		return false;
	return true;
}
void DFS(Graph gr,int vertex, bool* visited)
{
	if (vertex >= gr.vlist.size()||visited[vertex]==true)
	{
		return;
	}
	visited[vertex] = true;
	cout << vertex << "  ";
	for (auto v : gr.adjlist[vertex])
	{
		DFS(gr, v, visited);
	}
}
void BFS(Graph gr, int vertex, bool* visited)
{
	deque<int> gq;
	gq.push_back(vertex);
	visited[vertex] = true;

	while (!gq.empty())
	{
		int x=gq.front();
		cout << x << "  ";
		gq.pop_front();
		for (auto v : gr.adjlist[x])
		{
			if (!visited[v] && find(gq.begin(), gq.end(), v) == gq.end())
			{
				visited[v] = true;
				gq.push_back(v);
			}
		}
	}

}
