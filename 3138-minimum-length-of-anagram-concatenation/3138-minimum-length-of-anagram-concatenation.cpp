class Solution {
public:
    bool ok(string &s,int len)
    {
        int n=s.size();
        int mainFreq[26] ={0};
        for(int i=0;i<len;i++){
            mainFreq[s[i] - 'a']++;
        }
        
        for(int i=len;i<n;i+=len){
        int otherFreq[26] ={0};
            for(int j=i;j<i+len;j++)
            {
               otherFreq[s[j] - 'a']++; 
            }
            for(int j= 0;j<26 ; j++)
            {
                if(mainFreq[j] != otherFreq[j])
                {
                    return false;
                }
            }
        }
        return true;
        
    }
    int minAnagramLength(string s) {
        int n=s.size();
      for(int len =1;len<=n;len++)
      {
          if(n % len == 0 && ok(s,len)){
              return len;
          }
      }
        return n;
    }
};