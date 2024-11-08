class Solution {
public:
    void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int>temp(n+1);
        
//         int j = 0;
        
//         for(int i=k+1;i<n;i++)
//         {
//             temp[j] = nums[i];
//             j++;
//         }
        
//         for(int i=0;i<=k;i++)
//         {
//             temp[j] = nums[i];
//         }
        
//         for(int i=0;i<temp.size();i++)
//         {
//             nums[i] = temp[i];
//         }
        int n = nums.size();
        
        k = k%n;
        reverse(nums.begin(),nums.end());
        
        reverse(nums.begin(),nums.begin()+ k);
        
        reverse(nums.begin()+k,nums.end());
        
        
    }
};