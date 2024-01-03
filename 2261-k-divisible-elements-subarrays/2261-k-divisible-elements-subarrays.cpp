class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string>st;
        //set<vector<int>>st;
        for(int i=0;i<nums.size();i++)
        {
             int cnt=0;
            string temp;
            for(int j=i;j<nums.size();j++)
            {
                temp.push_back(nums[j]);
                if(nums[j]%p==0)
                {
                    cnt++;
                }
                if(cnt>k)
                {
                    break;
                }
                st.insert(temp);
            }
        }
        return st.size();
        
    
    }
};