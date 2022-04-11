#include<bits/stdc++.h>
using namespace std;

void solve(int i,int K,string &s)
{
    if(i==K) 
    {
        return;
    }
    next_permutation(s.begin(),s.end());
    solve(i+1,K,s);
}

// int main() 
// {
//     int N;
//     cin>>N; 
//     vector<int> v(N);

//     for(int i=1;i<=N;i++) 
//     {
//         v[i-1] = i;
//     }

//     solve(1,3,v); 
//     for(auto i:v) 
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     // vector<vector<int>> perm; 
//     // do 
//     // {
//     //     perm.push_back(v);
//     // }while(next_permutation(v.begin(),v.end()));

//     // for(auto i:perm) 
//     // {
//     //     for(auto j:i) 
//     //     {
//     //         cout<<j<<" ";
//     //     }
//     //     cout<<endl;
//     // }
// }

int main() 
{
    int N;
    cin>>N;
    string s = "";
    for(int i=1;i<=N;i++) 
    {
        s += to_string(i);
    }
    solve(1,3,s);
    cout<<endl<<s<<endl;
}