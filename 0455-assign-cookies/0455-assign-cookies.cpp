class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int m = g.size();
        int n = s.size();
        int count=0;
        int l=0,r=0;
        while(l<m && r<n)
        {
            if(s[r] >= g[l]){
                l++;
                count++;
            }
            r++;
        }
        return count;
    }
};