#include<bits/stdc++.h> 
using namespace std;


struct SinglyLL
{
    int data;
    struct SinglyLL *next;
};
typedef struct SinglyLL Node;
Node *head = NULL;
void insert(int data,int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) 
    {
        head = newNode;
        return;
    }
    if(pos == 1) 
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    int k=1;

    while(k<pos-1 && temp->next)
    {
        k++;
        temp = temp->next;
    }
    if(k == pos-1) 
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else 
    {
        cout<<"Invalid Position"<<endl;
    }

}

int getLenList() 
{
    Node *temp = head;
    int count = 0;
    while(temp) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}


void reverseList() 
{
    Node *prev=NULL,*curr=head,*nextNode = NULL;
    while(curr) 
    {
        nextNode = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = nextNode; 
    }

    head = prev;
} 


void traverse() 
{
    Node *temp = head;
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    for(int i=10;i<=50;i=i+10) 
    {
        insert(i,1);
    }

    insert(60,6);

    traverse();

    reverseList();

    traverse();

    return 0;
}