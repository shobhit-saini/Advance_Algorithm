#include<iostream>
#include<vector>
#include<bits/stdc++.h> 
using namespace std;
int addedge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int v, u, V, ch, i;
	cout << "Enter the no. of vertices:";
	cin >> V;
	vector<int> adj[V];
	while(1)
	{
		cout << "Press 1: adding edge into the graph\nPress any other key to exit\n";
		cin >> ch;
		if(ch != 1)
		{
			break;
		}
		else
		{
			cin >> u >> v;
			addedge(adj, u, v);		
		}
	}
	
	/////////////////Printing of graph//////////////////////////////////
	cout << "Adjacency list of graph:\n";
	vector<int>:: iterator itr;
	for(i = 0; i < V; i++)
	{
		cout << i ;
		for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
		{
			cout << "->" << *itr ;
		}
		cout << "\n";
	}
	
	
}
