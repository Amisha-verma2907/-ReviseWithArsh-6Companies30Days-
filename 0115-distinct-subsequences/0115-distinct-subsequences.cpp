class Solution {
public:
    int count(string s,string t,int i,int j,vector<vector<int>>&dp){
        if(j<0){
            return 1;
        }
        if(i<0)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(s[i] == t[j]){
            return dp[i][j] = count(s,t,i-1,j-1,dp) + count(s,t,i-1,j,dp);
        }else{
            return dp[i][j] = count(s,t,i-1,j,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
    int n2 = t.size();

    // Space optimization: Use two 1D arrays
    vector<unsigned long long> prev(n2 + 1, 0); 
    vector<unsigned long long> cur(n2 + 1, 0);

    // Base case: There's exactly one way to form an empty string
    prev[0] = 1;

    // Iterate over `s` and `t` to fill DP arrays
    for (int i = 1; i <= n1; i++) {
        cur[0] = 1; // Reset for every new row
        for (int j = 1; j <= n2; j++) {
            if (s[i - 1] == t[j - 1]) {
                cur[j] = prev[j - 1] + prev[j];
            } else {
                cur[j] = prev[j];
            }
        }
        prev = cur; // Move current row to previous for next iteration
    }

    return prev[n2];
        
        //tabulation
        
//         vector<vector<unsigned long long>>dp(n1+1,vector<unsigned long long>(n2+1,0));
        
//          for(int i=0;i<=n1;i++)
//         {
//             dp[i][0] = 1;
//         }
        
//         for(int j=1;j<=n2;j++)
//         {
//             dp[0][j] = 0;
//         }
        
//         for(int i=1;i<=n1;i++){
//             for(int j=1;j<=n2;j++)
//             {
//                 if(s[i-1] == t[j-1]){
//                     dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    
//                 }else{
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
        
        
       // return dp[n1][n2];
        //memoization
//         vector<vector<int>>dp(n1,vector<int>(n2,-1));
        
//         return count(s,t,n1-1,n2-1,dp);
    }
};