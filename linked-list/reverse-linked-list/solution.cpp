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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* p = head;
        ListNode* q = p->next;
        p->next = NULL;
        while(q) {
            ListNode* t = q;
            q = q->next;
            t->next = p;
            p = t;
        }
        return p;
    }
};