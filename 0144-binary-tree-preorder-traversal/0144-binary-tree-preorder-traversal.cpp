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
//     void preOrder(TreeNode* root,vector<int>&ans){
//         if(root == NULL){
//             return;
//         }
        
//         ans.push_back(root->val);
//         preOrder(root->left,ans);
//         preOrder(root->right,ans);
//     }
    vector<int> preorderTraversal(TreeNode* root) {
        //Recursive solution
       // vector<int>ans;
       // preOrder(root,ans);
       //  return ans;
        
        
        //Iterative solution
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        
        stack<TreeNode*>s;
       s.push(root);
       while(!s.empty()){
           root = s.top();
           s.pop();
           ans.push_back(root->val);
           if(root->right != NULL)
           {
               s.push(root->right);
           }
           if(root->left != NULL)
           {
               s.push(root->left);
           }
       }
        return ans;
    }
};