#include<iostream>
#include<vector>
#include<list>
#include<bits/stdc++.h> 
using namespace std;
int addedge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int BFT(vector<int> adj[], int s, int V)
{
	bool visited[V];
	int i, x;
	for(i = 0; i < V; i++)
	{
		visited[i] = 0;
	}
	visited[s] = 1;
	list<int> queue;
	queue.push_back(s);
	while(!queue.empty())
	{
		x = queue.front();
		queue.pop_front();
		cout << x << "\t";
		vector<int> :: iterator itr;
		for(itr = adj[x].begin(); itr != adj[x].end(); itr++)
		{
			if(visited[*itr] != 1)
			{
				visited[*itr] = 1;
				queue.push_back(*itr);
			}
		}
	}
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

	////////////////BFT///////////////////////////////
	cout << "Enter the starting point:";
	cin >> s;
	BFT(adj, s, V);

	
}
