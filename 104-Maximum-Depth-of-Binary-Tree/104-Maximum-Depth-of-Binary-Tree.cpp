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

/* Time complexity: O(n) */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int left_max, right_max;
        
        if (!root)
            return 0;
        
        left_max = maxDepth(root->left);
        right_max = maxDepth(root->right);
        
        return max(left_max, right_max) + 1;
    }
};