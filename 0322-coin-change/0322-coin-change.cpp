class Solution {
public:
    int coinsAmount(vector<int>&coins,int amount,int ind,vector<vector<int>>&dp){
        if(ind == 0)
        {
            if(amount% coins[0] == 0)
            {
                return amount/coins[0];
            }else{
                return 1e9;
            }
        }
        
        if(dp[ind][amount] != -1)
        {
            return dp[ind][amount];
        }
        //not take
        int notTake = 0 + coinsAmount(coins,amount,ind-1,dp);
        
        //take
        int take = INT_MAX;
        
        if(coins[ind] <= amount){
        take = 1 + coinsAmount(coins,amount - coins[ind],ind,dp);
        }
        
        return dp[ind][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        //tabulation
        int n = coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int T=0;T<=amount;T++)
        {
            if(T % coins[0] == 0){
            dp[0][T] = T/coins[0];
            }else{
                dp[0][T] = INT_MAX;
            }
        }
        
        for(int i=1;i<coins.size();i++)
        {
            for(int j = 0;j<=amount;j++)
            {
                //notTake
                int notTake = dp[i-1][j];
                
                int take = INT_MAX;
                if(coins[i] <= j  && dp[i][j - coins[i]] != INT_MAX){
                take = 1+ dp[i][j -coins[i]];
                }
                
                dp[i][j] = min(take,notTake);
                
            }
        }
        
        return dp[n-1][amount] != INT_MAX?dp[n-1][amount] : -1;
        
        
        //         int n = coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
//         int ans = coinsAmount(coins,amount,n-1,dp);
        
//         if(ans >= 1e9)
//         {
//             return -1;
//         }
//         return ans;
    }
};