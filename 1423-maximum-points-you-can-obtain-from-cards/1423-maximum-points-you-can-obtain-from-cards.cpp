class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0, rsum=0;
        
        int maxSum=0;
        
        for(int i=0;i<k;i++)
        {
            lsum = lsum + cardPoints[i];
            maxSum=lsum;
        }
        
        int rIndex = cardPoints.size() - 1;
        
        for(int i=k-1;i>=0;i--)
        {
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rIndex];
            maxSum = max(maxSum,(lsum+rsum));
            rIndex--;
        }
        return maxSum;
    }
};