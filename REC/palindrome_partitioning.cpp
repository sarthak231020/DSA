#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j) 
{
    while(i<j) 
    {
        if(s[i++] != s[j--]) 
            return false;
    }
    return true;
}

void solve(string s,int ind,vector<string> &currentList,vector<vector<string>> &res)
{
    if(ind == s.length()) 
    {
        res.push_back(currentList);
        return;
    }

    for(int end=ind;end<s.length();end++) 
    {
        if(isPalindrome(s,ind,end))
        {
            currentList.push_back(s.substr(ind,end-ind+1));
            solve(s,end+1,currentList,res);
            currentList.pop_back();
        }
    }
}

int main() 
{
    string s; 
    cin>>s;
    vector<string> currentList;
    vector<vector<string>> res;
    solve(s,0,currentList,res);

    for(auto i:res) 
    {
        for(auto j:i) 
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}