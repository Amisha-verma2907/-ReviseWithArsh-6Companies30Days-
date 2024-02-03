class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
//          map<string,int> arr;
//         if(s.size() < 10)
//             return {};
//         for(int i = 0; i < s.size()-9; ++i){
//             string str = s.substr(i,10);
//             arr[str]++;
//         }
        
//         vector<string> ans;
//         for(auto x: arr){
//             if(x.second > 1)
//             ans.push_back(x.first);
//         }
        
//         return ans;
    vector<string>v;
        if(s.length()<=10)
        {
            return v;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<=s.length()-10;i++)
        {
            string h = s.substr(i,10);
            mp[h]++;
        }
        for(auto x:mp)
        {
            if(x.second>1)
            {
                v.push_back(x.first);
                
            }
        }
        return v;
    }
};