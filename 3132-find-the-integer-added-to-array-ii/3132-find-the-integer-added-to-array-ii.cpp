class Solution {
public:
    bool check(vector<int>& nums1, vector<int>& nums2,int diff){
        int count =0 ;
        int j=0;
        int n=nums1.size();
        int m = nums2.size();
        for(int i=0;i<n && j<m;i++){
            if(nums1[i] + diff != nums2[j]){
                count++;
            }else{
                j++;
            }
        }
        return count<=2;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
//         int i=0;
//        while (i<2){
//            int mini=*min_element(nums1.begin(),nums1.end());
//            // int elementToRemove = 5; 
  
//            // Remove the element using erase function and iterators 
//            auto it = std::find(nums1.begin(), nums1.end(), 
//                         mini); 
  
//           // If element is found found, erase it 
//           if (it != nums1.end()) { 
//             nums1.erase(it); 
//           } 
//        }
//         int mini1 = *min_element(nums1.begin(),nums1.end());
//         int mini2 = *min_element(nums2.begin(),nums2.end());
//         int diff = mini2-mini1;
//         return diff;
        
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        
        // int mini1 = nums1[2];
        // int mini2 = nums2[0];
        // int diff = mini2-mini1;
        // return diff;
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int mini = INT_MAX;
        for(int i=0;i<3;i++)
        {
            int diff = nums2[0] - nums1[i];
            if(check(nums1,nums2,diff)){
                mini=min(mini,diff);
            }
        }
        return mini;
        
    }
};