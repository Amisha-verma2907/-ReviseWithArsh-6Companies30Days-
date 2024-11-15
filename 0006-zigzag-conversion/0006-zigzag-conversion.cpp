class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ans(numRows);
        
        if(numRows  == 1)
        {
            return s;
        }
        
        bool flag= false;
        
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            ans[j]+=s[i];
            
            if(j == 0 || j == numRows-1)
            {
                flag = !flag;
            }
            
            if(flag)
            {
                j++;
            }else{
                j--;
            }
        }
        
        string str;
        for(auto it:ans)
        {
            str += it;
        }
        
        return str;
    }
};