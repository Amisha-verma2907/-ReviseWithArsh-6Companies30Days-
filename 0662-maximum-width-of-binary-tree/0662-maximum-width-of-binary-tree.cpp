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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        } 

        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            unsigned long long mmin = q.front().second;
            int size = q.size();
            unsigned long long first, end;

            for (int i = 0; i < size; i++) {
                unsigned long long cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = cur_id;
                if (i == size - 1) end = cur_id;

                if (node->left) {
                    q.push({node->left, 2 * cur_id + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * cur_id + 2});
                }
            }

            ans = max(ans, static_cast<int>(end - first + 1));
        }

        return ans;
    }
};
