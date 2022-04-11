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

bool HasKNodes(Node *point,int K) 
{
    int count = 0;
    Node *temp = point; 
    while(temp) 
    {
        count++; 
        temp = temp->next;
        if(count == K) 
            return true;
    }
    return false;
}

Node *RevKNodes(int K) 
{
    Node *temp1 = head,*temp2=NULL,*temp3=NULL;
    Node *curr=temp1,*prev = NULL,*nextNode=NULL;
    while(temp1) 
    {
        if(HasKNodes(temp1,K))
        {
            int i;
            *curr=temp1;
            if(prev == NULL) 
                i = 0;
            else 
                i = 1;
            while(curr) 
            {
                i++;
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                if(i == K) 
                    break;
            }
            if(temp2 == NULL) 
            {
                temp2 = prev;
            }
            temp3 = temp1;
            temp1 = curr->next;
            prev = curr;
        }
        else 
        {
            break;
        }
    }
}




int main()
{
    // int N,K;
    // cin>>N>>K;
    for(int i=1;i<=5;i++) 
    {
        insert(i,i);
    }
    

    // Node *p = head,*q=head;
    // for(int i=N;i>1;i--) 
    // {
    //     for(int j=0;j<K-1;j++)
    //     {
    //         p = p->next;
    //     }
    //     p->next = p->next->next;
    // }
    // cout<<"Remained player : "<<p->data<<endl;
    return 0;
}