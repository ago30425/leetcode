/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;
    int hasCycle = 0;
    
    slow = fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            hasCycle = 1;
            break;
        }
    }
    
    if (hasCycle) {
        slow = head;
        
        while (slow) {
            if (slow == fast)
                break;
            
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    } else
        return NULL;
}