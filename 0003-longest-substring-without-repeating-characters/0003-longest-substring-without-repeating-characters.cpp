class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         int ans = 0;
        
//         int n=s.size();
//         for(int i=0;i<n;i++)
//         {
//             int hash[256] = {0};
            
//             for(int j=i;j<n;j++)
//             {
//                 if(hash[s[j]] == 1) break;
                
//                 int len = j-i+1;
//                 ans= max(len,ans);
//                 hash[s[j]] = 1;
//             }
//         }
        
//         return ans;
        
        
        int l=0,r=0;
        int maxLen = 0;
        int hash[256] ;
        
        for (int i = 0; i < 256; ++i) {
            hash[i] = -1;
        }
       
        int n = s.size();
        
        if(s == "")
        {
            return 0;
        }
        while(r<n){
           if(hash[s[r]] != -1){
               if(hash[s[r]] >= l){
                   l= hash[s[r]] +1;
               }
           } 
            int len = r-l +1;
            maxLen = max(maxLen,len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};