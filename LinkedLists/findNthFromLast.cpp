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

int solveBrut(int n) 
{
    int m = getLenList();
    int fromBegin = m-n+1;
    int count = 1;
    Node *temp = head;
    while(count != fromBegin) 
    {
        count++;
        temp = temp->next;
    }
    return temp->data;
}

int solveEffiecient(int n) 
{
    int count = 1; //Pointing to head.
    Node *fast = head,*slow = NULL;

    while(count != n) 
    {
        count++;
        fast = fast->next;
    }
    
    while(fast) 
    {
        if(slow == NULL) 
        {
            slow = head;
        }
        else 
        {
            slow = slow->next;
        }
        fast = fast->next;
    }
    return slow->data;
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


    cout<<endl<<solveBrut(4)<<endl;

    cout<<solveEffiecient(4)<<endl;


    return 0;
}