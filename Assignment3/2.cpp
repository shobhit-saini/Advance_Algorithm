#include<iostream>
#include<cstdlib>
using namespace std;
    struct node
    {
        int data;
        struct node *next;
    };
    struct node* temphead;
	void reverse(struct node* ptr)
	{
		if(ptr->next==NULL)
		{
			temphead=ptr;
			return;
		}
		else
		{
			reverse(ptr->next);
			struct node* qtr=ptr->next;
			qtr->next=ptr;
			ptr->next=NULL;
		}
	}
    int main()
    {
        int n;
        cout<<"Enter the size of an array:";
        cin>>n;
        int* arr=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
////////////////////////////////INSERTING ONE BY ONE IN INCREASING ORDER/////////////////////////////
        struct node* p=new node;
        struct node* ptr1,*head,*ptr2;
        p->data=arr[0];
        head=ptr1=p;
        ptr1->next=NULL;
        for(int i=1;i<n;i++)
        {
            p=new node;
            ptr1=head;
            while(ptr1!=NULL)
            {
                if((ptr1->next!=NULL)&&(ptr1->next->data<=arr[i]))
                {
                    ptr1=ptr1->next;
                }
                else
                break;
        	}
        	if(ptr1==head)
        	{
        		if(ptr1->data>=arr[i])
				{
	        		p->data=arr[i];
	        		p->next=ptr1;
	        		head=p;
	        		continue;
        		}
			}
			if(ptr1->next==NULL)
			{
				p->data=arr[i];
				ptr1->next=p;
				p->next=NULL;
				continue;
			}
			else
			{
                p->data=arr[i];
                p->next=ptr1->next;
                ptr1->next=p;
         	}        
        }
/////////////////////////////////////PRINTING OF LINKED LIST////////////////////////////////
        ptr1=head;
        while(ptr1!=NULL)
        {
            cout<<ptr1->data<<"\t";
            ptr1=ptr1->next;
        }    
////////////////////////////////////REMOVE DUPLICATES FROM THE LIST///////////////////////
		ptr1=head;
		ptr2=ptr1->next;
		while(ptr1!=NULL)
		{
			if(ptr1->data==ptr2->data)
			{
				if(ptr2->next==NULL)
				{
					free(ptr2);
					ptr1->next=NULL;
					ptr1=ptr1->next;
				}
				else
				{
					ptr1->next=ptr2->next;
					free(ptr2);
					ptr2=ptr1->next;
				}
			}
			else
			{
				if(ptr2->next==NULL)
				{
					break;
				}
				else
				{
					ptr1=ptr1->next;
					ptr2=ptr2->next;
				}
			}
		}
///////PRINTING THE ELEMENTS AFTER THE REMOVAL OF DUPLICATE ELEMENTS///////////
		cout<<"\nPRINTING THE ELEMENTS AFTER THE REMOVAL OF DUPLICATE ELEMENTS:\n";
		ptr1=head;
		int len=0;
        while(ptr1!=NULL)
        {
            cout<<ptr1->data<<"\t";
            ptr1=ptr1->next;
            len++;
        }   
//////////////////REVERSE EVERY K INTEGER IN THE LINKED LIST///////////////////
		int k,m=1,q=1;
		struct node* ptr,*head1,*head2,*head3;
		cout<<"\nEnter the value of k:";
		cin>>k;
		ptr=head;
		head1=head;
		for(int i=1;i<=len;i+=3)
		{
			int j=1;
			temphead=head1;
			ptr=head1;
			while((j<k)&&(ptr->next!=NULL))
			{
				ptr=ptr->next;
				j++;
			}
			head1=ptr->next;
			ptr->next=NULL;
			head3=head2;
			head2=temphead;
	        reverse(temphead);
			if(m==1)
			{
				head=temphead;
				m++;
			}
			if(q!=1)
			{
				head3->next=temphead;
				q++;
			}
			q++;
			head2->next=head1; 	
		}
		
///////////PRINTING THE ELEMENTS AFTER THE REVERSE IN THE GROUP OF K ELEMENTS///////////////
		cout<<"\nPRINTING THE ELEMENTS AFTER THE K REVERSE:\n";
		ptr1=head;
        while(ptr1!=NULL)
        {
            cout<<ptr1->data<<"\t";
            ptr1=ptr1->next;
        }  		
    }
