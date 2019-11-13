#include<iostream>
using namespace std;
int main()
{
	int n, i;
	cout << "Enter the size of an array:";
	cin >> n;
	int ar[n];
	cout << "Enter the elements of an array:";
	for(i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	int curr_max = ar[0];
	int max_so_far = ar[0];
	for(i = 1; i < n; i++)
	{
		curr_max = (curr_max + ar[i] >  ar[i]) ? curr_max + ar[i] : ar[i];
		max_so_far = (max_so_far < curr_max) ? curr_max : max_so_far;
	}
	cout << "Maximum sum of contiguous subarray:" << max_so_far;
}
