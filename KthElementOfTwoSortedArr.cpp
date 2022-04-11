#include<bits/stdc++.h>
using namespace std;

//Brut Solution is to merge no need to store elements just increase counter on every element picked when counter == K return that element


int solveOpt(vector<int> v1,vector<int> v2,int N,int M,int K) 
{
    if(N > M) 
    {
        return solveOpt(v2,v1,M,N,K);
    }

    int low = max(0,K-M); //If we have less elements than K in right array then must have to stole K-M elements from left array.
    int high = min(K,N); //If we have more K as larger than N then we can not select more than N elements from left array.

    while(low <= high) 
    {
        int cut1 = (low+high)/2;
        int cut2 = K-cut1; //So that left must have K elements in it.

        int l1 = cut1==0 ? INT_MIN : v1[cut1-1];
        int l2 = cut2==0 ? INT_MIN : v2[cut2-1];

        int r1 = cut1==N ? INT_MAX : v1[cut1]; 
        int r2 = cut2==M ? INT_MAX : v2[cut2];

        if(l1 <= r2 && l2 <= r1) 
            return max(l1,l2);
        else if(l1 > r2) //It means left array have a greater elements so shift them to right we reduce left arr by moving high to mid-1
            high = cut-1;
        else 
            low = cut+1;
    }   
    return 1; // Only gets executed when K not found that is wrong test case.
}

int main() 
{
    int N,M,K;
    cin>>N>>M>>K;

    vector<int> v1(N),v2(M);

    for(int i=0;i<N;i++) 
    {
        cin>>v1[i];
    }

    for(int i=0;i<M;i++) 
    {
        cin>>v2[i];
    }

    cout<<solveOpt(v1,v2,K)<<endl;
    
}