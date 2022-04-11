#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> outV;
void solve(vector<int> v,int N,int target,vector<int> out) 
{
    if(N==0) 
    {
        return ;
    }
    if(target == 0) 
    {
        outV.push_back(out);
        return;
    }

    if(v[N-1] > target)
    {
        solve(v,N -1,target,out);
    }
    else 
    {
        solve(v,N-1,target,out);
        out.push_back(v[N-1]);
        solve(v,N,target-v[N-1],out); //Unbounded Knapsack
    }
}

int main() 
{
    int N,target;
    cin>>N>>target;
    vector<int> v(N);

    for(int i=0;i<N;i++) 
    {
        cin>>v[i];
    }
    
    vector<int> out;
    solve(v,N,target,out);

    for(int i=0;i<outV.size();i++) 
    {
        for(int j=0;j<outV[i].size();j++) 
        {
            cout<<outV[i][j]<<" ";
        }
        cout<<endl;
    }
    set<vector<int>> s;

    for(int i=0;i<outV.size();i++) 
    {
        s.insert(outV[i]);
    }

    vector<vector<int>> finalOut(s.begin(),s.end());

    // for(int i=0;i<finalOut.size();i++) 
    // {
    //     for(int j=0;j<finalOut[i].size();j++) 
    //     {
    //         cout<<finalOut[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}