#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int i, j, k, l, t = 64;
	for(i = 1; i < N; i++)
	{
		
		for(j = 1; j <= i; j++)
		{
			cout << char(t+j)<< " ";
		}
		for(k = 1; k <= 2*(N-i)-1; k++)
		{
			cout << "  ";
		}
		for(l = j-1; l>=1; l--)
		{
			cout << char(t+l)<<" ";
		}
		cout << "\n";
	}
	if(i == N)
	{
		for(j = 1; j <= N ; j++)
		{
			cout << char(t+j) << " ";
		}
		
		for(l = j-2; l>=1; l--)
		{
			cout << char(t+l) << " ";
		}
	}
}
