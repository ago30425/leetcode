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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stack;
        TreeNode *last = NULL;
        
        while (root || !stack.empty()) {
            if (root) {
                stack.push_back(root);
                root = root->left;
            } else {
                TreeNode *node = stack.back();
                
                if (node->right && node->right != last) {
                    root = node->right;
                } else {
                    stack.pop_back();
                    res.push_back(node->val);
                    last = node;
                }
            }
        }
        
        return res;
    }
};