#include<bits/stdc++.h> 
using namespace std;


struct SinglyLL
{
    int data;
    struct SinglyLL *next;
};

typedef struct SinglyLL Node;

Node *head1 = NULL,*head2;

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


int solve1(Node *head1,Node *head2) //Using hashmap.
{
    unordered_set<Node *> s; 
    Node *temp1 = head1;
    while(temp1) 
    {
        s.insert(temp1);
        temp1 = temp1->next;
    }

    Node *temp2 = head2;
    while(temp2) 
    {
        if(s.find(temp2) != s.end()) 
        {
            return temp2->data;
        }
        temp2 = temp2->next;
    }
    return -1;
}

int solve2(Node *head1,Node *head2) 
{
    Node *temp1 = head1;
    vector<Node *> v;
    while(temp1) 
    {
        v.push_back(temp1);
        temp1 = temp1->next;
    }
    sort(v.begin(),v.end());
    Node *temp2 = head2;
    while(temp2) 
    {
        if(binary_search(v.begin(),v.end(),temp2))
        {
            return temp2->data;
        }
        temp2 = temp2->next;
    }
    return -1;
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


int solve3(Node *head1,Node *head2) // Most Effiecient One
{
    Node *temp1 = head1,*temp2 = head2;

    int L1 = getLenList(head1);
    int L2 = getLenList(head2);
    int diff; //stores difference in between length of lists.
    if(L1 < L2) 
    {
        temp1 = head2;
        temp2 = head1;
        diff = L2-L1;
    }
    else 
    {
        temp1 = head1;
        temp2 = head2;
        diff = L1-L2;
    }

    for(int i=0;i<diff;i++) 
    {
        temp1 = temp1->next;
    }

    while((temp1!=NULL) && (temp2 != NULL)) 
    {
        if(temp1 == temp2) 
        {
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}


int main()
{
    for(int i=10;i<=50;i=i+10) 
    {
        insert(&head1,i,1);
    }

    traverse(head1);

    for(int i=100;i<=150;i=i+10) 
    {
        insert(&head2,i,1);
    }

    traverse(head2);

    /*To put up an intersection */
    Node *temp1 = head1;
    temp1 = temp1->next;
    temp1 = temp1->next;

    Node *temp2 = head2;
    while(temp2->next) 
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
    /*end*/
    cout<<solve1(head1,head2)<<endl;
    cout<<solve2(head1,head2)<<endl;

    cout<<solve3(head1,head2)<<endl;
    return 0;
}