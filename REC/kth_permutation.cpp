#include<bits/stdc++.h>
using namespace std;
// int fact(int n) 
// {
//     if(n==0) 
//     {
//         return 1;
//     }
//     return n*fact(n-1);
// }




// int main() 
// {
//     int N,K;
//     cin>>N>>K;
//     vector<int> v(N+1);

//     for(int i=1;i<=N;i++) 
//     {
//         v[i] = i;
//     }
    
//     vector<int> factorial; 
    
//     for(int i=0;i<=N;i++) 
//     {
//         factorial.push_back(fact(i));
//     }
//     string result;
    
    
    

//     int temp = N;

//     while(v.size() != 0)
//     {
//         int val = K/(factorial[temp]/temp);
//         result += to_string(v[val]);
//         K = K%(factorial[temp]/temp);
       
//         v.erase(v.begin()+val);
//         temp--;
//     }
//     cout<<result<<endl;
// }



int main() 
{
    int N,K; 
    cin>>N>>K;
    int fact = 1;
    //assuming 
    vector<int> v;
    for(int i=1;i<N;i++) 
    {
        fact = fact*i; // if N is 4 then we need Factorial of 3.
        v.push_back(i);
    }
    // //Now put up the last one 
    v.push_back(N);

    K = K-1; // since we are assuming 
    string ans = "";
    while(true)
    {
        ans += to_string(v[K/fact]);
        v.erase(v.begin()+(K/fact));
        if(v.size() == 0) 
        {
            break;
        }
        K = K%fact;
        fact = fact/v.size();
    }
    // cout<<" Hey "<<endl; 
    cout<<ans<<endl;
}