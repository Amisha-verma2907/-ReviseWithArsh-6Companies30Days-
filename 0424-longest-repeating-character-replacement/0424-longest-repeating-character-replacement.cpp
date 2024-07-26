class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        for(int i=0;i<s.size();i++)
        {
            int maxFreq = 0;
            int hash[256] = {0};
            for(int j=i;j<s.size();j++)
            {
                hash[s[j] - 'A']++;
                maxFreq =  max(maxFreq, hash[s[j]- 'A']);
                
                int len = j-i+1;
                int lenReverse = len - maxFreq;
                if(lenReverse <= k)
                {
                  maxLen = max(maxLen,j-i+1);  
                }else{
                    break;
                }
            }
            
        }
        return maxLen;
    }
    
};