/*
Leet Code - 51 :- Place N queens on chess baord of nxn such that they dont cancel each other.
1. We will create a solve function which will check if a particular cell can have a queen in it if yes then queen is placed.
2. This is checked using a isSafe function which checks if theer is any queen which can cancel the queen where we want to put it.
3. We will push all possible patterns into the answer.

Time Complexity :O(N! × N²) .
Space Complexity : O(S × N²) .

*/

class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
         row--;
         col--;
        }
        col=dupcol;
        row=duprow;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=duprow;
        col=dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<string>& board,vector<vector<string>> & ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};
