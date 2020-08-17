/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define RECURSIVE

#ifdef RECURSIVE
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *newHead, *nextNewHead;
    
    if (head == NULL || head->next == NULL)
        return head;
    
    newHead = head->next;
    head->next = newHead->next;
    newHead->next = head;
    
    nextNewHead = swapPairs(head->next);
    
    head->next = nextNewHead;
    
    return newHead;
}
#else
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *prevNode, *curNode, *nextNode;
    int i = 0;
    
    if (head == NULL || head->next == NULL)
        return head;
    
    prevNode = NULL;
    curNode = head;
    head = head->next;
    while (curNode && curNode->next) {
        nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = curNode;
        
        if (prevNode)
            prevNode->next = nextNode;
        
        prevNode = curNode;
        curNode = curNode->next;
    }
    
    return head;
}
#endif