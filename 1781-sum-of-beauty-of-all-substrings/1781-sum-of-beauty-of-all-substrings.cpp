class Solution {
public:
    int beauty(vector<int>&v){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<26;i++){
        maxi=max(maxi,v[i]);
          if(v[i]>=1){
              mini=min(mini,v[i]);
          }  
       }
        return maxi-mini;
    }
    int beautySum(string s) {
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            vector<int>v(26,0);
            for(int j=i;j<s.size();j++){
                v[s[j]-'a']++;
                res+=beauty(v);
            }
        }
        return res;
    }
};