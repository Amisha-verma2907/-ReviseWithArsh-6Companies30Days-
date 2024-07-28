class Solution {
public:
    int func(vector<int>& nums, int goal)
    {
        int l=0,r=0,cnt=0;
        int sum=0;
        if(goal<0)return 0;
        while(r<nums.size()){
            if(nums[r] == 1)
            {
               sum++; 
            }
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //time-limit-exceed O(n2)
//        int count=0;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             int c1=0;
//             for(int j=i;j<nums.size();j++)
//             {
//                 if(nums[j]==1)
//                 {
//                    c1++; 
//                 }
//                 if(c1>goal)
//                 {
//                     break;
//                 }
//                 if(c1==goal)
//                 { 
//                     count++;
//                 }
//             }
//         }
//         return count;
        
        
        //better approach
        
        // int count=0;
        // int c1=0;
        // int l=0,r=0;
        // while(r<nums.size())
        // {
        //     if(nums[r] == 1)
        //     {
        //         c1++;
        //     }
        //     if(c1>goal)
        //     {
        //         while(c1!=2){
        //             l++;
        //             c1--; 
        //         }
        //     }
        //     if(c1==goal)
        //     {
        //         count++;
        //     }
        //     r++;
        // }
        // return count;
        
        
        return (func(nums,goal) - func(nums,goal-1));
    }
};