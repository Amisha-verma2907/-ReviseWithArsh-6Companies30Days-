class Solution {
public:
    int paths(int m,int n,vector<vector<int>>&dp){
        if(m == 0 && n==0)
        {
            return 1;
        }
        
        if(m<0 || n<0){
            return 0;
        }
        
        if(dp[m][n] != -1) return dp[m][n];
        
        int up = paths(m-1,n,dp);
        
        int left = paths(m,n-1,dp);
        
        return dp[m][n] = up + left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return paths(m-1,n-1,dp);
    }
};