// https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/
#include<bits/stdc++.h>
using namespace std; 

void calculatePSE(vector<int> &pse,vector<int> v,int N) 
{
    stack<int> st;

    for(int i=0;i<N;i++) 
    {
        while(!st.empty() && v[st.top()] >= v[i]) 
            st.pop();
        if(st.empty()) 
            pse[i] = -1;
        else 
            pse[i] = st.top();
        st.push(i);
    }
}


void calculateNSE(vector<int> &nse,vector<int> v,int N) 
{
    stack<int> st;

    for(int i=N;i>=0;i--) 
    {
        while(!st.empty() && v[st.top()] >= v[i]) 
            st.pop();
        if(st.empty()) 
            nse[i] = -1;
        else 
            nse[i] = st.top();
        st.push(i);
    }
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

    vector<int> nse(N),pse(N);

    calculateNSE(nse,v,N);
    calculatePSE(pse,v,N);
    
    vector<int> ans(N+1,0);
    for(int i=0;i<N;i++) 
    {
        int len = nse[i]-pse[i]-1;

        ans[len] = max(ans[len],v[i]);        
    }

    for(int i=N-1;i>=0;i--) 
    {
        ans[i] = max(ans[i],ans[i+1]);
    }

    for(int i=1;i<=N;i++) 
    {
        cout<<ans[i]<<" ";
    }

    cout<<endl;
}