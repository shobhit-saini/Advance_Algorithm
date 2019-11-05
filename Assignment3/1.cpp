#include<bits/stdc++.h>
using namespace std;
    struct cir
    {
        struct cir* prev;
        int data;
        struct cir* next;
    };
int main()
{
    int n,k;
    cout<<"Enter the no. of people:";
    cin>>n;
    cout<<"Enter the interval of elimation:";
    cin>>k;
    
//////////////////CIRCULAR LINKED LIST CREATION////////////////////////////////
    struct cir* head=new struct cir();
    head->data=1;
    struct cir* ptr;
    ptr=head;
    for(int i=2;i<n;i++)
    {
        struct cir* p=new struct cir();
        p->data=i;
        ptr->next=p;
        p->prev=ptr;
        ptr=ptr->next;
    }
    struct cir* p=new struct cir();
    p->data=n;
    ptr->next=p;
    p->prev=ptr;
    p->next=head;
    head->prev=p;
    
//////////////////CIRCULAR LINKED LIST PRINT//////////////////////
    /*struct cir* ptr1;
    ptr1=head;
    cout<<ptr1->data;
    ptr1=ptr1->next;    
    while(ptr1!=head)
    {
        cout<<ptr1->data<<"\n";
        ptr1=ptr1->next;
    }*/
    
//////////////////ELIMINATION PROCEDURE///////////////////////////
    struct cir* ptr2,*ptr3;
    ptr2=head;
    while(1)
    {
         for(int i=1;i<=k-1;i++)
        {
            
            ptr2=ptr2->next;
            if(ptr2->next==ptr2)
            {
                cout<<"Winner:"<<ptr2->data<<"\n";
                return 0;
            }    
        }
        ptr3=ptr2;
        ptr3->prev->next=ptr3->next;
        ptr3->next->prev=ptr3->prev;
        ptr2=ptr2->next;

    }
return 0;

}
