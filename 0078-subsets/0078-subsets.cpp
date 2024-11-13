class Solution {
public:
    void s(vector<int>& nums,int ind,vector<vector<int>> &ans,vector<int>&a){
        if(ind == nums.size()){
            ans.push_back(a);
            return;
        }
        
        //take
        a.push_back(nums[ind]);
        
        s(nums,ind+1,ans,a);
        
        a.pop_back();
        //not take
        s(nums,ind+1,ans,a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        s(nums,0,ans,a);
        
        return ans;
    }
};