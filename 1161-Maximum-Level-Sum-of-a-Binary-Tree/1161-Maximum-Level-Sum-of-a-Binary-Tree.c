/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
 * This is slow solution.
 * Runtime: 540 ms, faster than 6.25% of C online submissions
 * Memory Usage: 61.1 MB, less than 100.00% of C online submission
 */
typedef struct queue {
    int level;
    struct TreeNode *tree_node;
    struct queue *next;
} queue_t;

queue_t* queue_pop(queue_t **queue) {
    queue_t *q;
    
    q = *queue;
    if (q) {
        *queue = (*queue)->next;
    }
    
    return q;
}

void queue_push(queue_t **queue, queue_t *node) {
    queue_t *cur;

    if (!node)
        return;

    if (!(*queue)) {
        *queue = node;
        return;
    }

    cur = *queue;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    
    cur->next = node;
}

queue_t* queue_new_node(int level, struct TreeNode *tree_node) {
    queue_t *node;
    
    if (!tree_node)
        return NULL;
    
    node = (queue_t *)malloc(sizeof(queue_t));
    
    if (node) {
        node->level = level;
        node->tree_node = tree_node;
        node->next = NULL;
    }
    
    return node;
}

int maxLevelSum(struct TreeNode* root) {
    queue_t *queue, *node;
    queue_t *lnode, *rnode;
    int level, sum, max, level_max;

    if (!root)
        return 0;
    
    level_max = level = 1;
    sum = 0;
    max = root->val;
    
    queue = queue_new_node(level, root);
    while (queue) {
        node = queue_pop(&queue);
        
        if (node->level == level) {
            sum += node->tree_node->val;
        } else {
            if (sum > max) {
                max = sum;
                level_max = level;
            }
            sum = node->tree_node->val;
            ++level;
        }

        lnode = queue_new_node(node->level + 1, node->tree_node->left);
        if (lnode)
        {
            queue_push(&queue, lnode);
        }

        rnode = queue_new_node(node->level + 1, node->tree_node->right);
        if (rnode)
        {
            queue_push(&queue, rnode);
        }

        free(node);
    }
    
    return level_max;
}