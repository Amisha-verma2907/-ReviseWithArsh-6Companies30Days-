class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int hash[256] = {0};
            
            for(int j=i;j<n;j++)
            {
                if(hash[s[j]] == 1) break;
                
                int len = j-i+1;
                ans= max(len,ans);
                hash[s[j]] = 1;
            }
        }
        
        return ans;
    }
};