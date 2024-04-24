class Solution {
public:
    bool isSafe(vector<string> &board,int row,int col,int n){
        int duprow=row;
        int dupcol=col;
        //upper diagonal
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q')return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0){
             if(board[row][col] == 'Q')return false;
            col--;
        }
         row=duprow;
        col=dupcol;
        while(col>=0 && row<n){
             if(board[row][col] == 'Q')return false;
            col--;
            row++;
        }
        return true;
    }
    void nQueen(vector<vector<string>> &ans,vector<string> &board,int n,int col){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
           if(isSafe(board,row,col,n)){
               board[row][col]='Q';
               nQueen(ans,board,n,col+1);
               board[row][col]='.';
           } 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        nQueen(ans,board,n,0);
        return ans;
    }
};