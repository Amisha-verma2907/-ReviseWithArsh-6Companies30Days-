class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
//         int totalProduct = 1;
//         bool isZero = false;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i] == 0)
//             {
//                 isZero = true;
//             }
//             if(nums[i] != 0){
//             totalProduct *= nums[i];
//             }
//         }
        
        
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]  == 0){
//                 nums[i] = totalProduct;
//             }
//             else if(isZero)
//             {
//                 nums[i] = 0;
//             }else{
//             nums[i] = totalProduct / nums[i];
//             }
            
//         }
        
//         return nums;
        
        
        int n = nums.size();
        
        int productLeft = 1;
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        for(int i=0;i<nums.size();i++)
        {
            left[i] = productLeft;
            productLeft *= nums[i];
        }
        
        int productRight = 1;
        
        for(int i=n-1;i>=0;i--)
        {
            right[i] = productRight;
            productRight *=nums[i];
        }
        
        vector<int>result(n,0);
        
        for(int i=0;i<n;i++)
        {
            result[i] = left[i] * right[i];
        }
        
        return result;
        
    }
};