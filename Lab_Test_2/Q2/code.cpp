#include<iostream>
using namespace std;
int rows,columns;
int fun(int *a[], int i, int j)
{
	
	if(j == columns - 1 && i == 0)
		return 1;

	if(a[i][j] == 1)
		return fun(a, i, j+1) + fun(a, i-1, j);

	else
		return 0;
}
int main()
{
	cout << "Enter the no. rows:";
	cin >> rows;
	cout << "Enter the no. column:";
	cin >> columns;

	int *arr[rows];

	for(int i = 0; i < rows; i++)
	{
		arr[i] =new int[columns];
	}
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout << arr[i][j]<<"\t";
		}
		cout << "\n";
	}
	int n = fun(arr, rows - 1, 0);
	cout<<"Number of paths possible:"<<n;
}
