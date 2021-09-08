/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
 * Time: O(n)
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = NULL, *end, *node;
        
        if (!l1 && !l2)
            return NULL;
        
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            
            node = new ListNode;
            node->val = carry % 10;
            node->next = NULL;
            carry /= 10;

            if (!head)
                head = end = node;
            else {
                end->next = node;
                end = node;
            }
        }   
        
        return head;
    }
};