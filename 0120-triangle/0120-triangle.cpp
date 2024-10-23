class Solution {
public:
    int sum(vector<vector<int>>& triangle,int m,int n,vector<vector<int>>&dp){
        if(m==0 && n==0){
            return triangle[0][0];
        }    
        
        if(m<0 || n<0 || n>m){
            return INT_MAX;
        }
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
    
        int up = sum(triangle,m-1,n,dp);
        int dg = sum(triangle,m-1,n-1,dp);
        
        return dp[m][n] = triangle[m][n] + min(up,dg);
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        
        // int mini = INT_MAX;
        // for(int i=0;i<m;i++)
        // {
        //    mini = min(mini,sum(triangle,m-1,i,dp));
        // }
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; ++i) {
            dp[i] = vector<int>(i + 1, -1);  // Each row i has i+1 elements
        }
        int mini = INT_MAX;
        for (int i = 0; i < triangle[m - 1].size(); ++i) {
            mini = min(mini, sum(triangle, m - 1, i, dp));
        }
        
        
        return mini;
    }
};