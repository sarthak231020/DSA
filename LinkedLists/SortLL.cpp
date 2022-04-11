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

void insertInSortedLL(int data) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if(head2 == NULL) 
    {
        newNode->next = head2;
        head2 = newNode;
        return;
    }
    Node *curr = NULL,*temp = head2;
    while(temp!=NULL && temp->data < newNode->data) 
    {
        curr = temp;
        temp = temp->next;
    }
    if(curr == NULL) 
    {
        newNode->next = head2; 
        head2 = newNode;
    }
    else 
    {
        newNode->next = curr->next;
        curr->next = newNode;
    }

    
}


// void sortLL() 
// {
//     int data;
//     Node *pred=NULL;
//     while(temp != NULL) 
//     {
//         Node *newdata = temp;
//         Node *curr = NULL,*temp1 = head;
//         while(temp1 != NULL && newdata->data < temp1->data)
//         {
//             curr = temp1;
//             temp1 = temp1->next;
//         }
//         if(curr == NULL) 
//         {
        
//         }
//         pred = temp;
//         temp = temp->next; 
//     }
// }

void sortLL() 
{
    Node *temp = head;
    while(temp)     
    {
        insertInSortedLL(temp->data); 
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
    insert(10,1);
    insert(5,2);
    insert(8,3);
    insert(2,4);
    insert(1,5); 
    insert(0,6);
    insert(15,7);
    insert(11,8);

    traverse(head);
    sortLL();

    traverse(head2);

    return 0;
}