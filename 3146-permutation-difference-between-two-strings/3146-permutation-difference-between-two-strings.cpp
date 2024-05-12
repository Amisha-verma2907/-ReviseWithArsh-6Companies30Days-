class Solution {
public:
    int findPermutationDifference(string s, string t) {
        //Tc:O(n2)
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<t.size();j++)
            {
                if(t[j] == s[i])
                {
                   sum=sum+abs(i-j); 
                }
            }
        }
        return sum;
    }
};