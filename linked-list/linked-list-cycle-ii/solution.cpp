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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p, *q;
        p = head;
        q = head;
        while(p && q && p->next && q->next) {
            p = p->next;
            q = q->next;
            if(q->next)
                q = q->next;
            if(p == q)
                break;
        }
        if(!q || !q->next) 
            return NULL;
        q = head;
        while(p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};