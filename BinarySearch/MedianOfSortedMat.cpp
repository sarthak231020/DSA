#include<bits/stdc++.h>
using namespace std;

//Brut approach is to store elements of matrix into an array and sort it return mid element of that array.

int countSmallerEqToMid(vector<int> &row,int data)
{
    int l=0;
    int h=row.size()-1;

    while(l <= h) 
    {
        int mid = (l+h)>>1;

        if(row[mid] <= data) 
        {
            l = mid+1;
        }
        else 
        {
            h = mid-1;
        }
    }
    return l;
}

int solve(vector<vector<int>> v) //It will find out just upper bound which have no of lesser ele == no of greater ele.
{   
    // TC -> log2 2^32 N log2 M -> O(NlogM) 
    // SC -> basically it is O(1) if you do not do it in seperate function for countSmallerEqToMid
    int low = 1;
    int high = 1e9;
    int N = v.size();
    int M = v[0].size();
    while(low <= high) 
    {
        int mid = (low+high)>>1; // divide /2;
        int cnt = 0;

        for(int i=0;i<N;i++) 
        {
            cnt += countSmallerEqToMid(v[i],mid);
        }

        if(cnt <= (N*M)/2)
            low = mid+1;
        else 
            high = mid-1;
    }
    return low;
}

int main() 
{
    int N;
    int M;
    cin>>N>>M;  //It is given that matrix is row wise sorted and also N*M is always Odd so median will be middle ele

    vector<vector<int>> v(N,vector<int> (M));

    for(int i=0;i<N;i++) 
    {
        for(int j=0;j<M;j++) 
        {
            cin>>v[i][j];
        }
    }

    cout<<solve(v)<<endl;
}
