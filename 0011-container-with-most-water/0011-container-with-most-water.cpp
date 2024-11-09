class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //to make each operation is only be exceeded to 10^8 if more than that then TLE will occur as in below approach there is TC: O(n2) ~ 10^10
//         int w = 0;
//         int ht = 0;
        
//         int n = height.size();
//         int maxi = INT_MIN;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 w = j-i;
//                 ht = min(height[i],height[j]);
                
//                 maxi = max(maxi,w*ht);
//             }
//         }
        
//         return maxi;
        
        
        //optimal approach -> sliding window (two pointer approach)
        
        int i = 0;
        int j = height.size() -1;
        
        int ht = 0 ;
        int w = 0;
        int maxi = INT_MIN;
        
        
        while(i<j)
        {
            ht = min(height[i],height[j]);
            w = j-i;
            
            maxi = max(maxi,ht*w);
            height[i]<height[j] ? i++ : j--;
        }
        
        return maxi;
    }
};