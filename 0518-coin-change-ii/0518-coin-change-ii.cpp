class Solution {
public:
    int count(vector<int>&coins,int amount,int ind,vector<vector<int>>&dp)
    {
        if(ind == 0)
        {
            if(amount % coins[0] == 0)
            {
                return 1;
            }
            return 0;
        }
        
        if(dp[ind][amount]  != -1)
        {
            return dp[ind][amount];
        }
        
        //not take
        int notTake = count(coins,amount,ind-1,dp);
        
        int take = 0;
        if(coins[ind] <= amount){
          take = count(coins,amount - coins[ind],ind,dp);
        }
        
        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        return count(coins,amount,coins.size()-1,dp);
    }
};