#include<iostream>
using namespace std;
struct activity
{
	int start_time;
	int finish_time;
};
int Merge(struct activity *arr, int low, int mid, int high)
{
	activity temp [high - low + 1] ;
	int i = low, j = mid + 1, k = 0;
	while(i <= mid && j <= high)
	{
		if(arr[i].finish_time <= arr[j].finish_time)
		{
			temp[k] = arr[i];
			k++; i++; 
		}
		else 
		{
			temp[k] = arr[j];
			k++; j++;
		}
	}
	while(i <= mid)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}
	while(j <= high)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	for(i = low; i <= high; i++)
	{
		arr[i] = temp[i - low];
	}
}
int Mergesort(struct activity *arr, int low, int high)
{
	int mid = (low + high)/2;
	if(low < high)
	{
		Mergesort(arr, low, mid);
		Mergesort(arr, mid+1, high);
		Merge(arr, low, mid, high);
	}

}
int main()
{
	int n, i;
	cout << "Enter the no. of activity:";
	cin >> n;
	struct activity arr[n];
	for(i = 0; i < n; i++)
	{
		cin >> arr[i].start_time;
		cin >> arr[i].finish_time;
	}
	Mergesort(arr, 0, n-1);
	cout << "After the sorting:";
	for(i = 0; i < n; i++)
	{
		cout << arr[i].start_time << "/" << arr[i].finish_time << "\n";
	}
}
