#include "Header.h"

int main()
{
    Graph graph;
    graph=readGraphMF("graph1.txt");
    for (auto v : graph.vlist)
    {
        cout << "Dinh: " << v << endl;
        cout << "Ke dinh: ";
        for (auto e : graph.adjlist[v])
        {
            cout << e<<"  ";
        }
        cout << endl<< endl;
    }
    /*for (auto v : graph.vlist)
    {
        cout << "Bac trong cua dinh " << v << " la: " << calcDegM(graph, v);
        cout << endl;
        cout << "Bac ngoai cua dinh " << v << " la: " << calcDegP(graph, v);
        cout << endl;
        cout << endl;
    }*/
    int V = graph.vlist.size();
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    BFS(graph, 0, visited);
}