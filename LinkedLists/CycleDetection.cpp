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

bool solveBrutHash() 
{
    Node *temp = head;
    unordered_set<Node *> s;
    while(temp)
    {
        if(s.find(temp) != s.end()) 
        {
            return true;
        }
        else 
        {
            s.insert(temp);
        }
        temp = temp->next;
    }
    return false;
}

bool solveEffiecient() //Tortoise method Floyd's Algo
{
    Node *slow=head,*fast=head;

    while(fast) 
    {
        slow = slow->next; 
        if(fast->next == NULL) 
        {
            return false;
        }
        fast = fast->next->next;
        if(slow == fast) 
        {
            return true;
        }
    }
    return false;
}

int lenOfLoop() 
{
    Node *slow=head,*fast=head;
    bool loopExists = false;
    while(fast) 
    {
        slow = slow->next; 
        if(fast->next == NULL) 
        {
            loopExists = false;
            break;
        }
        fast = fast->next->next;
        if(slow == fast) 
        {
            loopExists = true;
            break;
        }
    }
    if(loopExists) 
    {
        int count = 0;
        fast = fast->next; 
        while(fast != slow) 
        {
            count++;
            fast = fast->next;
        }
        return count;
    }
    return -1;
}

int findStartNodeOfLoop() 
{
    Node *slow=head,*fast=head;
    bool loopExists = false;
    while(fast) 
    {
        slow = slow->next; 
        if(fast->next == NULL) 
        {
            loopExists = false;
            break;
        }
        fast = fast->next->next;
        if(slow == fast) 
        {
            loopExists = true;
            break;
        }
    }
    if(loopExists) 
    {
        slow = head;
        while(slow != fast) 
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
    return -1;
}

int main()
{
    for(int i=10;i<=50;i=i+10) 
    {
        insert(i,1);
    }

    insert(60,6);

    traverse();
    Node *temp =head;  // Create a Loop 
    while(temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = head;

    cout<<solveBrutHash()<<endl;

    cout<<solveEffiecient()<<endl;

    cout<<lenOfLoop()<<endl;

    cout<<findStartNodeOfLoop()<<endl;

    return 0;
}