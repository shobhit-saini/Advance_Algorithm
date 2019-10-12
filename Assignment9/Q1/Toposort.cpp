#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<bits/stdc++.h> 
using namespace std;
int addedge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	//adj[v].push_back(u);
}

int DFT(vector<int> adj[], int s, bool visited[], int T[], int V)
{
	static int counter = V-1;
		visited[s] = 1;
		vector<int> :: iterator itr;
		for(itr = adj[s].begin(); itr != adj[s].end(); itr++)
		{
			if(visited[*itr] != 1)
			{
				DFT(adj, *itr, visited, T, V);
			}
		}
		T[counter--] = s;
}
int main()
{
	int v, u, V, ch, i, s;
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

	////////////////DFT///////////////////////////////
	cout << "Enter the starting point:";
	cin >> s;
	int T[V] = {0};
	bool visited[V];
	for(i = 0; i < V; i++)
	{
		visited[i] = 0;
	}

	DFT(adj, s, visited, T, V);
	cout << "Toposort is:";
	for(i = 0; i < V; i++)
	{
		cout << T[i] <<"\t";
	}
}
