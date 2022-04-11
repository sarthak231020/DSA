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

int solve1() 
{
    return (getLenList()%2);
}

void solve2() 
{
    Node *temp = head;
    while((temp != NULL) && (temp->next != NULL)) 
    {
        temp = temp->next->next;
    }
    if(temp == NULL) 
    {
        cout<<"EVEN LENGTH LL"<<endl;
    }
    else 
    {
        cout<<"ODD LENGTH LL"<<endl;
    }
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

    // insert(60,6);
    if(solve1() == 1) 
    {
        cout<<"ODD LENGTH LL"<<endl;
    }
    else 
    {
        cout<<"EVEN LENGTH LL"<<endl;
    }

    solve2();

    // head = NULL; for testing only

    // if(!head) 
    // {
    //     cout<<"head NULL"<<endl;
    // }
    // else 
    // {
    //     cout<<"head not null"<<endl;
    // }
    return 0;
}