class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() -1;
        
        while(s<e)
        {
            int mid = s + (e-s)/2;
            
            if(nums[mid] > nums[e]){
                s = mid +1;
            }else if(nums[mid] < nums[s]){
                e= mid;
            }else{
                e--;
            }
        }
        
        return nums[s];
    }
};