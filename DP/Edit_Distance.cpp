#include<bits/stdc++.h> 
using namespace std; 
int T[1001][1001];

int solve(string s1,string s2,int N,int M)
{
    for(int i=0;i<=N;i++)   
    {
        T[i][0] = 0;
    }
    for(int j=0;j<=M;j++) 
    {
        T[0][j] = 0;
    }

    for(int i=1;i<=N;i++) 
    {
        for(int j=1;j<=M;j++)   
        {
            if(s1[i-1] == s2[j-1]) 
            {
                T[i][j] = 1+T[i-1][j-1];
            }
            else
            {
                T[i][j] = max(T[i-1][j],T[i][j-1]);
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

    solve(s1,s2,N,M);

    int count = 0;

    int i=N,j=M; 

    while(i>0 && j>0) 
    {
        if(s1[i-1] == s2[j-1]) 
        {
            i--; 
            j--;
        }
        else 
        {
            count++;
            if(T[i-1][j] >= T[i][j-1]) 
            {
                i--;
            }
            else 
            {
                j--;
            }
        }
    }

    cout<<count<<endl;

}