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
    // void postOrder(TreeNode* root,vector<int>&ans){
    //     if(root == NULL)
    //     {
    //         return;
    //     }
    //     postOrder(root->left,ans);
    //     postOrder(root->right,ans);
    //     ans.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // postOrder(root,ans);
        // return ans;
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        
        st1.push(root);
        while(!st1.empty()){
              root = st1.top();
              st1.pop();
              st2.push(root);
              if(root->left != NULL){
              st1.push(root->left);
              }
              if(root->right != NULL){
              st1.push(root->right);
              }
        }
        
        while(!st2.empty()){
            TreeNode * top = st2.top();
            st2.pop();
            ans.push_back(top->val);
        }
        return ans;
        
    }
};