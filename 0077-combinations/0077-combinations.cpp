class Solution {
public:
    void combination(int n,int k,int start,vector<vector<int>>&ans,vector<int>&a){
        if(k==0)
        {
            ans.push_back(a);
            return;
        }
        
        for(int i=start;i<=n;i++)
        {
            a.push_back(i);
            combination(n,k-1,i + 1,ans,a);
            
            a.pop_back();            
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>a;
    
        combination(n,k,1,ans,a);
        
        return ans;
    }
};