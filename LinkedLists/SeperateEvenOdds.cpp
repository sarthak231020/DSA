#include<bits/stdc++.h> 
using namespace std;


struct SinglyLL
{
    int data;
    struct SinglyLL *next;
};
typedef struct SinglyLL Node;
Node *head = NULL,*head2 = NULL;

    Node *headEven = NULL,*headOdd = NULL;
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

void seperateEvenOdd() 
{
    Node *temp1 = headEven,*temp2 = headOdd;
    Node *temp = head; 
    while(temp) 
    {   
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = temp->data;
        newNode->next = NULL;
        if((newNode->data)%2 == 0) 
        {
            if(headEven == NULL) 
            {
                headEven = newNode;
                temp1 = newNode;
            }
            else 
            {
                temp1->next = newNode;
                temp1 = newNode;
            }
        }
        else if((newNode->data%2) == 1) 
        {
            if(headOdd == NULL) 
            {
                headOdd = newNode;
                temp2 = newNode;
            }
            else 
            {
                temp2->next = newNode;
                temp2 = newNode;
            }
        }

        temp = temp->next;
    }

    
}

void traverse(Node *head) 
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
    int count = 1;
    for(int i=10;i<=60;i=i+10) 
    {
        insert(i,count);
        count++;
    }

    cout<<"Even List"<<endl;
    Node *temp = head;
    while(temp) 
    {

        int data1 = (int)(temp->data);
        if((data1%2) == 0)
        {
            cout<<temp->data<<" ";
        }
        temp = temp->next;
    }
    cout<<endl<<"Odd List"<<endl;
    temp = head;
    while(temp)     
    {
        int data2 = temp->data;
        if((data2%2) == 1) 
        {
            cout<<temp->data<<" ";
        }
        temp = temp->next;
    }
    cout<<endl;
}