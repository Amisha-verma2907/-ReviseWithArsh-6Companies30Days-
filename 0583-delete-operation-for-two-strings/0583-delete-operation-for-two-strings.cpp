class Solution {
public:
    int common(string & text1,string& text2){
        int n1 = text1.size();
        int n2 = text2.size();
        
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=0;i<=n1;i++)
        {
            dp[i][0] = 0;
        }
        
        for(int j=0;j<=n2;j++)
        {
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n1][n2];
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        int totalSize = n1+n2;
        
        
        int c = common(word1,word2);
        
        return totalSize - (c*2);
    }
};