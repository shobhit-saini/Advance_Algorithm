#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////Q1//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

void Q1(int N)
{
int i = 0, j = 0, count = 65, l = 0, k = 0;

	if(N <= 3)
	{
		
		if(N = 2)
		{
			l = 1;
		}
		
		else
		{
			l = (1+ (N-1)*2);
		}
		
	}

	if(N > 3)
	{
		l = (1+ (N+1)*2) + 2*(N-5);
	}
	
	for(i = 1; i <= N; i++)
	{
		count = 65;
		
		for(j = 1; j <= i; j++)
		{
			cout<<char(count)<<" ";
			count++;
		}
		
		count--;
		
		for(k = 1; k <= l; k++)
		{
			cout<<" ";
		}
		
		if(i == N)
		{
		count--;
		j = 2;
		}
		
			else
			{
			j = 1;
			}
			
		if(i != N)
		{
			cout<<" ";
		}
		
		for(; j <= i; j++)
		{
			cout<<char(count)<< " ";
			count--;
		}
		
		cout<< "\n";
		l = l-4;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////Q2//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

void Q2(int N)
{
	int br[N], k, i;
	
	for(i = 0; i < N; i++)
	{
		br[i] = i+1;
	}
	
	for(i = 1; i <= N; i++)
	{
		cout<< i;
	}
	
	cout<<"\n";
	k = 2;
	
	while(k!=N+1)
	{
		
		for( i =N-(k-1); i < N; i++)
		{
			cout<<br[i];
		}
		
		for( i = 0; i<N-(k-1); i++ )
		{
			cout<<br[i];
		}
		
	cout<<"\n";
	k++;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////Q3- 3-way merge sort//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

int Merge(int* ar, int low, int mid1, int mid2, int high)
{
	int i = low, j = mid1 + 1, k = mid2 + 1, l = 0;
	int temp[high-low+1];
	while (i <= mid1 && j <= mid2 && k <= high)
	{
		if(ar[i] <= ar[j] && ar[i] <= ar[k])
		{
			temp[l] = ar[i];
			i++;
			l++;
		}
			else if(ar[j] <= ar[k])
			{
				temp[l] = ar[j];
				l++;
				j++;
			}
				else
				{
					temp[l] = ar[k];
					l++;
					k++;
				}
	}
	while(i <= mid1 && j <= mid2)
	{
		if(ar[i] <= ar[j])
		{
			temp[l] = ar[i];
			l++;
			i++;
		}
			else 
			{
				temp[l] = ar[j];
				l++;
				j++;
			}
	}
	
	while(i <= mid1 && k <= high)
	{
		if(ar[i] <= ar[k])
		{
			temp[l] = ar[i];
			l++;
			i++;
		}
			else 
			{
				temp[l] = ar[k];
				l++;
				k++;
			}
	}
	
	while(j <= mid2 && k <= high)
	{
		if(ar[j] <= ar[k])
		{
			temp[l] = ar[j];
			l++;
			j++;
		}
			else 
			{
				temp[l] = ar[k];
				l++;
				k++;
			}
	}
	
	while(i <= mid1)
	{
		temp[l] = ar[i];
		l++;
		i++;
	}
	
	while(j <= mid2)
	{
		temp[l] = ar[j];
		l++;
		j++;
	}

	while(k <= high)
	{
		temp[l] = ar[k];
		l++;
		k++;
	}
	
	for(i = low; i <= high; i++)
	{
		ar[i] = temp[i-low];
	}
}

int Mergesort(int* ar, int low, int high)
{
	int mid1 = 0, mid2 = 0;
	
	if(low < high)
	{
		mid1 = low + (high - low)/2;
		mid2 = low + 2*(high - low)/2;
		Mergesort(ar, low, mid1);
		Mergesort(ar, mid1 + 1, mid2);
		Mergesort(ar, mid2 + 1, high);
		Merge(ar, low, mid1, mid2, high);
	}
}

void Q3(int N)
{
	int ar[N];
	
	for(int i = 0; i < N; i++)
	{
		cin>>ar[i];
	}
	
	Mergesort(ar, 0, N-1);
	
	cout<< "Sorted array is:";
	
	for(i = 0; i < N; i++)
	{
		cout<< ar[i]<<"\t";
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////Main()//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int N = 0;
	cin>> N;
	Q1(N);
	Q2(N);
	Q3(N);
}
