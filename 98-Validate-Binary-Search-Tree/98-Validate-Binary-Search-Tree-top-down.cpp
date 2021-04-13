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
#include <cstdint>

/*
 * Runtime: 8 ms, faster than 86.60%.
 * Memory Usage: 21.6 MB, less than 73.49%.
 */
class Solution {
    bool TreeTraverse(TreeNode* root, int64_t min, int64_t max) {
        if (!root)
            return true;
        
        if (root->val <= min || root->val >= max)
            return false;
        
        return (TreeTraverse(root->left, min, root->val) &&
                TreeTraverse(root->right, root->val, max));
    }
    
public:
    /* time: O(n) */
    bool isValidBST(TreeNode* root) {
        return TreeTraverse(root, INT64_MIN, INT64_MAX);
    }
};