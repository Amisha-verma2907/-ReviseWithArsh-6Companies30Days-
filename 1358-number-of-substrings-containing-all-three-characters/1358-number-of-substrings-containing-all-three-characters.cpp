class Solution {
public:
    int numberOfSubstrings(string s) {
        //brute force O(n2)  space: O(1)
//         int count=0;
        
//         for(int i=0;i<s.size();i++)
//         {
//             int hash[3] = {0};
//             for(int j=i;j<s.size();j++)
//             {
//                 hash[s[j] - 'a'] = 1;
//                 if(hash[0] + hash[1] + hash[2] == 3)
//                 {
//                     count++;
//                 }
                
//             }
//         }
//         return count;
        
        //better approach 
//         int count=0;
        
//         for(int i=0;i<s.size();i++)
//         {
//             int hash[3] = {0};
//             for(int j=i;j<s.size();j++)
//             {
//                 hash[s[j] - 'a'] = 1;
//                 if(hash[0] + hash[1] + hash[2] == 3)
//                 {
//                     count+=(s.size()-j);
//                     break;
//                 }
                
//             }
//         }
//         return count;
        
        
        //optimal approach O(n) space : O(1)
        
        int lastSeen[3] = {-1,-1,-1};
        
        int cnt=0;
        
        for(int i=0;i<s.size();i++)
        {
            lastSeen[s[i] - 'a'] = i;
            
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            {
                cnt = cnt+ (1 + min(lastSeen[0],min(lastSeen[1],lastSeen[2])));
            }
        }
        
        return cnt;
    }
};