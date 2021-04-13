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
#include <stdint.h>

/*
 * Runtime: 8 ms, faster than 94.19% .
 * Memory Usage: 21.6 MB, less than 65.45%.
 * 
 * Inorder traverse solution.
 */
class Solution {
    bool TreeTraverse(TreeNode* root, int64_t *lastVal) {
        if (!root)
            return true;
    
        if (!TreeTraverse(root->left, lastVal))
            return false;
        
        /*
         * There is no previous node for the leftmost node.
         * Therefore we need to check *lastVal.
         */
        if (*lastVal != INT64_MIN && *lastVal >= root->val)
            return false;
        
        *lastVal = root->val;
            
        return TreeTraverse(root->right, lastVal);
    }
    
public:
    /* time: O(n) */
    bool isValidBST(TreeNode* root) {
        int64_t lastVal = INT64_MIN;
        
        return TreeTraverse(root, &lastVal);
    }
};