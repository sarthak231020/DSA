#include<bits/stdc++.h> 
using namespace std; 

void calculatePSE(vector<int> &pse,vector<int> v,int N) 
{
    stack<int> st;

    for(int i=0;i<N;i++) 
    {
        while(!st.empty() && v[st.top()] >= v[i]) 
        {
            st.pop();
        }
        if(st.empty()) 
        {
            pse[i] = 0;
        }
        else 
        {
            pse[i] = st.top()+1;
        }
        st.push(i);
    }
}

void calculateNSE(vector<int> &nse,vector<int> v,int N) 
{
    stack<int> st;

    for(int i=N-1;i>=0;i--) 
    {
        while(!st.empty() && v[st.top()] >= v[i]) 
        {
            st.pop();
        }
        if(st.empty()) 
        {
            nse[i] = v.size()-1;
        }
        else 
        {
            nse[i] = st.top()-1;
        }
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

    vector<int> pse(N),nse(N);

    calculatePSE(pse,v,N);

    for(int i=0;i<N;i++)
    {
        cout<<pse[i]<<" ";
    }
    cout<<endl;
    calculateNSE(nse,v,N);

    for(int i=0;i<N;i++) 
    {
        cout<<nse[i]<<" ";
    }
    cout<<endl;

    int maxi = INT_MIN;
    for(int i=0;i<N;i++) 
    {
        maxi = max(maxi,(nse[i]-pse[i]+1)*v[i]);
    }

    cout<<maxi<<endl;

    return 0;
}