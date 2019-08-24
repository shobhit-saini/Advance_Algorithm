#include<iostream>
using namespace std;
int Merge(int* ar, int low, int mid1, int mid2, int high)
{
	int i = low, j = mid1 + 1, k = mid2 + 1, l = 0;
	int temp[high-low+1];
	while (i <= mid1 && j <= mid2 && k <= high)
	{
		if(ar[i] <= ar[j] && ar[i] <= ar[k])
		{
			temp[l] = ar[i];
			k++;
			l++;
		}
		else if(ar[j] <= ar[i] && ar[j] <= ar[k])
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
	
	
	
	while(i <= mid1 && k <= mid2)
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
	while(i <= mid1)
	{
		temp[l] = ar[i];
		l++;
		i++;
	}
	while(k <= high)
	{
		temp[l] = ar[k];
		l++;
		k++;
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
int main()
{
	int N = 0, i = 0;
	cout<< "Enter the size of the array:";
	cin>> N;
	int ar[N];
	for( i = 0; i < N; i++)
	{
		cin>> ar[i];
	}
	Mergesort(ar, 0, N-1);
	cout<< "Sorted array is:";
	for(i = 0; i < N; i++)
	{
		cout<< ar[i]<<"\t";
	}
}
