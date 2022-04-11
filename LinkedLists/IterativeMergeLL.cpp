#include<bits/stdc++.h> 
using namespace std;


struct SinglyLL
{
    int data;
    struct SinglyLL *next;
};

typedef struct SinglyLL Node;

Node *head1 = NULL,*head2=NULL,*head3=NULL;

void insert(Node **head,int data,int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    newNode->data = data;
    newNode->next = NULL;
    if((*head) == NULL) 
    {
        *head = newNode;
        return;
    }
    if(pos == 1) 
    {
        newNode->next = *head;
        *head = newNode;
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



int getLenList(Node *head)
{
    int count = 0;
    Node *temp = head;
    while(temp) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void MergeLL(Node *head1,Node *head2) 
{
    // if(head3 == NULL)
    // {
    //     if(head1->data < head2->data) 
    //     {
    //         Node *newNode = (Node *)malloc(sizeof(Node));
    //         newNode->data = head1->data;
    //         head1 = head1->next;
    //         head3 = newNode;
    //     }
    //     else 
    //     {
    //         head2 = head2->next;
            
    //     }
    // }

    Node *temp = head3;
    while((head1 != NULL) && (head2 != NULL)) 
    {
        if(head1->data <= head2->data) 
        {
            if(head3 == NULL) 
            {
                head3 = head1;
                temp = head1;
            }
            else 
            {
                temp->next = head1;
                temp = head1;
            }
            head1 = head1->next;
        }
        else 
        { 
            if(head3 == NULL) 
            {
                head3 = head2;
                temp = head2;
            }
            else 
            {
                temp->next = head2;
                temp = head2;
            }
            head2 = head2->next;
        }
    }
    if(head1 != NULL) 
    {
        temp->next = head1;
    }
    if(head2 != NULL) 
    {
        temp->next = head2;
    }
}

Node * MergeLLRec(Node *head1,Node *head2) 
{
    Node *result = NULL;
    if(head1 == NULL) 
        return head2;
    if(head2 == NULL) 
        return head1;
    
    if(head1->data <= head2->data) 
    {
        result = head1;
        result->next = MergeLLRec(head1->next,head2);
    }
    else 
    {
        result = head2; 
        result->next = MergeLLRec(head1,head2->next);
    }
    return result;
}


int main()
{
    for(int i=50;i>=10;i=i-10) 
    {
        insert(&head1,i,1);
    }

    traverse(head1);

    for(int i=21;i>=3;i=i-3) 
    {
        insert(&head2,i,1);
    }
    insert(&head2,30,8);

    traverse(head2);
    //Iterative
    // MergeLL(head1,head2);

    // traverse(head3);

    //recursive
    head3 = MergeLLRec(head1,head2);
    traverse(head3);
    return 0;
}