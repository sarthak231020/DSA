#include<bits/stdc++.h>
using namespace std;

//Brut Solution is to merge these arrays and if length is even return average of two middle if length is odd then return mid ele

double solveOpt(vector<int> v1,vector<int> v2,int N,int M) 
{
    if(N > M) 
        return solveOpt(v2,v1,M,N);
    
    int low = 0; //Since we can leave all elements of the left array
    int high = N; //Since we can pick all elements of left array

    while(low <= high)
    {
        int cut1 = (low+high)/2; 
        int cut2 = (N+M+1)/2-cut1; //In order to take care of even odd lengths.
        
        int left1 = cut1 == 0 ? INT_MIN : v1[cut1-1];
        int left2 = cut2 == 0 ? INT_MIN : v2[cut2-1];

        int right1 = cut1 == N ? INT_MAX : v1[cut1];
        int right2 = cut2 == M ? INT_MAX : v2[cut2];

        if(left1 <= right2 && left2 <= right1)
        {
            if((N+M)%2 == 0)  
                return (max(left1,left2)+min(right1,right2))/2.0;
            else 
                return max(left1,left2);
        }
        else if(left1 > right2) 
            high = cut1-1;
        else 
            low = cut1+1;
    }
    return 0.0;
}

int main() 
{
    int N,M;
    cin>>N>>M;

    vector<int> v1(N),v2(M);

    for(int i=0;i<N;i++) 
    {
        cin>>v1[i];
    }

    for(int i=0;i<M;i++) 
    {
        cin>>v2[i];
    }

    cout<<solveOpt(v1,v2,N,M)<<endl;
}