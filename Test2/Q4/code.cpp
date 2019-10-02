#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int *Merge(int* start, int* end, int m)
{
	int result[m];
	int i = 0, j = 0, k = 0;
	while(i < m && j < m)
	{
		if(start[i] <= end[j])
		{
			result[k] = 1;
			i++;
			k++;
		}
		else
		{
			result[k] = 0;
			j++;
			k++;
		}
	}
	while(i < m)
	{
		result[k] = 1;
		i++;
		k++;
	}
	while(j < m)
	{
		result[k] = 0;
		j++;
		k++;
	}
	for(int i = 0; i < m; i++)
	{
		cout << result[i];
	}
	return result;
}
int main()
{
	int m, i, k;
	cout << "Enter the no. of variable:";
	cin >> m;
	int start[m];
	int end[m];
	int result[m];
	for(i = 0; i < m; i++)
	{
		cin >> start[i];
		cin >> end[i];
	}
	sort(start, start + m);
	sort(end, end + m);
	i = 0; 
	int j = 0; 
	k = 0;
	while(i < m && j < m)
	{
		if(start[i] <= end[j])
		{
			result[k] = 1;
			i++;
			k++;
		}
		else
		{
			result[k] = 0;
			j++;
			k++;
		}
	}
	while(i < m)
	{
		result[k] = 1;
		i++;
		k++;
	}
	while(j < m)
	{
		result[k] = 0;
		j++;
		k++;
	}
	/*result = Merge(start, end, m);*/
	int var = 0;
	for(i = 0; i < k; i++)
	{
	   
	    /*if(result[i] == 1)
	        var++;
	            else if(var > 0)
	                var--;*/
	}
	cout << var;
}
