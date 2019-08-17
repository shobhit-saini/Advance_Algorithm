#include<iostream>
#include<map>
#include<math.h>
using namespace std;
int main()
{
	int n,value=0,min=2147483647,index=0,k=0,x;
/*.........................Input..........................*/
	cout<<"Enter the size of an array:";
	cin>>n;
	int* ar=new int[n];
	int* br=new int[n];
	cout<<"Enter the elements:\n";
	for(int i=0; i<n; i++)
	{
		cin>>ar[i];
	}

/*Enter value of k and x for the k closest integers to x*/
	cout<<"Enter the value of x:";
	cin>>x;
	cout<<"Enter the value value of k:";
	cin>>k;
	
//Temporary array br for processing 
	for(int i=0; i<n; i++)
	{
		br[i]= abs(ar[i]-x);	
	}

	for(int i=0;i<k;i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(br[j] != -1)
			{
			    if(min >= br[j])
				{
					min = br[j];
					index = j;
				}
			}
		}	
		min=2,147,483,647;	
		br[index] = -1;		
		cout<<ar[index]<<"\n";		
	}
}
