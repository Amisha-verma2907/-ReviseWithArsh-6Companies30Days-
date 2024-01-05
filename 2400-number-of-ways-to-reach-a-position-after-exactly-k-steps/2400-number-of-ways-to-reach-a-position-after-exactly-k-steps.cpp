class Solution {
public:
    int mod=1000000007;
    int totalNoOfways(vector<vector<int>> & dp,int s, int e, int k){
        if(k==0)
        {
            if(s==e)
            {
                return 1;
            }else{
                return 0;
            }
        }
        
        if(dp[s+1000][k]!=-1)
        {
            return dp[s+1000][k]%mod;
        }
        
        int op1= totalNoOfways(dp,s+1,e,k-1)%mod;
        int op2 =totalNoOfways(dp,s-1,e,k-1)%mod;
        
        return dp[s+1000][k] = (op1+op2)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3001,vector<int>(k+1,-1));
        return totalNoOfways(dp,startPos,endPos,k)%mod;
    }
};