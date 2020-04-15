/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//#define RECURSIVE

struct ListNode* reverseList(struct ListNode* head){
#ifdef RECURSIVE
    struct ListNode *newHead;

    if (head == NULL || head->next == NULL)
        return head;
        
    newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
#else   // Iterative
    struct ListNode *lastNode = NULL;
    struct ListNode *nextNode;
    
    while (head) {
        nextNode = head->next;
        head->next = lastNode;
        lastNode = head;
        head = nextNode;
    }
    
    return lastNode;
#endif
}