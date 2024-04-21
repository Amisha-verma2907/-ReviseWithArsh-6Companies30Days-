class Solution {
public:
    void combination(vector<vector<int>>&ans,vector<int>&v,vector<int>& candidates,int target,int ind){
        if(ind == candidates.size()){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        if(candidates[ind]<=target){
        v.push_back(candidates[ind]);
        combination(ans,v,candidates,target-candidates[ind],ind);
        v.pop_back();
        }
        combination(ans,v,candidates,target,ind+1);      
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        combination(ans,v,candidates,target,0); //0->index
        return ans;
        
    }
};