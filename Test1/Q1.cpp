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
