#include<bits/stdc++.h>
using namespace std;
int addedge(vector<int>adj[], int u, int v)
{
	adj[u].push_back(v);
}
int printedge(vector<int>adj[], int V)
{
	int i;
	vector<int>::iterator itr;
	for(i = 0; i < V; i++)
	{
		cout << i;
		for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
		{
			cout << "->" << *itr;	
		}
		cout << "\n";
	}
}
int Topo_sort(vector<int>adj[], int visited[], int V, int T[], int s)
{
	static int counter = V-1;
	vector<int>:: iterator itr;
	visited[s] = 1;
	for(itr = adj[s].begin(); itr != adj[s].end(); itr++)
	{
		if(visited[*itr] != 1)
		{
			Topo_sort(adj, visited, V, T, *itr);
		}
	}
	T[counter--] = s; 
}
int main()
{
	int V, E, i, u, v;
	cout << "Enter the No. of vertex:";
	cin >> V;
	cout << "Enter the no. of edges:";
	cin >> E;
	vector<int>adj[V];
	int visited[V] = {0};
	int T[V] = {0};
	for(i = 0; i < E; i++)
	{
		cin >> u >> v;
		addedge(adj, u , v);
	}
	printedge(adj, V);
	Topo_sort(adj, visited, V, T, 0);
	cout << "Toposort:";
	for(i = 0; i < V; i++)
	{
		cout << T[i] << "\t";
	}
}
