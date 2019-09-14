#include<iostream>
using namespace std;
int min(int a, int b, int c)
{
	if(a < b && a < c)
		return a;
		
	else if(b < c) 
		return b;
		
	else 
		return c;
}
int fun(int *ar, int N)
{
	if(N <= 0)
	{
		return 0;
	}
	else
	{
		return min(fun(ar, N - 1) + ar[N - 1], fun(ar , N - 2) + ar[N - 1], fun(ar, N - 2) + ar[N - 2]);
	}
}
int main()
{
	int N, i, result;
	cout << "Enter the no. of task:";
	cin >> N;
	
	cout << "Enter the execution time in minutes:";
	int ar[N];
	
	for(i = 0; i < N; i++)
	{
		cin >> ar[i];
	}
	result = fun(ar, N);
	cout<<result;
}
