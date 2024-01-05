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
        // int n=nums.size();
        // vector<int>dp(n,-1);
        // return findMax(dp,nums,n-1);
        
        int prev=nums[0];
        int prev2=0;
        int curi=0;
        for(int i=1;i<nums.size();i++)
        {
            int pick = nums[i];
            if(i>1) pick += prev2;
            int nonPick = 0 + prev;
            
            curi = max(pick,nonPick);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};