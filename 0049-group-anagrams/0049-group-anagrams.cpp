class Solution {
public:
    string generateFrequency(string s){
       int hash[256] = {0};
        
       for(int i=0;i<s.size();i++)
       {
           hash[s[i]]++;
       }
        
        string t;
        for(int i = 0;i<256;i++)
        {
            if(hash[i] > 0)
            {
                t+= (char)i;
                t+=to_string(hash[i]);
            }
        }
        
        return t;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>ans;
        
        unordered_map<string,vector<string>>mp;
        
        for(auto it:strs){
            string m = generateFrequency(it);
            
            mp[m].push_back(it);
        }
        
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};



//         vector<vector<string>>ans;
        
//         unordered_map<string,vector<string>>mp;
        
//         for(auto it:strs){
//             string sortedString = it;
            
//             sort(sortedString.begin(),sortedString.end());
            
//             mp[sortedString].push_back(it);
            
//         }
        
//         for(auto it: mp)
//         {
//             ans.push_back(it.second);
//         }
        
//         return ans;
        