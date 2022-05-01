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
    void _postorderTraversal(TreeNode* root, vector<int> &v) {
        if (!root)
            return;
        
        _postorderTraversal(root->left, v);
        _postorderTraversal(root->right, v);
        v.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        _postorderTraversal(root, res);
        
        return res;
    }
};