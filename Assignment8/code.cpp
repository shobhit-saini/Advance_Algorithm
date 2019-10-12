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
int counter = 1;
int DFT(vector<int> adj[], int s, bool visited[], int start[], int finish[], int parent[])
{
		visited[s] = 1;
		cout << s << "\t";
		start[s] = counter;
		counter++;	
		vector<int> :: iterator itr;
		for(itr = adj[s].begin(); itr != adj[s].end(); itr++)
		{
			if(visited[*itr] != 1)
			{
				parent[*itr] = s;
				DFT(adj, *itr, visited, start, finish, parent);
			
			}
		}
		finish[s] = counter;
		counter++;
		
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
	bool visited[V];
	for(i = 0; i < V; i++)
	{
		visited[i] = 0;
	}
	int start[V] = {0};
	int finish[V] = {0};
	int parent[V] = {0};
	DFT(adj, s, visited, start, finish, parent);
	cout << "\nStart/finish:";
	for(i = 0; i < V; i++)
	{
		cout << i << "->" << start[i] << "/" << finish[i] << "/" << parent[i] << "\n";
	}
	cout << "\n";
	for(i = 0; i < V; i++)
	{
		for(itr = adj[i].begin(); itr != adj[i].end(); itr++)
		{
			if(parent[*itr] == i && start[i] < start[*itr] && start[*itr] < finish[*itr] && finish[*itr] < finish[i])
			{
				cout << i << "->" << *itr << ":" <<"TREE EDGE\n";
			}
			else if(start[*itr] < start[i] && start[i] < finish[i] && finish[i] < finish[*itr])
			{
				cout << i << "->" << *itr << ":" <<"BACK EDGE\n";
			}
			else if(parent[*itr] != i && start[i] < start[*itr] && start[*itr] < finish[*itr] && finish[*itr] < finish[i])
			{
				cout << i << "->" << *itr << ":" <<"FORWARD EDGE\n";
			}
			else if(start[*itr] < finish[*itr] && finish[*itr] < start[i] && start[i] < finish[i])
			{
				cout << i << "->" << *itr << ":" <<"CROSS EDGE\n";
			}
		}
		cout << "\n";
	}
}
