#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<conio.h>
using namespace std;

struct Huffman
{
	char data;
	int frequency;
	struct Huffman *left;
	struct Huffman *right;
};

string codearray[256];
int k = 0;

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

void codeformation(int ints[], int len, struct Huffman* node)  
{  
   /* int i; 
	string str1; 
    for (i = 0; i < len; i++)  
    {  
        str1.append(to_string(ints[i]));  
    }  
    codearray[int(node->data)] = str1;
    //codearray[k].code = ;
    k++; */
}  

void Pathstraversal(struct Huffman* node, string s)  
{  
    if (node == NULL)  
        return;  
      
    /* it's a leaf, so print the path that led to here */
    if (node->left == NULL && node->right == NULL)  
    {  
        codearray[int(node->data)] = s; 
    }  
    else
    {  
        /* otherwise try both subtrees */
        Pathstraversal(node->left, s + '0');  
        Pathstraversal(node->right, s + '1');  
    }  
}  

void printInorder(struct Huffman* node) 
{ 
    if (node == NULL) 
        return; 
 /// cout << "hi";
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->frequency << " "; 
    //getch();
  
    /* now recur on right child */
    printInorder(node->right); 
    
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
	
	int j = 1;
	
	////////////////Making of Huffman Tree//////////////////////
	while(j <= temp - 1)
	{
	    //////////////Extraction of first minimum/////////////////
	    struct Huffman*	Min1 = new Huffman;
	    *Min1 = ar[0];
	    cout <<"add" <<&Min1;
		cout <<"Min1:" << Min1->frequency << "\n";
		N = Extract_min(ar, N);
		cout << "Heap After the Extract min:\n";
    		for(i = 0; i < N; i++)
    		{
    			cout <<  ar[i].data << "\t";
    			cout << ar[i].frequency << "\n";
    		}
    		
		//////////////Extraction of second minimum/////////////////
        struct Huffman*	Min2 = new Huffman;
	    *Min2 = ar[0];
		cout << "Min2:" << Min2->frequency << "\n";
		N = Extract_min(ar, N);
		cout << "Heap After the Extract min:\n";
    		for(i = 0; i < N; i++)
    		{
    			cout <<  ar[i].data << "\t";
    			cout << ar[i].frequency << "\n";
    		}	
		cout <<"n:"<<N;
		/////////////Making the new node///////////////////
		ar[N].frequency = Min1->frequency + Min2->frequency;
		ar[N].data = '\0';
		ar[N].left = Min1;
		ar[N].right = Min2;
		N++;
		cout<<"N:"<<N;
		///////////Insert the new node into tree/////////
		Insert(ar, N);
		cout << "Heap After insertion:\n"; 	
    		for(i = 0; i < N; i++)
    		{
        		cout <<  ar[i].data << "\t";
        		cout << ar[i].frequency << "\n";
    		}
	
		j++;
	}
		cout << "After the Huffman algo.:\n";
		printInorder(&ar[0]);

		string s, str1;
	    Pathstraversal(&ar[0], s);
	    cout << "Enter the string you want to send:\n";
	    cin >> str1;
	    for(int i = 0; i < strlen(str1.c_str()); i++)
	    {
	        cout<<codearray[int(str1[i])];
	    }
	    //cout<< (ar[0].right)->frequency ;//<< "\t" <<ar->left->data;
	   // cout<<codearray[65];
}
