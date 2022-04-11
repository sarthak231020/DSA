#include<bits/stdc++.h> 
using namespace std; 

void solve(int col,vector<string> &board,int N,vector<vector<string>> &result,vector<int> &leftRow,vector<int> &lowerDiagonal,vector<int> &upperDiagonal) 
{
    if(col == N)
    {
        result.push_back(board);
        return;
    }

    for(int row = 0;row<N;row++) 
    {
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[N-1+col-row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[N-1+col-row] = 1;
            solve(col+1,board,N,result,leftRow,lowerDiagonal,upperDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[N-1+col-row] = 0;
        }
    }
}

int main() 
{
    int N;
    cin>>N;
    string s(N,'.');
    vector<string> board;
    for(int i=0;i<N;i++) 
    {
        board.push_back(s);
    }
    vector<int> leftRow(N-1,0),lowerDiagonal(2*N-1,0),upperDiagonal(2*N-1,0);
    vector<vector<string>> result;
    solve(0,board,N,result,leftRow,lowerDiagonal,upperDiagonal);

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