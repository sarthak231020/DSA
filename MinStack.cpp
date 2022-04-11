#include<bits/stdc++.h>
using namespace std;

// Brut Solution is to take Stack of Pair<int,int> first for value and second for min till here 
// so while push check second of top if push min as second
// in pop just pop.

//Optimized 
class MinStack 
{
    stack<long long> st;
    long long mini = INT_MAX;

    public: 
    void push(int value) 
    {
        long long val = value;

        if(st.empty()) 
        {
            st.push(val);
            mini = val;
        }
        else
        {
            if(val < mini) 
            {
                st.push(2*val-mini); 
                mini = val;
            }
            else 
            {
                st.push(val);
            }
        }
    }

    void pop() 
    {
        if(st.empty()) 
            return;
        long long ele = st.top(); 
        st.pop(); 
        if(ele < mini) 
        {
            mini = 2*mini-ele;
        }
    }

    int top() 
    {
        if(st.empty()) 
            return -1; 
        long long ele = st.top(); 
        if(ele < mini)  
            return mini;
        return ele;
    }

    int getMin() 
    {
        return mini;
    }
};

int main() 
{
   

    MinStack minSt;
    
    minSt.push(-2);
    minSt.push(0); 
    minSt.push(-3);

    cout<<minSt.top()<<endl;
    cout<<minSt.getMin()<<endl;

    minSt.pop();

    cout<<minSt.getMin()<<endl;

}