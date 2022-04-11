#include<bits/stdc++.h>
using namespace std; 

bool isSafe(vector<string> board,int row,int col)
{
    int temp_row = row;
    int temp_col = col;
    int N = board.size();
    while(col>=0) 
    {   
        if(board[row][col] == 'Q')
            return false;
        col--;
    }
    col = temp_col;
    while(row<N && col >=0) 
    {
        if(board[row][col] == 'Q') 
            return false;
        row++;
        col--;
    }
    row = temp_row; 
    col = temp_col;
    while(row>=0 && col>=0)
    {
        if(board[row][col] == 'Q') 
            return false;
        row--;
        col--;
    }
    return true; 
}

void solve(int col,int N,vector<string> &board,vector<vector<string>> &result)
{
    if(col == N) 
    {
        result.push_back(board);
        return;
    }

    for(int row = 0;row<N;row++) 
    {
        if(isSafe(board,row,col))
        {
            board[row][col] = 'Q';
            solve(col+1,N,board,result);
            board[row][col] = '.';
        }
    }
}


int main() 
{
    int N;
    cin>>N;

    string s(N,'.'); 
    vector<vector<string>> result;
    vector<string> board;
    for(int i=0;i<N;i++) 
    {
        board.push_back(s);
    }

    solve(0,N,board,result);

    for(auto i:result)
    {
        for(auto j:i) 
        {
            cout<<j<<endl;
        }
        cout<<"OUTPUT ENDS";
        cout<<endl;
    }
    

}