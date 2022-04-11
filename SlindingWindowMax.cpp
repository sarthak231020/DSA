#include<bits/stdc++.h>
using namespace std;

//Brut Solution is to find all Subarray of Size K and Store max Of each one of them it takes O(N^2).

vector<int> solveOpt(vector<int> v,int N,int K) 
{
    deque<int> dq;
    vector<int> ans;
    for(int i=0;i<N;i++) 
    {
        while(!dq.empty() && dq.front() == i-K) 
        {
            dq.pop_front();
        }
        while(!dq.empty() && v[dq.back()] < v[i]) 
        {
            dq.pop_back();
        } 
        dq.push_back(i);
        if(i >= K-1)
            ans.push_back(v[dq.front()]);
    }

    return ans;
}

int main() 
{
    int N,K;
    cin>>N>>K;

    vector<int> v(N); 

    for(int i=0;i<N;i++) 
    {
        cin>>v[i];
    }

    for(auto i:solveOpt(v,N,K)) 
    {
        cout<<i<<" ";
    }
    cout<<endl;
}