class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        //using map
//         int n = nums.size();
        
//         vector<int>mp(n+1,0);
        
//         for(int i=0;i<n;i++)
//         {
//             mp[nums[i]]++;
//         }
        
//         for(int i=0;i<=n;i++)
//         {
//             if(mp[i] == 0)
//             {
//                 return i;
//             }
//         }
//         return 0;
        
        
        //general approach
        
        int n = nums.size();
        
        int totalSum = (n * (n+1))/2;
        
        int actualSum =0;
        for(int i=0;i<n;i++)
        {
            actualSum += nums[i];
        }
        
        return totalSum - actualSum;
    }
};