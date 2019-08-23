
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
