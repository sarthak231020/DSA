#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> v,int N) 
{
    stack<pair<int,int>> st;
    vector<int> ans(N);

    for(int i=0;i<N;i++) 
    {
        while(!st.empty() && v[st.top().second] <= v[i])
        {
            st.pop();
        }
        if(st.empty()) 
        {
            ans[i] = -1;
        }
        else 
        {
            ans[i] = st.top().second;
        }
        st.push({v[i],i});
    }

    for(auto i:ans) 
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<N;i++) 
    {
        ans[i] = i-ans[i];
    }

    for(auto i:ans)
    {
        cout<<i<<" ";
    }

    cout<<endl;
    return ans;
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

    solve(v,N);
}