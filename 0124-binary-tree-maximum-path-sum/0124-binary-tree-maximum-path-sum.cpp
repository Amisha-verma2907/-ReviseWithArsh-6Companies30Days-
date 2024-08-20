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
    int maxPath(TreeNode* &root,int &maxi){
        if(root == NULL){
            return 0;
        }
        
        int leftSum = max(0,maxPath(root->left,maxi));
        // if(leftSum<0){
        //     return 0;
        // }
        int rightSum = max(0,maxPath(root->right,maxi));
//         if(rightSum<0){
//             return 0;
//         }
        
        maxi = max(maxi,leftSum+rightSum+root->val);
        
        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root,maxi);
        return maxi;
    }
};