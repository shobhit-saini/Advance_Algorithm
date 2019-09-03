#include<iostream>
#include<math.h>
using namespace std;

struct Huffman
{
	char data;
	int frequency;
	struct Huffman *left;
	struct Huffman *right;
};

int Swap(struct Huffman *a, struct Huffman *b)
{
	struct Huffman temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//Building the Heap 
int Build_heap(struct Huffman *ar, int high)
{
	int  temp = 0, i = 0, j = 0;
	
	//For loop from second last level
		for(i = floor(high/2) - 1; i >= 0; i--)
		{
			j = i;
			
			//Heapify from Top
			while(j <= floor(high/2) - 1)
			{
				if((2*j +2 < high))
				{
					if((ar[j].frequency > ar[2*j + 1].frequency) || (ar[j].frequency > ar[2*j + 2].frequency))
					{
						if((ar[2*j + 1].frequency < ar[2*j + 2].frequency))
						{
							Swap(&ar[j], &ar[2*j + 1]);
							j = 2*j + 1;
						}
						else
						{
							Swap(&ar[j], &ar[2*j + 2]);
							j = 2*j + 2;
						}
					}
					
					else
					{
						break;
					}
						
				}
				else if(ar[j].frequency > ar[2*j + 1].frequency)
				{
					Swap(&ar[j], &ar[2*j + 1]);
						j = 2*j + 1;
				}
				else
				{
					break;
				}
			}
		}
	
return 0;
}

int Extract_min(struct Huffman *ar, int high)
{

	int i = 0;
	Swap(&ar[0], &ar[high - 1]);
	
	high = high - 1;
	
	while(i <= floor(high/2) - 1)
			{
				if((2*i +2 < high))
				{
					if((ar[i].frequency > ar[2*i + 1].frequency) || (ar[i].frequency > ar[2*i + 2].frequency))
					{
						if((ar[2*i + 1].frequency < ar[2*i + 2].frequency))
						{
							Swap(&ar[i], &ar[2*i + 1]);
							i = 2*i + 1;
						}
						else
						{
							Swap(&ar[i], &ar[2*i + 2]);
							i = 2*i + 2;
						}
					}
					
					else
					{
						break;
					}
						
				}
				else if(ar[i].frequency > ar[2*i + 1].frequency)
				{
					Swap(&ar[i], &ar[2*i + 1]);
					i = 2*i + 1;
				}
				else
				{
					break;
				}
			}
return high;
}

int Insert(struct Huffman *ar, int N)
{
	int i = N - 1 ;
	while(i >= 0)
	{
		if(ar[i].frequency < ar[(i-1)/2].frequency)
		{
			Swap(&ar[i], &ar[(i-1)/2]);
			i = (i-1)/2;
		}
		else
		{
			break;
		}
	}	
}
	
int main()
{
	int i = 0, N = 0;
	cout << "Enter the number of characters:\n";
	cin >> N;
	struct Huffman ar[2*N];
	cout << "Enter the character and it's frequency:";
	for(i = 0; i < N; i++)
	{
		cin >> ar[i].data;
		cin >> ar[i].frequency;
		ar[i].left = NULL;
		ar[i].right = NULL;
	}	
	
	Build_heap(ar, N);
	
	for(i = 0; i < N; i++)
	{
		cout <<  ar[i].data << "\t";
		cout << ar[i].frequency << "\t";
		cout << ar[i].left << "\t";
		cout << ar[i].right << "\n";
	}
	
	int temp = N, total;
	struct Huffman Min1, Min2;
	int j = 1;
	while(j <= temp - 1)
	{
		Min1 = ar[0];
		cout << Min1.frequency << "\n";
		N = Extract_min(ar, N);

		cout << "First";
		for(i = 0; i < N; i++)
		{
			cout <<  ar[i].data << "\t";
			cout << ar[i].frequency << "\n";
		}
		Min2 = ar[0];
		cout << Min2.frequency << "\n";
		N = Extract_min(ar, N);
		cout<<"Second";
		for(i = 0; i < N; i++)
		{
			cout <<  ar[i].data << "\t";
			cout << ar[i].frequency << "\n";
		}	
		ar[N].frequency = Min1.frequency + Min2.frequency;
		ar[N].data = '\0';
		ar[N].left = &Min1;
		ar[N].right = &Min2;
		N++;
		cout<< "N" <<N;
		Insert(ar, N);
		cout << "After insertion:\n"; 	
		for(i = 0; i < N; i++)
		{
		cout <<  ar[i].data << "\t";
		cout << ar[i].frequency << "\n";
		}
		cout << j;
		j++;
	}
		cout << "After the Huffman algo.:\n";
			cout <<  ar[0].data << "\t";
			cout << ar[0].frequency << "\n";
	
	cout<< (ar[0].right)->frequency ;//<< "\t" <<ar->left->data;
	
}
