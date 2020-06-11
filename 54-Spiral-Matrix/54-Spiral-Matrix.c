

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int vector[4][2] = {
    { 1,  0},
    { 0,  1},
    {-1,  0},
    { 0, -1}
};

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int i;
    int pos[2] = {-1, 0};
    int dir, toggle;
    int *res;
    int n;
    int pathLen[2];

    /* check parameters */
    if (matrixSize == 0)
    {
        if (returnSize)
            *returnSize = 0;

        return NULL;
    }
    
    if (returnSize) {
        if (matrixColSize) {
            *returnSize = *matrixColSize * matrixSize;
            pathLen[0] = *matrixColSize;
            pathLen[1] = matrixSize - 1;
        }
        else {
            *returnSize = 0;
            return NULL;
        }
    } else {
        return NULL;
    }
    
    res = (int *)malloc((*returnSize) * sizeof(int));
    if (!res) {
        *returnSize = 0;
        return NULL;
    }

    dir = 0;
    n = 0;
    toggle = 0;
    while (n < *returnSize) {
        for (i = 0; i < pathLen[toggle]; ++i) {
            pos[0] += vector[dir][0];
            pos[1] += vector[dir][1];
            res[n++] = matrix[pos[1]][pos[0]];
        }
        
        --pathLen[toggle];
        dir = (dir + 1) % 4;
        toggle = dir % 2;
    }

    return res; 
}