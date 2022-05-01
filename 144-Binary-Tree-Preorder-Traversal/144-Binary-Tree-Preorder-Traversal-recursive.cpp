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
private:
    void _preorderTraversal(TreeNode* root, vector<int> &v) {
        if (!root)
            return;
        
        v.push_back(root->val);
        _preorderTraversal(root->left, v);
        _preorderTraversal(root->right, v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        _preorderTraversal(root, res);
        
        return res;
    }
};