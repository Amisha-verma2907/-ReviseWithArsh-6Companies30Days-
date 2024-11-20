class Solution {
public:
    int partition(vector<int>nums,int target,int ind,vector<vector<int>>&dp){
        if(ind == 0)
        {
            if(nums[0] == 0 && target == 0){
                return 2;
            }
           if(target == 0 || target == nums[0]){
                return 1;
            }
            return 0;
        }
        
        if(dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        //notTake
        int notTake = partition(nums,target,ind-1,dp);
        
        int take = 0;
        if(nums[ind] <= target)
        {
            take = partition(nums,target - nums[ind],ind-1,dp);
        }
        
        return dp[ind][target] = take + notTake;
    }
    int TargetSum(int target,vector<int>&nums){
        int totalSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            totalSum+=nums[i];
        }
        int s2 = (totalSum - target)/2;
        if((totalSum-target)<0 || (totalSum -target) %2 != 0 ) return 0;
        int n= nums.size();
        
//         vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        
//         return partition(nums,s2,nums.size()-1,dp);
        
        vector<vector<int>>dp(n,vector<int>(s2+1,0));
        if(nums[0] == 0)
        {
        dp[0][0] = 2;
        }else{
            dp[0][0] = 1;
        }
        
        if (nums[0] != 0 && nums[0] <= s2)
        dp[0][nums[0]] = 1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=s2;j++)
            {
                int notTake = dp[i-1][j];
                
                int take =0 ;
                
                if(nums[i] <= j){
                    take = dp[i-1][j - nums[i]];
                }
                
                dp[i][j] = take + notTake;
            }
        }
        
        return dp[n-1][s2];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return TargetSum(target,nums);
    }
};