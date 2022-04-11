#include<bits/stdc++.h> 
using namespace std; 

int main() 
{
    int N,target; 
    cin>>N>>target;
    vector<int> v(N); 
    for(int i=0;i<N;i++) 
    {
        cin>>v[i];
    }

    solve(v,N);

    return 0;
}