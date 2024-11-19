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
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        int ans = coinsAmount(coins,amount,n-1,dp);
        
        if(ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
};