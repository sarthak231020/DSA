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


void insertInSortedList(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data; 
 
    Node *temp = head,*curr = NULL;

    while((temp !=NULL) && (temp->data < newNode->data))
    {
        curr = temp; 
        temp = temp->next;
    }

    if(curr == NULL) 
    {
        newNode->next = head; 
        head = newNode;
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;


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
    for(int i=50;i>=10;i=i-10) 
    {
        insert(i,1);
    }

    Node *temp = head;
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl; //This is a sorted list

    // cout<<"Still Running"<<endl;
    insertInSortedList(5);
    // cout<<"Still Running"<<endl;
    temp = head;
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    // cout<<"Still Running"<<endl;
    insertInSortedList(25); 
    // cout<<"Still Running"<<endl;
    temp = head;
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    insertInSortedList(60); 
    
    temp = head;
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}