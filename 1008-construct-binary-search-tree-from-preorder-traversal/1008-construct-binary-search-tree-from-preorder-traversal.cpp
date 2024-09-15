/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode* ans = new TreeNode(preorder.top());
        
//         preorder.pop();
//         while(!preorder.empty()){
//             int topElement = preorder.top();
//             preorder.pop();
            
//             if(topElement < ans->val){
//                 ans->left = new TreeNode(topElement);
//             }else{
//                 ans->right = new TreeNode(topElement);
//             }
//         }
        
//         return ans;
        
        
        //TC: O(3N) ~ O(N) ans SC: O(1)
        
        
        int i=0;
        return build(preorder,i,INT_MAX);
    }
    
    TreeNode* build(vector<int>& preorder,int& i,int maxi){
        if(i == preorder.size() || preorder[i]>maxi){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder,i,root->val);
        root->right = build(preorder,i,maxi);
        
        return root;
    }
};