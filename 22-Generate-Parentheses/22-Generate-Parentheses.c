

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void TreeTraverse(
    char ***res,
    int *returnSize,
    char *parentheses,
    int p,
    int sum,
    int depth,
    const int maxDepth);
    
char ** generateParenthesis(int n, int* returnSize){
    char **res = NULL, *subRes, *parentheses;
    int maxDepth = n * 2 - 1;
    
    if (n == 0)
        return NULL;

    *returnSize = 0;
    parentheses = (char *)malloc(sizeof(char) * (maxDepth + 2));
    if (!parentheses)
        return res;
    
    TreeTraverse(&res, returnSize, parentheses, 1, 0, 0, maxDepth);

    return res;
}

void TreeTraverse(
    char ***res,
    int *returnSize,
    char *parentheses,
    int p,
    int sum,
    int depth,
    const int maxDepth)
{
    sum += p;
    if (sum < 0)
        return;
    
    parentheses[depth] = (p == 1) ? '(' : ')';
    if (depth >= maxDepth) {
        if (sum == 0) {
            char **newRes, *subRes;

            parentheses[depth + 1] = '\0';
            (*returnSize)++;
            
            newRes = (char **)realloc(*res, sizeof(char *) * (*returnSize));
            if (newRes) {
                *res = newRes;
            
                subRes = (char *)malloc(sizeof(char) * (maxDepth + 2));
                if (subRes) {
                    strncpy(subRes, parentheses, maxDepth + 2);
                    (*res)[*returnSize - 1] = subRes;
                } else {
                    /* TODO: Error handling. */
                }
            } else {
                /* TODO: Error handling. */
            }
        }
            
        return;
    }

    TreeTraverse(res, returnSize, parentheses, 1, sum , depth + 1, maxDepth);
    TreeTraverse(res, returnSize, parentheses, -1, sum, depth + 1, maxDepth);

    return;
}