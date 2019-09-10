#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i, j, k, N;
	cout << "Enter the amount:";
	cin >> N;
	cout << "Enter the no. of denomination:";
	cin >> k;
	cout << "Enter the denomination:";
	int D[k];
	int T[N+1];
	for(i = 0; i < k; i++)
	{
		cin >> D[i];
	}
	T[0] = 0;
	for(i = 1; i <= N; i++)
	{
		T[i] = INT_MAX;
	}
	
	for(i = 1; i <= N; i++)
	{
		for(j = 0; j < k; j++)
		{
			if(((i - D[j]) >= 0) && T[i - D[j]] + 1 < T[i])
			{
				T[i] = T[i - D[j]] + 1;
			} 
		}
	}
	cout << T[N];
}
