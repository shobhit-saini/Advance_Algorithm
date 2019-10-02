#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m, i, k;
	cout << "Enter the no. of variable:";
	cin >> m;
	int start[m];
	int end[m];
	int result[m];
	
	//Enter the start time and end time
	for(i = 0; i < m; i++)
	{
		cin >> start[i];
		cin >> end[i];
	}
	
	//Sort the start time and end time array
	sort(start, start + m);
	sort(end, end + m);
	
	i = 0; 
	int j = 0; 
	k = 0;
	
	/*Merge the two array into one array while merging remember one thing put one into new array
	when you take element from start array otherwise 0*/
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

	int var = 0, max = 0;
	
	//if any new value of var is encounter then increment max value
	for(i = 0; i < k; i++)
	{
	    if(result[i] == 1)
	    {
	        var++;
	        if(var > max)
	        {
	            max++;
	        }
	     }
	     else if(var > 0)
	                var--;
	}
	cout << max;
}

