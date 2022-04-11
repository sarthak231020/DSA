#include<bits/stdc++.h>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int,vector<int>,greater<int>> minHeap;  
int median = 0;

void printMedians(vector<int> v,int N)
{
    if(N == 0) 
        return;
    
    maxHeap.push(v[0]);
    
}

int main() 
{
    int N; 
    cin>>N; 
    vector<int> v(N); 

    for(int i=0;i<N;i++) 
    {
        cin>>v[i];
    }

    


}