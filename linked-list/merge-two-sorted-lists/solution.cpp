/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head;
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
            
        if(l1->val >= l2->val)
            head = l2;
        else
            head = l1;
        
        while(l1 && l2) {
            while(l1 && l2 && l2->val <= l1->val) {
                if(l2->next == NULL || l2->next->val > l1->val) {
                    ListNode *tmp = l2;
                    l2 = l2->next;
                    tmp->next = l1;
                }
                else
                    l2 = l2->next;
            }
            while(l1 && l2 && l1->val <= l2->val) {
                if(l1->next == NULL || l1->next->val > l2->val) {
                    ListNode *tmp = l1;
                    l1 = l1->next;
                    tmp->next = l2;
                }
                else
                    l1 = l1->next;
            }
        }
        
        return head;
    }
};