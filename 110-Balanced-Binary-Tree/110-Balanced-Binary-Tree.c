/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int traverse_tree(struct TreeNode* root) {
    int rdepth, ldepth;

    if (!root)
        return 0;
    
    ldepth = traverse_tree(root->left);
    if (ldepth < 0)
        return -1;
    rdepth = traverse_tree(root->right);
    if (rdepth < 0)
        return -1;
    
    if (ldepth - rdepth > 1 ||
        ldepth - rdepth < -1)
        return -1;
    
    return MAX(ldepth, rdepth) + 1;
}

bool isBalanced(struct TreeNode* root){
    if (!root)
        return true;
    
    return !(traverse_tree(root) < 0);
}