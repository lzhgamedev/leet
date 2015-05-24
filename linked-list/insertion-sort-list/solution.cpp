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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy, *p;
        dummy = new ListNode(0);
        p = head;
        while(p) {
            InsertNode(dummy, p);
            p = p->next;
        }
        return dummy->next;
    }
    void InsertNode(ListNode* d, ListNode* node) {
        while(d && d->next) {
            if(d->next->val <= node->val) {
                d = d->next;
            }
            else {
               ListNode* q = new ListNode(node->val);
               q->next = d->next;
               d->next = q;
               return;
            }
        }
        d->next = new ListNode(node->val);
    }
};