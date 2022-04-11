#include<bits/stdc++.h> 
using namespace std;
//Brut solution is to check every row and every col to get celebrity -> O(N^2)
//Celebrity does not know anybody but everybody knows him.

//Optimal Solution TC -> O(N). SC->O(N).
//https://www.youtube.com/watch?v=CiiXBvrX-5A

void solveOpt(vector<vector<int>> v,int N) 
{
    if(N == 1)
        return;
    
    stack<int> st;

    for(int i=0;i<N;i++) 
    {
        st.push(i);
    }

    while(st.size() >= 2)
    {
        int x = st.top();
        st.pop(); 
        int y = st.top(); 
        st.pop();

        if(v[x][y] == 1) 
            st.push(y);
        else 
            st.push(x);
    }
    bool flag = true;
    for(int i=0;i<N;i++) 
    {
        if(i != st.top()) 
        {
            if(v[st.top()][i] == 1 || v[i][st.top()] == 0)
            {
                flag = false; 
                break;
            }
        }
    }
    if(flag == true) 
    {
        cout<<"Celebrity is : "<<st.top()<<endl;
    }
    else
    {
        cout<<"No Celebrity present"<<endl;
    }

}

int main() 
{
    int N; 
    cin>>N;

    vector<vector<int>> v(N,vector<int> (N));  //Always a N*N matrix will be given 0-> represent i don't know j.
                                                                                // 1-> represents i knows j. 

    for(int i=0;i<N;i++) 
    {
        for(int j=0;j<N;j++) 
        {
            cin>>v[i][j];
        }
    }

    solveOpt(v,N);
}