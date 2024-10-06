class Solution {
public:
    int climb(int dp[],int n){
        // if(n<=2){
        //     return n;
        // }
        if(n == 1)
        {
            return 1;
        }
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
        
//         if(dp[n] != -1){
//             return dp[n];
//         }
        
//         return dp[n] = climb(dp,n-1) + climb(dp,n-2);
        
        
    }
    int climbStairs(int n) {
        int dp[n+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i] = -1;
        }
        
        
        return climb(dp,n);
    }
};