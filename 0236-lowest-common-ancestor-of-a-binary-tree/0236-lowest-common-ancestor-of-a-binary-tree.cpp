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
        // Base case: if the current node is null or matches either p or q, return the current node.
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        // Recursively search for LCA in the left and right subtrees.
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are non-null, it means p and q are found in both subtrees, so root is LCA.
        if (left != NULL && right != NULL) {
            return root;
        }
        
        // If only one of the subtrees contains p or q, return that one.
        return left != NULL ? left : right;
    }
};