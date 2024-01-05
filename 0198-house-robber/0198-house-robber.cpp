class Solution {
public:
    int findMax(vector<int>&dp,vector<int>& nums,int ind){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        
        int pick = nums[ind]+findMax(dp,nums,ind-2);
        int nonPick =  0 + findMax(dp,nums,ind-1);
        
        return dp[ind]=max(pick,nonPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return findMax(dp,nums,n-1);
    }
};