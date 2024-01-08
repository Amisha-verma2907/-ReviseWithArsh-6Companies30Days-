class Solution {
public:
    int solve(int n,int k){
        if(n==1){
            return 0;
        }
        return (solve(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        //in modulus 0 based indexing is there therefore we need to add 1
        int ans=solve(n,k)+1;
        return ans;
    }
};