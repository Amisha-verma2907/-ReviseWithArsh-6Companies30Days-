class Solution {
public:
    int count(string word1,string word2,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(word1[i] == word2[j]){
            return dp[i][j] = 0 + count(word1,word2,i-1,j-1,dp);
        }else{
            int insertO = 1 + count(word1,word2,i,j-1,dp);
            int deleteO = 1 + count(word1,word2,i-1,j,dp);
            int replace = 1+ count(word1,word2,i-1,j-1,dp);
            
            return dp[i][j] = min(insertO,min(deleteO,replace));
        }
    }
    int minDistance(string word1, string word2) {
       int n1= word1.size();
       int n2 = word2.size();
        
        //space optimisation
        
        vector<int>prev(n2+1,0);
         vector<int>cur(n2+1,0);
        
         for(int j=0;j<=n2;j++)
        {
            prev[j] = j;
        }
        
        
        for(int i=1;i<=n1;i++){
            cur[0] = i;
            for(int j=1;j<=n2;j++)
            {
                
            if(word1[i-1] == word2[j-1]){
                  cur[j] = 0 + prev[j-1];
            }else{
            int insertO = 1 + cur[j-1];
            int deleteO = 1 + prev[j];
            int replace = 1 + prev[j-1];
            
             cur[j] = min(insertO,min(deleteO,replace));
            } 
            }
            prev = cur;
        }
        
        return prev[n2];
        
        //tabulation
        
//         vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
//         for(int i=0;i<=n1;i++)
//         {
//             dp[i][0] = i;
//         }
        
//          for(int j=0;j<=n2;j++)
//         {
//             dp[0][j] = j;
//         }
        
        
//         for(int i=1;i<=n1;i++){
//             for(int j=1;j<=n2;j++)
//             {
                
//             if(word1[i-1] == word2[j-1]){
//                   dp[i][j] = 0 + dp[i-1][j-1];
//             }else{
//             int insertO = 1 + dp[i][j-1];
//             int deleteO = 1 + dp[i-1][j];
//             int replace = 1+ dp[i-1][j-1];
            
//              dp[i][j] = min(insertO,min(deleteO,replace));
//             } 
//             }
//         }
        
//         return dp[n1][n2];
        
        //memoization
//        vector<vector<int>>dp(n1,vector<int>(n2+1,-1));
        
//        return count(word1,word2,n1-1,n2-1,dp);
    }
};