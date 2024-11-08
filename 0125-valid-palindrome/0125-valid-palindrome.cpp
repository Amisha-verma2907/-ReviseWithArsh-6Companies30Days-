class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        
        for(int i=0;i<s.size();i++)
        {
           if(isalnum(s[i])){
               temp+=tolower(s[i]);
           } 
        }
        
        reverse(temp.begin(),temp.end());
        
        int i=0,j = temp.size()-1;
        while(i<s.size() && j>=0){
            if(temp[i] != temp[j]){
                return 0;
            }
            j--;
            i++;
        }
        
        return 1;
    }
};