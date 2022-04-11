// // #include<bits/stdc++.h>
// // using namespace std; 

// // int main() 
// // {
// //     string s;
// //     cin>>s;
// //     string out = "";
// //     string temp = "";
// //     int val = 0;
// //     for(int i=0;i<s.length();i++) 
// //     {
// //         temp = "";
        
// //         if(isdigit(s[i]))
// //         {
// //             val = s[i] - '0';
// //             i++;
// //             while(s[i] != ']') 
// //             {
// //                 if(s[i] != '[')
// //                     temp += s[i];
// //                 i++;
// //             }
// //         }
// //         for(int i=0;i<val;i++) 
// //         {
// //             out += temp;
// //         }
// //     }
// //     cout<<out<<endl;
// // }

// // string solve(string s,int ind,string &ans)
// // {
// //     if(ind == s.size()) 
// //     {
// //         return finalans;
// //     }
// //     if(s[i] == ']')
// //     {
// //         return ans;
// //     }
// //     int k;
// //     if(isdigit(s[ind]))
// //     {
// //         k = s[ind]-'0';
// //     }
// //     if(s[ind] >= 'a' && s[ind] <= 'z')
// //     {
// //         ans += s[ind];
// //     }
// //     string finalans = solve(s,ind+1,ans);

// // }

// void solve(string s,int ind,string &finalans)
// {
//     if(ind == s.length())
//         return;
//     string ans;
//     if(s[ind] == '[') 
//     {
//         ans = "";
//     }
//     else if(s[ind] >= 'a' && s[ind] <= 'z')
//     {
//         ans += s[ind];
//     }
//     else if(isdigit(s[ind]))
//     {
//         k = s[ind] - '0';
//     }
//     else 
//     {

//     }
// }

// int main() 
// {
//     string s;
//     cin>>s;
//     solve(s,)
// }



#include<bits/stdc++.h> 
using namespace std;

void solve(string exp,int ind,string ans,string &res)
{
    if(ind == exp.length())
        return;
    int k = -1;
    if(isdigit(exp[ind]))
    {
        k = exp[ind] - '0';
    }
    else if(exp[ind] >= 'a' && exp[ind] <= 'z') 
    {
        ans += exp[ind];
    }
    
    solve(exp,ind+1,ans,res);
    for(int i=0;i<k;i++) 
    {
        res += ans;
    }
}

int main() 
{
    string exp;
    cin>>exp;

    string ans;
    string res;
    solve(exp,0,ans,res);
    cout<<res<<endl;
    return 0;
}