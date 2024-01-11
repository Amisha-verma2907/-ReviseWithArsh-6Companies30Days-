class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int>mp;
        for(auto it:secret){
            mp[it]++;
        }
        string ans="";
        int cow=0,bull=0;
        for(int i=0;i<guess.size();i++)
        {
            if(guess[i]==secret[i] && mp[guess[i]]!=0)
            {
                bull++;
                mp[secret[i]]--;
            }
        }
    for(int i=0;i<guess.size();i++){
        if(guess[i]!=secret[i] && mp[guess[i]]!=0){
            cow++;
            mp[guess[i]]--;
                
        }
           }
               ans+=to_string(bull)+'A'+to_string(cow)+'B';
               return ans;
    }
};