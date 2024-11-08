class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int>temp(n);
        
        int j = 0;
        
        for(int i=0;i<k;i++)
        {
            temp[i] = nums[n-k+i];
        }
        
        for(int i=0;i<n-k;i++)
        {
            temp[i + k] = nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            nums[i] = temp[i];
        }
        
        
        
//         int n = nums.size();
        
//         k = k%n;
//         reverse(nums.begin(),nums.end());
        
//         reverse(nums.begin(),nums.begin()+ k);
        
//         reverse(nums.begin()+k,nums.end());
        
        
    }
};