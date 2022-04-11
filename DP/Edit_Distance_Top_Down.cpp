#include<bits/stdc++.h>
using namespace std;

int T[501][501];

int solve(string s1,string s2,int N,int M) 
{

    for(int i=0;i<=N;i++) 
    {
        for(int j=0;j<=M;j++) 
        {
            if(i==0) 
            {
                T[i][j] = j;
            }
            else if(j==0)
            {
                T[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]) 
            {
                T[i][j] = T[i-1][j-1];
            }
            else
            {
                T[i][j] = 1+min(T[i-1][j],min(T[i][j-1],T[i-1][j-1]));
            }
        }
    }

    return T[N][M];
}

int main() 
{
    string s1,s2; 
    cin>>s1;
    cin>>s2;
    int N = s1.length(); 
    int M = s2.length();
    memset(T,-1,sizeof(T));

    cout<<solve(s1,s2,N,M)<<endl;

    return 0; 
}