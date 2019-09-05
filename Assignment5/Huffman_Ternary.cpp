#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
using namespace std;

//Data type to storing relevant tree information
	struct Huffman
	{
		char data;
		int frequency;
		struct Huffman *left;
		struct Huffman *middle;
		struct Huffman *right;
	};

	string codearray[256];

//Swap function for swapping any two node of tree
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
			for(i = floor((high-2)/3); i >= 0; i--)
			{
				j = i;
				
				//Heapify from Top
				while(j <= floor((high-2)/3))
				{
					if((3*j + 2 < high) && (3*j + 3 < high))
					{
						if((ar[j].frequency > ar[3*j + 1].frequency) || (ar[j].frequency > ar[3*j + 2].frequency) || (ar[j].frequency > ar[3*j + 3].frequency))
						{
							if((ar[3*j + 1].frequency < ar[3*j + 2].frequency) && (ar[3*j + 1].frequency < ar[3*j + 3].frequency))
							{
								Swap(&ar[j], &ar[3*j + 1]);
								j = 3*j + 1;
							}
								else if (ar[3*j + 2].frequency < ar[3*j + 3].frequency)
								{
									Swap(&ar[j], &ar[3*j + 2]);
									j = 3*j + 2;
								}
										else
										{
											Swap(&ar[j], &ar[3*j + 3]);
											j = 3*j + 3;
										}
						}
						
							else
							{
								break;
							}
							
					}
					
					else if((3*j +2 < high))
					{
						if((ar[j].frequency > ar[3*j + 1].frequency) || (ar[j].frequency > ar[3*j + 2].frequency))
						{
							if((ar[3*j + 1].frequency < ar[3*j + 2].frequency))
							{
								Swap(&ar[j], &ar[3*j + 1]);
								j = 3*j + 1;
							}
								else
								{
									Swap(&ar[j], &ar[3*j + 2]);
									j = 3*j + 2;
								}
						}
						
							else
							{
								break;
							}
							
					}
					
						else if(ar[j].frequency > ar[3*j + 1].frequency)
						{
							Swap(&ar[j], &ar[3*j + 1]);
								j = 3*j + 1;
						}
							else
							{
								break;
							}
				}
			}
		
	return 0;
	}

//Adjusting tree after Extracting minnimum from tree 
	int Extract_min(struct Huffman *ar, int high)
	{
	
		int j = 0;
		Swap(&ar[0], &ar[high - 1]);
		high = high - 1;
		if(high == 1)
		{
			return high;
		}
		
		//Heapify from Top
				while(j <= floor((high-2)/3))
				{
					if((3*j + 2 < high) && (3*j + 3 < high))
					{
						if((ar[j].frequency > ar[3*j + 1].frequency) || (ar[j].frequency > ar[3*j + 2].frequency) || (ar[j].frequency > ar[3*j + 3].frequency))
						{
							if((ar[3*j + 1].frequency < ar[3*j + 2].frequency) && (ar[3*j + 1].frequency < ar[3*j + 3].frequency))
							{
								Swap(&ar[j], &ar[3*j + 1]);
								j = 3*j + 1;
							}
								else if (ar[3*j + 2].frequency < ar[3*j + 3].frequency)
								{
									Swap(&ar[j], &ar[3*j + 2]);
									j = 3*j + 2;
								}
										else
										{
											Swap(&ar[j], &ar[3*j + 3]);
											j = 3*j + 3;
										}
						}
						
							else
							{
								break;
							}
							
					}
					
					else if((3*j +2 < high))
					{
						if((ar[j].frequency > ar[3*j + 1].frequency) || (ar[j].frequency > ar[3*j + 2].frequency))
						{
							if((ar[3*j + 1].frequency < ar[3*j + 2].frequency))
							{
								Swap(&ar[j], &ar[3*j + 1]);
								j = 3*j + 1;
							}
								else
								{
									Swap(&ar[j], &ar[3*j + 2]);
									j = 3*j + 2;
								}
						}
						
							else
							{
								break;
							}
							
					}
					
						else if(ar[j].frequency > ar[3*j + 1].frequency)
						{
							Swap(&ar[j], &ar[3*j + 1]);
								j = 3*j + 1;
						}
							else
							{
								break;
							}
				}
	return high;
	}

//Inserting node into the tree
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
  
//Making Code from tree and store into array
	void Pathstraversal(struct Huffman* node, string s)  
	{  
	    if (node == NULL)  
	        return;  
	      
	    ///////////it's a leaf
	    if (node->left == NULL && node->middle == NULL && node->right == NULL)  
	    {  
	        codearray[int(node->data)] = s; 
	    }  
	    else
	    {  
	        //otherwise try both subtrees 
	        Pathstraversal(node->left, s + '0');  
	        Pathstraversal(node->middle, s + '1'); 
	        Pathstraversal(node->right, s + '2');  
	    }  
	}  

//Printing of Huffman tree
	void printInorder(struct Huffman* node) 
	{ 
	    if (node == NULL) 
	        return; 
	        
	    printInorder(node->left); 
	    printInorder(node->middle); 
	    cout << node->frequency << " "; 
	    
	    printInorder(node->right); 
	    
	} 

///////////////////Decoder///////////////////
	void Decoder(struct Huffman* node, string str)
	{
		struct Huffman* temp = node;
		int i = 0;
		for(i = 0; i < strlen(str.c_str()); i++)
		{
			if(str[i] == '0')
			{
				temp = temp->left;
			}
			else if(str[i] == '1')
			{
				temp = temp->middle;
			}
			else if(str[i] == '2')
			{
				temp = temp->right;
			}
			if(temp->left == NULL && temp->middle == NULL && temp->right == NULL)
			{
				cout<<temp->data;
				temp = node;	
			}
		}
	}


//////////////////////////////////////////////MAIN/////////////////////////////////////////////////////////////////////////////
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
			ar[i].middle = NULL;
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
		while(N != 1)
		{
		    //////////////Extraction of first minimum/////////////////
		    struct Huffman* Min1 = new Huffman;
		    *Min1 = ar[0];
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
	    		
	    	//////////////Extraction of third minimum/////////////////
	       	struct Huffman* Min3 = new Huffman;
	       		if(N != 0)
		        {
					*Min3 = ar[0];
					cout << "Min3:" << Min3->frequency << "\n";
					N = Extract_min(ar, N);
					cout << "Heap After the Extract min:\n";
			    		for(i = 0; i < N; i++)
			    		{
			    			cout <<  ar[i].data << "\t";
			    			cout << ar[i].frequency << "\n";
			    		}
		    			
				/////////////Making the new node///////////////////
				ar[N].frequency = Min1->frequency + Min2->frequency + Min3->frequency;
				ar[N].data = '\0';
				ar[N].left = Min1;
				ar[N].middle = Min2;
				ar[N].right = Min3;
				N++;
				}
					else
					{
						ar[N].frequency = Min1->frequency + Min2->frequency;
						ar[N].data = '\0';
						ar[N].left = Min1;
						ar[N].middle = Min2;
						ar[N].right = NULL;
						N++;
					}

			///////////Insert the new node into tree/////////
			Insert(ar, N);
			cout << "Heap After insertion:\n"; 	
	    		for(i = 0; i < N; i++)
	    		{
	        		cout <<  ar[i].data << "\t";
	        		cout << ar[i].frequency << "\n";
	    		}

		}
		
		//Printing of Huffman Tree
		cout << "Huffman Tree:\n";
		printInorder(&ar[0]);

 		//For getting encoding string
		string s, str1, encoded;
	    Pathstraversal(&ar[0], s);
	    cout << "\nEnter the string you want to send:";
	    cin >> str1;
	    cout << "Encoded string:";
		    for(int i = 0; i < strlen(str1.c_str()); i++)
		    {
		        encoded += codearray[int(str1[i])];
		        cout << codearray[int(str1[i])];
		    }
		 
		//For decoding the string   
	    cout << "\nDecoded string:";
	    Decoder(&ar[0], encoded);
}
