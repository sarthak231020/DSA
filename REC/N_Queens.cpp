#include<bits/stdc++.h> 
using namespace std; 
vector<vector<int>> result;
vector<int> ans;

void solve(vector<int> &v,int N,int temp,vector<int> &ans) 
{
    if(N == 0) 
    {
        result.push_back(ans);
        return;
    }

    for(int i=0;i<v.size();i++) 
    {
        if(v[i]+1 == temp || v[i]-1 == temp)
        {
            continue;
        }
        int temp = v[i];
        v.erase(v.begin()+i);
        ans.push_back(temp);
        solve(v,N-1,temp,ans);
        ans.pop_back();
        v.insert(v.begin()+i,temp);
    }
}


int main() 
{
    int N;
    cin>>N; 
    vector<int> v;
    for(int i=1;i<=N;i++) 
    {
        v.push_back(i);
    }

    solve(v,N,-10,ans);

    for(auto i:result) 
    {
        for(auto j:i) 
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}