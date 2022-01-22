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

/* Time complexity: O(m + n)
 *     m: the size of list1, n: the size of list2
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *curr, *retList;
        
        if (list1 == NULL)
            return list2;
        
        if (list2 == NULL)
            return list1;
        
        if (list1->val < list2->val) {
            curr = list1;
            list1 = list1->next;
        } else {
            curr = list2;
            list2 = list2->next;
        }
        
        retList = curr;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            
            curr = curr->next;
        }
        
        if (list1)
            curr->next = list1;
        else
            curr->next = list2;
        
        return retList;
    }
};