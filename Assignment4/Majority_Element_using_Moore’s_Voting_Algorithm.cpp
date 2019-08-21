int main()
	{
		int N = 0,temp = 0, count = 1, i = 0;
		//////////////////////INPUT///////////////////////////////////////
		cout<<"Enter the size of an array:";
		cin>>N;
		int* ar = new int[N];
		for(i = 0; i <N; i++)
		{
			cin>>ar[i];
		}
		int majority_index = 0;
		for(i = 1; i<N; i++)
		{
			if(ar[i] == ar[i-1])
			{
				count++;
			}
			else
			{
				count--;
			}
			if(count == 0)
			{
				majority_index = i;
				count = 1;
			}
			
		}
		for(i = 0; i < N; i++)
		{
			if(ar[majority_index] == ar[i])
			{
				temp++;
			}
		}
		if(temp > (N/2))
		{
			cout<<"Majority element exists:"<<ar[majority_index];
		}
		else
		{
			cout<<"Majority element doesnot exists";
		}
	}
