class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
       int m= grid.size();
        int n=grid[0].size();
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int minVal = INT_MAX;
                if(i==0 && j==0)continue;
                if(i!=0) minVal=min(minVal,grid[i-1][j]);
                if(j!=0)minVal= min(minVal,grid[i][j-1]);
                ans = max(ans,grid[i][j] - minVal);
                grid[i][j] =min(grid[i][j],minVal);
            }
        }
        return ans;
    }
};