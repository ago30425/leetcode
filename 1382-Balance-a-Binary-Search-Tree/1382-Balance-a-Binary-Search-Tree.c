/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
 * If arr is NULL, just calculate the number of nodes in tree.
 */
void Tree2Array(struct TreeNode* root, struct TreeNode **arr, int *nodeCount)
{
    if (!root) {
        return;
    }
    
    Tree2Array(root->left, arr, nodeCount);
    
    if (arr)
        arr[(*nodeCount)++] = root;
    else
        (*nodeCount)++;
    
    Tree2Array(root->right, arr, nodeCount);
}

struct TreeNode* Array2Tree(struct TreeNode **arr, int left, int right)
{
    struct TreeNode *tmpNode;
    int mid;
    
    if (right < left)
        return NULL;
    
    mid = (left + right) / 2;
    tmpNode = arr[mid];
    tmpNode->left = Array2Tree(arr, left, mid - 1);
    tmpNode->right = Array2Tree(arr, mid + 1, right);
    
    return tmpNode;
}

struct TreeNode* balanceBST(struct TreeNode* root){
    struct TreeNode **array;
    int nodeCount = 0;
    
    Tree2Array(root, NULL, &nodeCount);

    array = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * nodeCount);
    if (!array)
        return root;
    
    nodeCount = 0;
    Tree2Array(root, array, &nodeCount);
    
    root = Array2Tree(array, 0, nodeCount - 1);
    
    free(array);

    return root;
}