class Solution {
public:
    int count(vector<vector<int>>& obstacleGrid,int m, int n,vector<vector<int>>&dp){
        if(m==0 && n==0 && obstacleGrid[m][n] == 1){
            return 0;
        }
        if(m == 0 && n==0){
            return 1;
        }   
        
        if(m<0 || n<0 || obstacleGrid[m][n] == 1){
            return 0;
        }
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
         int up = count(obstacleGrid,m-1,n,dp);   
        
        
         int left = count(obstacleGrid,m,n-1,dp);  
        
        
        return dp[m][n] = up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //tabulation method
        
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
        
//         vector<vector<int>>dp(m,vector<int>(n,-1));
        
//         if(obstacleGrid[0][0] == 1){
//             return 0;
//         }
        
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++){
//                 if(obstacleGrid[i][j] == 1){
//                     dp[i][j] = 0;
//                 }else if(i == 0 && j==0)
//                 {
//                     dp[i][j] =1;
//                 }
//                 else{
//                     int up =0;
//                     int left =0;
//                     if(i>0){
//                         up = dp[i-1][j];
//                     }
//                     if(j>0){
//                         left = dp[i][j-1];
//                     }
                    
//                     dp[i][j] = up + left;
//                 }
//             }
           
//         }
        
//         return dp[m-1][n-1];
        
        //memoization code
       // return count(obstacleGrid,m-1,n-1,dp);
        
        
        
        //space optimisation
        
         int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        
        vector<int>prev(n,0);
        
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    temp[j] = 0;
                }else if(i == 0 && j==0)
                {
                    temp[j] =1;
                }
                else{
                    int up =0;
                    int left =0;
                    if(i>0){
                        up = prev[j];
                    }
                    if(j>0){
                        left = temp[j-1];
                    }
                    
                    temp[j] = up + left;
                }
            }
            
            prev = temp;
           
        }
        
        return prev[n-1];
    }
};