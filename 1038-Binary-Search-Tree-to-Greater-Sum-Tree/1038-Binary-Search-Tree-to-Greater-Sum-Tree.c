/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* bstToGst(struct TreeNode* root){
    int sum = 0;
    
    TreeTraverse(root, &sum);
    
    return root;
}

void TreeTraverse(struct TreeNode* root, int *sum) {
    if (root == NULL) {
        return;
    }

    TreeTraverse(root->right, sum);
    root->val += *sum;
    *sum = root->val;
    TreeTraverse(root->left, sum);
}