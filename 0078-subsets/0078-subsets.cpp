class Solution {
public:

//     void elements(vector<int> nums,int p , int n ,vector<int> temp , vector<vector<int>> &ans){

//         if(p==n){
//             ans.push_back(temp);
//             return ;
//         }
//         elements(nums,p+1,n,temp,ans);
//         temp.push_back(nums[p]);
//         elements(nums,p+1,n,temp,ans);


//     }
    void print(vector<int> nums,vector<int> ele,vector<vector<int>>&ans,int ind){
        if(ind == nums.size()){
            ans.push_back(ele);
            return;
        }
        ele.push_back(nums[ind]);
        print(nums,ele,ans,ind+1);
        ele.pop_back();
        print(nums,ele,ans,ind+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // int n=nums.size();
        // int p=0;
        // vector<vector<int>> ans;
        // vector<int> temp;
        // elements(nums,p,n,temp,ans);
        // return ans;
        
        vector<vector<int>>ans;
        vector<int>ele;
        int n=nums.size();
        print(nums,ele,ans,0);
        return ans;

    }
};