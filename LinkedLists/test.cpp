#include<bits/stdc++.h> 
using namespace std; 

void swap(int *x,int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() 
{
    int x=10,y=20;
    swap(x,y);
    cout<<x<<endl;
    cout<<y<<endl;
    return 0;
}