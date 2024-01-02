class Solution {
public:
    void solve(string digits,int index,vector<string>&ans,string mapping[],string output){
        if(index>=digits.length())
        {
            ans.push_back(output);
            return;
        }
        
        int number = digits[index] -'0';
        string value = mapping[number];
        
        for(int i=0;i<value.length();i++)
        {
            output.push_back(value[i]);
            solve(digits,index+1,ans,mapping,output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        
        if(digits.length()==0){
            return ans;
        }
        string output="";
        int index=0;
        
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,index,ans,mapping,output);
        return ans;
    }
};