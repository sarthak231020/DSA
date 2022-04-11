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
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteNode(int pos)
{
    if(head == NULL) 
    {
        cout<<"List is already empty"<<endl;
        return;
    }
    if(pos == 1) 
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    int k=1;
    Node *prev=head,*curr=head;
    while(k<pos && curr->next)
    {
        k++;
        prev = curr; 
        curr = curr->next;
    }

    if(curr == NULL) 
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    
    prev->next = curr->next;
    free(curr);

}

int main() 
{

    for(int i=10;i<=50;i=i+10) 
    {
        insert(i,1);
    }

    insert(60,6);
    insert(150,2);

    Node *temp = head;
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"Deleting 1st Node"<<endl;
    deleteNode(1);
    temp = head;
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"Deleting 5th Node"<<endl;
    temp = head;
    deleteNode(5);
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"Deleting last node"<<endl;
    temp = head;
    deleteNode(5);
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;
}