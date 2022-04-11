#include<bits/stdc++.h> 
using namespace std;

//Brut soltion is to sort both the strings and check whether they are equal or not TC->O(Nlogn) SC->O(1)

//A better solution is to make two hash maps and check whether each one contains same amount of characters.

//Optimal Solution
bool solveOpt(string s1,string s2)
{
    if(s1.length() != s2.length()) 
        return false; 

    map<char,int> mp;

    for(int i=0;i<s1.length();i++)
    {
        if(mp.find(s1[i]) != mp.end()) 
            mp[s1[i]]++;
        else 
            mp[s1[i]] = 1;
    }

    for(int i=0;i<s2.length();i++) 
    {
        if(mp.find(s2[i]) != mp.end()) 
            mp[s2[i]]--;
        else 
            return false;
    }

    for(auto i:mp) 
    {
        if(i.second != 0) 
            return false;
    }
    return true;
}

int main() 
{
    string s1,s2;

    getline(cin,s1); 
    getline(cin,s2);

    cout<<solveOpt(s1,s2)<<endl;
}