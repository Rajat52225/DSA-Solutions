/*
Leet Code - 52 :- N Queens II .
So approach is similar to n queens :-
1. We check like we put one queen only in one column .
2. According to that first queen we sets other queens and we put them like we check if on left diagnolly or straight left or left down diagonally any queen isnt there.
3. If we reach the end when column==n then we get our first arrangement and we increase a counter .
4. Then what we do is we just return the count .

Time Complexity : O(N! × N) .
Space Complexity : O(N²) .

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
        while(col>=0 && row<n){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,int& count,vector<string>& board,int n){
        if(col==n){
            count++;
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,count,board,n);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int count=0;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,count,board,n);
        return count;
    }
};
