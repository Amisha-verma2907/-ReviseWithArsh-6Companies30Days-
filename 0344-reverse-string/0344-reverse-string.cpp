class Solution {
public:
//     void reverse(vector<char>&s,int left,int right){
//         if(left>=right){
//             return;
//         }
        
//         swap(s[left],s[right]);
//         reverse(s,left+1,right-1);
//     }
    void reverseString(vector<char>& s) {
        // int n = s.size();
        // reverse(s,0,n-1);
        
        int n = s.size();
        
        reverse(s.begin(),s.end());
    }
};