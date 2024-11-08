class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         int maxi = INT_MIN; // Initialize with the smallest possible integer
        
//         for (int i = 0; i < nums.size(); i++) {
//             int product = 1; // Start a new product for each subarray beginning at index i
//             for (int j = i; j < nums.size(); j++) {
//                 product *= nums[j];
//                 maxi = max(maxi, product); // Update maxi with the current product if it’s larger
//             }
//         }
        
//         return maxi;
        
        
        
        int minProduct = nums[0];
        int maxProduct = nums[0];
        int result  = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if (nums[i] < 0) {
                swap(maxProduct, minProduct);
            }
            
            minProduct = min(nums[i],nums[i]*minProduct);
            maxProduct = max(nums[i],nums[i]*maxProduct);
            
            result = max(result,maxProduct);
        }
        
        
        return result;
        
        
    }
};