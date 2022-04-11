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




int main()
{
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++) 
    {
        insert(i,i);
    }
    Node *temp = head; 
    while(temp->next) 
    {
        temp = temp->next;
    }
    temp->next = head;  // Create a circle.

    Node *p = head,*q=head;
    for(int i=N;i>1;i--) 
    {
        for(int j=0;j<K-1;j++)
        {
            p = p->next;
        }
        p->next = p->next->next;
    }
    cout<<"Remained player : "<<p->data<<endl;
    return 0;
}