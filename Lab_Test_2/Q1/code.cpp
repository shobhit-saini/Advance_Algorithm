#include<iostream>
using namespace std;
int main()
{
	int n, i, j;
	cin >> n;
	int ar[n];
	int loc[n], k = 0, l;
/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////Loop for input and finding the location of 3 in the array//////////////////
//////////////////////////////////////////////////////////////////////////////////////////// 
	for(i = 0; i < n; i++)
	{
		cin >> ar[i];
////////////////////store all the location of 3 in location array//////////////////////////////
		if(ar[i] == 3)
		{
			loc[k++] = i;
		}
	}
	
/*	for(i = 0; i < k; i++)
	{
		cout << loc[i];
	}*/
	cout << "\n";
	 j = 1;
	int m = 0;
	for(l = 0; l < k; l++)
	{
		loc[l] += m ; 	
		j = 1;
		while(j != 3) ///While loop take care of 3 times rotation
		{
			for(i = n-1; i > loc[l] ; i--) // for loop take care of 1 times rotation
			{
				ar[i] = ar[i-1];
			}
			j++;
			
		}
	 m += 2; // imp.: because we did rotation the location of the element in location array changes
	}
	for(i = 0; i < n; i++)
	{
     		cout << ar[i] << "\t";
	}

}
