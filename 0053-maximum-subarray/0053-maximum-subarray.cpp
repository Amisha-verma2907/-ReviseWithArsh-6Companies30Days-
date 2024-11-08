class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//         int maxi = INT_MIN;
        
//         int sum = 0;
//         for(int i=0;i<nums.size();i++)
//         {
//             sum+=nums[i];
            
//             if(sum>maxi){
//                 maxi = sum;
//             }
//             if(sum<0)
//             {
//                 sum = 0;
//             }
//         }
        
//         return maxi;
        
        
        int maxSum = nums[0];
        int curSum =  nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            curSum = max(nums[i],nums[i]+curSum);
            maxSum = max(maxSum,curSum);
        }
        
        return maxSum;
    }
};