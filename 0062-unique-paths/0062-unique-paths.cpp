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
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
//         dp[0][0] = 1;
        
//          for (int i = 0; i < m; i++) {
//             dp[i][0] = 1; // Only one way to reach any cell in the first column (move down)
//         }
//         for (int j = 0; j < n; j++) {
//             dp[0][j] = 1; // Only one way to reach any cell in the first row (move right)
//         }
        
//         for(int i=1;i<m;i++)
//         {
//             for(int j=1;j<n;j++)
//             {
//                 int up = 0;
//                 int left = 0;
                
//                 if(i>0) up = dp[i-1][j];
                
//                 if(j>0) left = dp[i][j-1];
                
//                 dp[i][j] = up + left;
//             }
//         }
        
//         return dp[m-1][n-1];
        
        //return paths(m-1,n-1,dp);
        
        
        
        //space optimisation solution
        
        vector<int>prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int>cur(n,0);
            
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j==0)
                {
                    cur[j] = 1;
                }else{
                    int up = 0;
                    int left = 0 ;
                    
                    if(i>0) up = prev[j];
                    if(j>0) left = cur[j-1];
                    
                    cur[j] = up +left;
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};