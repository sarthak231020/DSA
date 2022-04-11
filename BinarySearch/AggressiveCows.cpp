#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &v,int N,int cows,int dist) 
{
    int cnt = 1,coOrd = v[0];


    for(int i=1;i<N;i++) 
    {
        if(v[i]-coOrd >= dist)
        {
            cnt++;
            coOrd = v[i];
        }
        if(cnt == cows) 
            return true;
    }
    return false;
}

int solve(vector<int> &v,int N,int Cows) 
{
    sort(v.begin(),v.end()); 


    int low = 1;
    int high = v[N-1]-v[0]; //Max distance we can keep

    while(low <= high) 
    {
        int mid = (low+high)/2; 

        if(possible(v,N,Cows,mid))
            low = mid+1;
        else 
            high = mid-1;
    }
    return high;
}

int main()
{
    int N,Cows;
    cin>>N>>Cows; //You have to place the cows with largest minimum distance.
    
    vector<int> v(N);

    for(int i=0;i<N;i++) 
    {
        cin>>v[i];
    }

    cout<<solve(v,N,Cows)<<endl;
}