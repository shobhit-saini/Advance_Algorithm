#include <iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<sstream>
using namespace std;
//Stud Datatype to store information of file into stud type array
struct stud
{	string name;
	string roll_no;
	string department; 
};
//swapping-Used in quick sort
	void swap(struct stud *i,struct stud *j)
	{
	    struct stud temp;
	    temp=*i;
	    *i=*j;
	    *j=temp;
	}
    //To find the position of pivot elements
		int partition(struct stud *a,int p,int q)
		{
		    int i,j,temp;
		    struct stud x;
		    x=a[p];
		    i=p;
		    for(j=p+1;j<=q;j++)
		    {
		        if(strcmp(a[j].name.c_str(),x.name.c_str())<0)
		        {
		            i=i+1;
		            swap(a[i],a[j]);
		        }
		        //if name matches then sort by roll_no
		        else if(strcmp(a[j].name.c_str(),x.name.c_str())==0)
		        {
		        	if(strcmp(a[j].roll_no.c_str(),x.roll_no.c_str())<=0)
			        {
			            i=i+1;
			            swap(a[i],a[j]);
			        }
				}
		    }
		    swap(a[p],a[i]);
		    
		     
		    return (i);
		}
		//Main function of Quick_sort
		void DAC_QS(struct stud *a,int p,int q)
		{
		    int m;
		    if(p<q)
		    {
		        m=partition(a,p,q);//DIVIDE--Time Complexity=O(n)
		        DAC_QS(a,p,m-1);//Conquer--T(m-p)
		        DAC_QS(a,m+1,q);//Conquer--T(q-m)
		    }
		}

/********************************************MERGE SORT*****************************************************************/
    //Merge algo. to merge two sorted array 
	void Merge(struct stud *a, int low, int high, int mid)
	{
		int i, j, k;
		struct stud temp[high-low+1];
		i = low;
		k = 0;
		j = mid + 1;
	 
		// Merge the two parts into auxillary array temp[].
		while (i <= mid && j <= high)
		{
			if (strcmp(a[i].name.c_str(),a[j].name.c_str())<0)
			{
				temp[k] = a[i];
				k++;
				i++;
			}
			else if(strcmp(a[i].name.c_str(),a[j].name.c_str())>0)
			{
				temp[k] = a[j];
				k++;
				j++;
			}
			//if name matches then sort by roll_no
			else if(!(strcmp(a[i].name.c_str(),a[j].name.c_str())))
			{
				if(strcmp(a[i].roll_no.c_str(),a[j].roll_no.c_str())<0)
				{
					temp[k] = a[i];
					k++;
					i++;
				}
				else
				{
					temp[k] = a[j];
					k++;
					j++;
				}
			}
		}
	 
		// Insert all the remaining elements from i to mid into temp[].
		while (i <= mid)
		{
			temp[k] = a[i];
			k++;
			i++;
		}
	 
		// Insert all the remaining elements from j to high into temp[].
		while (j <= high)
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	 
	 
		// Transfer the elements from auxillary array temp to a;
		for (i = low; i <= high; i++)
		{
			a[i] = temp[i-low];//temp array starts from 0 that's why i-low
		}
	}
    //Main function of Mergesort
	void MergeSort(struct stud *a, int low, int high)
	{
		int mid;
		if (low < high)
		{
			mid=(low+high)/2;
			// Split the data into two half.
			MergeSort(a, low, mid);
			MergeSort(a, mid+1, high);
	 
			// Merge them to get sorted output.
			Merge(a, low, high, mid);
		}
	}

/****************************************************Modified Binary Search**********************************************************************/

	int M_BS_L(struct stud *brr,int low,int high,string key)
	{
		int mid,res1;
		if(low<=high)
		{
			mid=(low+high)/2;
			res1=strcmp(brr[mid].name.c_str(),key.c_str());
			if(res1==0)
			{
				if(mid==low)
				{
				
					return mid;
				}
				if(strcmp(brr[mid-1].name.c_str(),brr[mid].name.c_str())<0)
				{
					return mid;
				}
			}
			 if(res1<0)
			{
				return M_BS_L(brr,mid+1,high,key);	
			}
			else
			{
				
				return M_BS_L(brr,low,mid-1,key);
			}	
		}
	  	return -1;
	}
	int M_BS_R(struct stud *brr,int low,int high,string key)
	{
		int i,mid,res1;
		if(low<=high)
		{
			mid=(low+high)/2;
			res1=strcmp(brr[mid].name.c_str(),key.c_str());
			if(res1==0)
			{
				if(mid==high)
				{
					return mid;
				}
				if(strcmp(brr[mid+1].name.c_str(),brr[mid].name.c_str())>0)
				{
					return mid;
				}
			}
			if(res1>0)
			{
				return M_BS_R(brr,low,mid-1,key);
			}
			else
			{
				return M_BS_R(brr,mid+1,high,key);
			}
		}
	  return -1;
	}

int main()
{
	int c,length,size=0,flag=0;
	string x="";
	ifstream Myfile("abc.txt");
	  if(!Myfile.is_open())
	  {
	  	cout<<"File  can't be open";
	  }
	  int a,b;
	  struct stud arr[100];
	  string line;
	  while(getline(Myfile,line))
	  {
	  	stringstream ss(line);//Divide the string into words
	  	getline(ss,arr[size].name,',');
	  	getline(ss,arr[size].roll_no,',');
	  	getline(ss,arr[size].department,'\n');
	  	size++;
	  }
  /*for(int j=0;j<size;j++)
  {
  	cout<<arr[j].name<<" "<<arr[j].roll_no<<" "<<arr[j].department<<endl;
  }*/
  
  while(1)
  {
  	cout<<"->Press 1 for Merge sort:"<<endl;
 	cout<<"->Press 2 for Quick sort:"<<endl;
 	cout<<"->Press 3 for Binary Search:"<<endl;
  	cout<<"->Press 4 to Quit:"<<endl;
  	 cin>>c;
	  switch(c)
	  {
		  	case 1:
		  			MergeSort(arr, 0, size-1);
		  			for(int i=0;i<size;i++)
		    		{
		    			cout<<arr[i].name<<"\t";
		    			cout<<arr[i].roll_no<<"\t";
		    			cout<<arr[i].department<<"\n";
					}
					cout<<endl;
					flag=1;
					break;
		  	case 2:
		  		    DAC_QS(arr,0,size-1);
		         	for(int i=0;i<size;i++)
		    		{
		    			cout<<arr[i].name<<"\t";
		    			cout<<arr[i].roll_no<<"\t";
		    			cout<<arr[i].department<<"\n";
					}
					cout<<endl;
					flag=1;
					break;
		  	case 3:
		  			if(flag==0)
		  			{
		  				cout<<"Elements are not sorted yet";
					}
					else
					{
						cout<<"Enter the element do you want to search:";
				  		cin>>x;
				  		a=M_BS_L(arr,0,size-1,x);
			    		b=M_BS_R(arr,0,size-1,x);
			    	//	cout<<"["<<a<<","<<b<<"]";
			    		for(int i=a;i<=b;i++)
			    		{
			    			cout<<arr[i].name<<"\t";
			    			cout<<arr[i].roll_no<<"\t";
			    			cout<<arr[i].department<<"\n";
						}
					}
					cout<<endl;
			  	break;
			case 4:	return 0;
		}
	}
  Myfile.close();
}
