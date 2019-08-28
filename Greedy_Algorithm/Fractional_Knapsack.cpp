#include<iostream>
using namespace std;

struct ks
{
	int weight;
	int value;
	float v_w_ratio;
};
int Merge(struct ks *arr, int low, int mid, int high)
	{
		int i,j,k=0;
		i=low;
		j=mid+1;
		struct ks temp[high-low+1];
		
		while(i<=mid && j<=high)
		{
			if(arr[i].v_w_ratio<=arr[j].v_w_ratio)
			{
				temp[k].v_w_ratio=arr[i].v_w_ratio;
				temp[k].value = arr[i].value;
				temp[k].weight = arr[i].weight;
				k++;
				i++;
			}
			else
			{
				temp[k].v_w_ratio=arr[j].v_w_ratio;
				temp[k].value = arr[j].value;
				temp[k].weight = arr[j].weight;
				k++;
				j++;
			}
		}
		while(i<=mid)
		{
			temp[k].v_w_ratio=arr[i].v_w_ratio;
			temp[k].value = arr[i].value;
			temp[k].weight = arr[i].weight;
			k++;
			i++;
		}
		while(j<=high)
		{
			temp[k].v_w_ratio=arr[j].v_w_ratio;
			temp[k].value = arr[j].value;
			temp[k].weight = arr[j].weight;
			k++;
			j++;
		}
		for(int i=low;i<=high;i++)
		{
			arr[i].v_w_ratio = temp[i-low].v_w_ratio;
			arr[i].value = temp[i-low].value;
			arr[i].weight = temp[i-low].weight;
		}
	}
	int Mergesort(struct ks *arr,int low,int high)
		{
			int mid;
			if(low<high)
			{
				mid=(low+high)/2;
				Mergesort(arr,low,mid);
				Mergesort(arr,mid+1,high);
				Merge(arr, low, mid, high);
			}	
		}
		
int main()
{
	int N = 0, i = 0, knapsack = 0;
	float x = 0.0, profit = 0.0;
	cout<<"Enter the no. of items";
	cin>> N;
	struct ks arr[N];
	
	for(i = 0; i < N; i++)
	{
		cin>> arr[i].weight >> arr[i].value; 
		arr[i].v_w_ratio = ((float)arr[i].value)/arr[i].weight;
	}
	cout<<"Enter the size of knapsack:";
	cin>> knapsack;
	Mergesort(arr, 0, N-1);
	for(i = N; i >=0 ; i--)
	{
		
		if((knapsack - arr[i].weight)> 0)
		{
			knapsack -= arr[i].weight; 
			profit += arr[i].value;	
			cout<<profit<<"\t";
		}
		else 
		{
			x = arr[i].weight/knapsack;
			profit += arr[i].value/x;
			break;	
		}
	}
	cout<< profit;
	
}
