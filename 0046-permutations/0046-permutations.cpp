class Solution {
public:
    void permutation(vector<int>& nums,vector<vector<int>> &ans, vector<int> &v,int freq[]){
        if(v.size() == nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i]){
                freq[i]=1;
                v.push_back(nums[i]);
                permutation(nums,ans,v,freq);
                v.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i] = 0 ;         
                 }
        permutation(nums,ans,v,freq);
        return ans;
     }
};