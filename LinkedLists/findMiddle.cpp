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

int solveBrut() 
{
    int mid = ceil(getLenList()/(2.0));
    Node *temp = head;
    int count = 0;

    while(count != mid-1) 
    {
        count++;
        temp = temp -> next;
    }
    return temp->data;
}

int solveTwoPointers() //Effiecient one
{
    Node *slow = head,*fast = head;
    
    int i=0;
    while(fast->next != NULL) 
    {
        if(i==0) 
        {
            fast = fast->next; 
            i = 1;
        }
        else 
        {
            slow = slow->next;
            fast = fast->next;
            i = 0;
        }
    }
    return slow->data; 
}


int solveTwoPointers2() //Effiecient one
{
    Node *slow = head,*fast = head;
    
    if(head->next == NULL) 
    {
        return head->data;
    }
    fast = fast->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    } 
    return slow->data;
}



int main() 
{

    for(int i=10;i<=50;i=i+10) 
    {
        insert(i,1);
    }

    // insert(60,6);

    Node *temp = head;
    while(temp) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
    cout<<solveBrut()<<endl;
    cout<<"Using two pointers"<<endl;
    cout<<solveTwoPointers()<<endl;

    cout<<solveTwoPointers2()<<endl;

    return 0;
}