class Solution {
public:
    int characterReplacement(string s, int k) {
        // brute force O(n2)
//         int maxLen = 0;
//         for(int i=0;i<s.size();i++)
//         {
//             int maxFreq = 0;
//             int hash[256] = {0};
//             for(int j=i;j<s.size();j++)
//             {
//                 hash[s[j] - 'A']++;
//                 maxFreq =  max(maxFreq, hash[s[j]- 'A']);
                
//                 int len = j-i+1;
//                 int lenReverse = len - maxFreq;
//                 if(lenReverse <= k)
//                 {
//                   maxLen = max(maxLen,j-i+1);  
//                 }else{
//                     break;
//                 }
//             }
            
//         }
//         return maxLen;
        
        //better approach using sliding window O(n)
        
        int l=0, r=0, maxLen = 0;
        unordered_map<char,int>mp;
        int maxFreq = 0;
        while(r<s.size())
        { 
            mp[s[r]]++;
            maxFreq = max(maxFreq,mp[s[r]]);
            
            int lenReverse = (r-l+1) - maxFreq;
            if(lenReverse<=k)
            {
                maxLen=max(maxLen,r-l+1);
            }else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxLen;
    }
    
};