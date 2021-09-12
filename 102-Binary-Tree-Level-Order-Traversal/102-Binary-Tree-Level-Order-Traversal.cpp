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
    void preorderTraverse(TreeNode* root, int level, vector<vector<int>> &v) {
        if (!root)
            return;
        
        if (v.size() < level + 1) {
            vector<int> tempv;
            v.push_back(tempv);
        }

        v[level].push_back(root->val);
        preorderTraverse(root->left, level + 1, v);
        preorderTraverse(root->right, level + 1, v);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        
        preorderTraverse(root, 0, v);
        
        return v;
    }
};