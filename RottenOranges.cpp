//This question states that a rotten orange can rotten the left right upper lower oranges if possible to rotten all orages 
// return days otherwise -1. 
// 0->NO orange 1->fresh Orange 2->rotten Orange.
#include<bits/stdc++.h> 
using namespace std;

int orangesRottened(vector<vector<int>> &v,int N,int M) 
{
    if(v.empty())
        return 0;
    queue<pair<int,int>> q;
    int tot = 0,days=0,cnt=0;

    for(int i=0;i<N;i++) 
    {
        for(int j=0;j<M;j++ ) 
        {
            if(v[i][j] != 0) 
                tot++;
            if(v[i][j] == 2) 
                q.push({i,j});
        }
    }

    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    while(!q.empty()) 
    {
        int k = q.size();
        cnt += k;
        while(k--)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) 
            {
                int nx = x+dx[i],ny=y+dy[i];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M || v[nx][ny] != 1)
                    continue;
                v[nx][ny] = 2;
                q.push({nx,ny});   
            }
        }
        if(!q.empty()) 
            days++;
    }

    if(cnt == tot)
        return days;
    return -1;

}

int main() 
{
    int N,M; 
    cin>>N>>M; 

    vector<vector<int>> v(N,vector<int> (M));

    for(int i=0;i<N;i++) 
    {
        for(int j=0;j<M;j++) 
        {
            cin>>v[i][j];
        }
    }

    cout<<orangesRottened(v,N,M)<<endl;
}