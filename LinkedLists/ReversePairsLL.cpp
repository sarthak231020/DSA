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

void reversePairs() 
{
    Node *temp1 = NULL,*temp2 = NULL,*curr = head;
    while((curr != NULL) && (curr->next != NULL))
    {
        if(temp1 != NULL) 
        {
            temp1->next->next = curr->next;
        }
        temp1 = curr->next;
        curr->next = curr->next->next;
        temp1->next = curr;
        if(temp2 == NULL) 
        {
            temp2 = temp1;
        }
        curr = curr->next;
    } 
    head = temp2;
}

// Node *ReversePairsRec(Node **head) 
// {
//     if(head == NULL || head->next == NULL) 
//         return head; 
//     Node *temp; 
//     temp = *head->next;
//     head->next = temp->next;
//     temp->next = *head;
//     *head = temp; 
//     *head->next->next = ReversePairsRec(*head->next->next); 
//     return *head;
// }


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
    for(int i=40;i>=10;i=i-10)
    {
        insert(i,1);
    }

    traverse();

    reversePairs();

    traverse();

}