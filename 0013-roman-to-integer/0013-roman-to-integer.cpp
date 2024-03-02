class Solution {
public:
    int romanToInt(string s) {
       // map<char,int>mp{{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500}};
        unordered_map <char,int> mp;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        int n=s.size();
        int ans=0;
        
//         for(int i=n-2;i>=0;i--)
//         {
            
//             if(mp[s[i-1]]<mp[s[i]])
//             {
//                 ans-=mp[s[i-1]];
//             }
//         }
//         return ans;
     
        
         for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]]){
            //for cases such as IV,CM, XL, etc...
            ans=ans-mp[s[i]];
        }
        else{
            ans=ans+mp[s[i]];
        }
    }
        return ans;
    }
};