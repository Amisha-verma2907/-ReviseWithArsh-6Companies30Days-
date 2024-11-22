class Solution {
public:
    int count(string word1,string word2,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(word1[i] == word2[j]){
            return dp[i][j] = 0 + count(word1,word2,i-1,j-1,dp);
        }else{
            int insertO = 1 + count(word1,word2,i,j-1,dp);
            int deleteO = 1 + count(word1,word2,i-1,j,dp);
            int replace = 1+ count(word1,word2,i-1,j-1,dp);
            
            return dp[i][j] = min(insertO,min(deleteO,replace));
        }
    }
    int minDistance(string word1, string word2) {
       int n1= word1.size();
        int n2 = word2.size();
        
        vector<vector<int>>dp(n1,vector<int>(n2+1,-1));
        
       return count(word1,word2,n1-1,n2-1,dp);
    }
};