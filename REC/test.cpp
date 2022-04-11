#include<bits/stdc++.h>
using namespace std; 

int main() 
{
    int row = 3;
    int col = 3;
            for(int i=0;i<9;i++) 
            {
                cout<<" "<<row<<" "<<col<<" "<<(3*(row/3)+i/3)<<" "<<(3*(col/3)+i%3)<<endl;
            }
}