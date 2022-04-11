#include<bits/stdc++.h>
using namespace std;

bool allocationIsPossible(vector<int> v,int N,int Stud,int Barrier)
{
    int allocatedStud = 1,pages = 0;

    for(int i=0;i<N;i++) 
    {
        if(v[i] > Barrier) //We have reached a mid point where a book is not allocated to any student so return false.
            return false;
        if(pages + v[i] > Barrier)
            allocatedStud += 1;
        pages += v[i];
    }
    if(allocatedStud > Stud)  // In this case we have allocated more students than allowed so return false
        return false;
    return true;
}
 
int solveOpt(vector<int> v,int N,int Stud) 
{   
    //TC -> O(NlogN)
    int sum = 0,res = -1;
    for(int i=0;i<N;i++) 
    {
        sum += v[i];
    }

    int low = *min_element(v.begin(),v.end());
    int high = sum;
    while(low <= high) 
    {
        int mid = (low+high)/2;
        
        if(allocationIsPossible(v,N,Stud,mid))
        {
            res = mid; 
            high = mid-1;
        }
        else 
        {
            low = mid+1;
        }
    }
    return res;
}

int main() 
{
    int N,Stud;
    cin>>N>>Stud; 

    vector<int> v(N);

    for(int i=0;i<N;i++) 
    {
        cin>>v[i];
    }

    cout<<solveOpt(v,N,Stud)<<endl;
}