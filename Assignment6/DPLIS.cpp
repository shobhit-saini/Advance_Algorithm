#include<iostream>
using namespace std;
int main()
{
	int N, i, j, max;
	cout << "Enter the size of sequence:";
	cin >> N;
	int ar[N], br[N];
	for(i = 0; i < N; i++)
	{
		cin >> ar[i];
	}
	for(i = 0; i < N; i++)
	{
		br[i] = 1;
	}
	for(i = 1; i < N; i ++)
	{
		for(j = 0; j < i; j++)
		{
			if(ar[i] > ar[j])
			{
				br[i] = (br[j] + 1 > br[i]) ? br[j] + 1 : br[i];
			}
		}
	}
	max = br[0];
	for(i = 0; i < N; i++)
	{
		max = max < br[i] ? br[i] : max;
	}
	cout << max;
}
