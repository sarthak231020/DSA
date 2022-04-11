#include<bits/stdc++.h>
using namespace std; 

vector<vector<int>> outV;
void solve(vector<int> v,int N,vector<int> out)
{
    if(N == 0) 
    {
        outV.push_back(out);
        return;
    }

    solve(v,N-1,out);
    out.push_back(v[N-1]);
    solve(v,N-1,out);
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
    vector<int> out;
    solve(v,N,out);
    cout<<"[";
    for(int i=0;i<outV.size();i++) 
    {
        cout<<"[";
        for(int j=0;j<outV[i].size();j++) 
        {
            if(j!=outV[i].size()-1)
                cout<<outV[i][j]<<",";
            else
                cout<<outV[i][j];
        }
        if(i == outV.size()-1)
            cout<<"]";
        else 
            cout<<"],";
    }
    cout<<"]";

    return 0;
}