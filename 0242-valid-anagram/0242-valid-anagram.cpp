class Solution {
public:
    bool isAnagram(string s, string t) {
//        unordered_map<char,int>mp1;
//         if(s.size()!=t.size())
//         {
//             return false;
//         }
//         for(int i=0;i<s.size();i++)
//         {
//             mp1[s[i]]++;
//         }
//         for(int i=0;i<t.size();i++)
//         {
//             mp1[t[i]]--;
//         }
//         for(auto i:mp1)
//         {
//             if(i.second!=0)
//             {
//                 return false;
//             }
//         }
//         return true;
        
        unordered_map<char,int>mp;
        
        for(char it: s)
        {
            mp[it]++;
        }
        
        for(char it:t)
        {
            if(mp.find(it) != mp.end() )
            {
                mp[it]--;
                if(mp[it] == 0){
                mp.erase(it);
            }
            }
            else{
                return false;
            }
        }
        
        
        return mp.empty();
        
    }
};