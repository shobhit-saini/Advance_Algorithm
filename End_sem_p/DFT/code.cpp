#include<bits/stdc++.h>
using namespace std;
int addedge(vector<int>adj[], int u, int v)
{
	adj[u].push_back(v);	
}
int printgraph(vector<int>adj[], int V)
{
	int i;
	vector<int>::iterator itr;
	for(i = 0; i < V; i++)
	{
		cout << i ;
		for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
		{
			cout << "->" << *itr;
		}
		cout << "\n";
	}
}
int DFT(vector<int>adj[], int s, int V, int visited[])
{
	vector<int>:: iterator itr;
		cout << "\t" << s;
		visited[s] = 1;
	for(itr = adj[s].begin(); itr != adj[s].end(); itr++)
	{
		if(visited[*itr] != 1)
		{
			DFT(adj, *itr, V, visited);
		}
	}
}
int main()
{
	int V, E, i, s;
	cout << "Enter the no. of vertices:";
	cin >> V;
	vector<int>adj[V];
	cout << "Enter the no. of Edges:";
	cin >> E;
	int u, v;
	int visited[V] = {0};
	for( i = 0; i < E; i++)
	{
		cin >> u >> v;
		addedge(adj, u, v);	
	}
	printgraph(adj, V);	
	
	cout << "Depth first traversal is:";
	for(i = 0; i < V; i++)
	{	
		if(visited[i] != 1)
		{
			DFT(adj, i, V, visited);
		}
	}
}
