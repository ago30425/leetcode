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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stack;
        
        while (root || !stack.empty()) {
            if (root) {
                stack.push_back(root);
                root = root->left;
            } else {
                root = stack.back();
                stack.pop_back();
                res.push_back(root->val);
                root = root->right;
            }
        }
        
        return res;
    }
};