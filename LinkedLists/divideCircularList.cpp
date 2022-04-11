#include<bits/stdc++.h> 
using namespace std;


struct SinglyLL
{
    int data;
    struct SinglyLL *next;
};

typedef struct SinglyLL Node;

Node *head = NULL,*head2 = NULL;

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

void traverseCircular(Node *head) 
{
    Node *temp = head; 
    do 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}

int getCount(Node *head) 
{
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next; 
    }while(temp != head); 
    return count;
}

void divideCircular() 
{
    int len = getCount(head);
    int mid = len/2; 
    if(len%2 == 0) 
        mid = mid-1;
    Node *slow = head;
    int count = 0;
    while(count != mid) 
    {
        count++; 
        slow = slow->next; 
    }
    head2 = slow->next;
    Node *temp = head2;
    slow->next = head;
    while(temp->next != head) 
    {
        temp = temp->next;
    }
    temp->next = head2;
}

void divideCircular2()
{
    Node *slow = NULL,*fast=head;
    int i=0;
    do
    {
        if(i==0) 
        {
            fast = fast->next;
            i = 1;
        }
        if(i == 1) 
        {
            if(slow == NULL) 
                slow = head;
            else 
                slow = slow->next;
            fast = fast->next; 
            i = 0;
        }
    }while(fast != head && fast->next != head);
    if(fast->next == head) 
        slow = slow->next;
    head2 = slow->next;
    Node *temp = head2; 
    slow->next = head; 
    while(temp->next != head) 
    {
        temp = temp->next;
    }

    temp->next = head2;
} 


int main()
{
    int count = 1;
    for(int i=10;i<=60;i = i+10) 
    {
        insert(i,count);
        count++;
    }

    Node *temp = head;
    while(temp->next) 
    {
        temp = temp->next; 
    }
    temp->next = head; // make it circular.



    traverseCircular(head);
    divideCircular();

    traverseCircular(head);
    cout<<"List 1 Completed"<<endl;
    traverseCircular(head2);

    return 0;
}