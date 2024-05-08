// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
        
//     }
// };


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       //Tc:O(2N + 2N) SC:O(N)
//          int n=nums.size();
//         vector<int>s(n);
//         stack<int>st;
//         for(int i=0; i<= 2*n-1; i++){
//             while(!st.empty() && (st.top() <= nums[i%n])){
//                 st.pop();
//             }
//             if(i<n){
//               if(st.empty() == false){
//                 s[i] = st.top();
//               }else{
//                   s[i] = -1;
//               }
               
//             }
//            st.push(nums[i%n]); 
//         }
//         return s;

        int n = nums.size();
        vector<int>v(n,-1);

        stack<int>st;
        for(int i = 2*n - 1; i >= 0; i--)
        {
            // we pop out all elements smaller than current element
            while(!st.empty() && (nums[i%n] >= st.top()))
            {
                st.pop();
            }

            // if stack is empty means no greater element is there
            // if not empty we make answer at that index equal to top element
            if(!st.empty() && (i < n))
            {
                v[i] = st.top();
            }

            st.push(nums[i%n]);
        }

       return v;
    }
};


// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         // TC: O(2N), SC: O(N)
//         vector<int> s(2 * nums.size(), -1);
//         stack<int> st;

//         for (int i = 0; i < 2 * nums.size(); ++i) {
//             while (!st.empty() && nums[st.top()] < nums[i % nums.size()]) {
//                 s[st.top()] = nums[i % nums.size()];
//                 st.pop();
//             }
//             st.push(i % nums.size());
//         }

//         return s;
//     }
// };
