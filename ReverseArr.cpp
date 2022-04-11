#include<bits/stdc++.h>
using namespace std; 

void reverseArr(vector<int> &v,int l,int r) 
{
    if(l >= r) 
    {
        return; 
    }
    swap(v[l],v[r]);
    reverseArr(v,l+1,r-1);
}

//Using single var 
void SolveRev(vector<int> &v,int i) 
{
    if(i >= v.size()-i-1) 
    {
        return;
    }
    swap(v[i],v[v.size()-i-1]);
    SolveRev(v,i+1); 
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

    reverseArr(v,0,N-1);

    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    SolveRev(v,0);

    for(auto i:v) 
    {
        cout<<i<<" ";
    }
    cout<<endl;
}