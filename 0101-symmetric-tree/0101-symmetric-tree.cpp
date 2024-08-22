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
    bool symmetric(TreeNode* root1,TreeNode* root2){
        if(root1 == NULL  || root2 == NULL){
            return root1== root2;
        }
        if(root1->val != root2->val){
            return false;
        }
        
        return symmetric(root1->left,root2->right)&&symmetric(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
       
    //wrong approach
//     if(root->left->val != root->right->val){
//         return false;
//     }
            
//     if(root->left != NULL){
//         isSymmetric(root->left);}
            
//     if(root->right != NULL){
//         isSymmetric(root->right);
//     }
        
//     return true;
        
        //correct approach
        
        if(root == NULL){
           return true;
        }
         return symmetric(root->left,root->right);
    }
};