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
//         int n = coins.size();
    
//     vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));
    
//     // Initialize base case
//     for (int i = 0; i <= amount; i++) {
//         if (i % coins[0] == 0) {
//             dp[0][i] = 1; // If `i` is a multiple of coins[0]
//         }
//     }
    
//     // Fill the DP table
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j <= amount; j++) {
//             unsigned long long notTake = dp[i - 1][j]; // Exclude current coin
            
//             unsigned long long take = 0;
//             if (j >= coins[i]) {
//                 take = dp[i][j - coins[i]]; // Include current coin
//             }
            
//             dp[i][j] = take + notTake; // Total combinations
//         }
//     }
    
//     return dp[n - 1][amount]; 
        
        
        //         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
//         return count(coins,amount,coins.size()-1,dp);
        
        
        int n = coins.size();
    
        vector<unsigned long long>prev(amount+1,0);
        
    
    // Initialize base case
    for (int i = 0; i <= amount; i++) {
        if (i % coins[0] == 0) {
            prev[i] = 1; // If `i` is a multiple of coins[0]
        }
    }
    
    // Fill the DP table
    for (int i = 1; i < n; i++) {
        vector<unsigned long long>cur(amount+1,0);
        for (int j = 0; j <= amount; j++) {
            unsigned long long notTake = prev[j]; // Exclude current coin
            
            unsigned long long take = 0;
            if (j >= coins[i]) {
                take = cur[j - coins[i]]; // Include current coin
            }
            
            cur[j] = take + notTake; // Total combinations
        }
        
        prev = cur;
    }
    
    return prev[amount]; 
    }
};