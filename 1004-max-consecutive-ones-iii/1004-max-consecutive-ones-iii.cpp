class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //brute force (Time limit exceeded)due to O(n2) = 10^5 * 10^5 = 10^10 not possible 
        
//         int maxLen = 0;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             int zeroes = 0;
//             for(int j=i;j<nums.size();j++)
//             {
//                 if(nums[j]==0){
//                 zeroes++;}
//                 if(zeroes <= k)
//                 {
//                     int len = j-i+1;
//                     maxLen =max(maxLen,len);
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         return maxLen;
        
        int l=0,r=0, maxLen=0;
        int zeroes = 0;
         while(r<nums.size()){
             if(nums[r] == 0)
             {
                 zeroes++;
             }
             
             if(zeroes <=k)
             {
                 int len = r-l+1;
                 maxLen = max(maxLen,len);
             }else{
                 while(zeroes > k ){
                     if(nums[l] == 0){
                         zeroes--;
                         
                     }
                     l++;
                     
                 }
             }
             
            r++; 
         }
        return maxLen;
    }
};