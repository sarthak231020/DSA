#include<bits/stdc++.h>
using namespace std;

bool solvePalin(string s,int i)
{
    if(i >= s.length()/2) 
        return true;
    if(s[i] != s[s.length()-i-1])   
        return false;
    if(solvePalin(s,i+1) == false)
        return false;
    return true;
    // One liner -> return solvePalin(s,i+1)
}

int main() 
{
    string s;
    getline(cin,s);

    cout<<solvePalin(s,0);
}