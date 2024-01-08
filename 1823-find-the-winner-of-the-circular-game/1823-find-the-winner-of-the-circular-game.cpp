class Solution {
public:
    int solve(vector<int>&dp,int n,int k){
        if(n==1){
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=(solve(dp,n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        //in modulus 0 based indexing is there therefore we need to add 1
        vector<int>dp(n+1,-1);
        int ans=solve(dp,n,k)+1;
        return ans;
    }
};