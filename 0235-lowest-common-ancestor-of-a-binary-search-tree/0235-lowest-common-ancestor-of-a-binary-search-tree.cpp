/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        if(root->val == p->val){
            return ans;
        }
        while(root != NULL){
            if(p->val < root->val && q->val <root->val){
                root = root->left;
            }
            else if(p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }
            else{
                return root;
            }
            
        }
        return ans;
    }
};