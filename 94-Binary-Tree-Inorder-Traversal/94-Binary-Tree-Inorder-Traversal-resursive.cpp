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
private:
    void _inorderTraversal(TreeNode* root, vector<int> &v) {
        if (!root)
            return;
        
        _inorderTraversal(root->left, v);
        v.push_back(root->val);
        _inorderTraversal(root->right, v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
       
        _inorderTraversal(root, res);
        
        return res;
    }
};