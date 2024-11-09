class Solution {
public:
    void combination(vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>&ds,int index){
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        
        if(index >= candidates.size()){
            return;
        }
        
        //pick element
        if(candidates[index] <= target){
        ds.push_back(candidates[index]);
        combination(candidates,target - candidates[index],ans,ds,index);
        
        ds.pop_back();
        }
        //not pick
        combination(candidates,target,ans,ds,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        combination(candidates,target,ans,ds,0);
        
        return ans;
    }
};