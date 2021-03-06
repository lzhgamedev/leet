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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head;
        
        while(p != NULL && p->next != NULL) {
            if(p->next->val == p->val) {
                ListNode *tmp = p->next;
                p->next = tmp->next;
                tmp->next = NULL;
            } 
            else 
                p = p->next;
        }
        return head;
    }
};