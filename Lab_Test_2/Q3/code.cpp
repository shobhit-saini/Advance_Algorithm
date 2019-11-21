#include<bits/stdc++.h>
using namespace std;
int addedge(vector<int>adj[], int u, int v)
{
	adj[u].push_back(v);
}
int DFT(vector<int>adj[], int s, int visited[])
{
	visited[s] = 1;
	vector<int>:: iterator itr;
	for(itr = adj[s].begin(); itr != adj[s].end(); itr++)
	{
		if(visited[*itr] != 1)
		{
			DFT(adj, *itr, visited);
		}
	}
}
int main()
{
	int V, E, U, u, v, i, s;

	cout << "Enter the no. of vertices:";
	cin >> V;

	vector<int> adj[V+1];
	cout << "Enter the no. of Edges:";
	cin >> E;

	for(i = 0; i < E; i++)
	{
		cin >> u >> v;
		addedge(adj, u, v);
	}

	int visited[V+1];
	for(i = 0; i <= V; i++)
	{
		visited[i] = 0;
	}

	cout << "Enter the size of set U:";
	cin >> U;

	for(i = 0; i < U; i++)
	{
		cin >> s;
		DFT(adj, s, visited);
	}


	for(i = 0; i <= V; i++)
	{
		if(visited[i] == 1)
		{
			cout << i << "\t";
		}
	}
}
