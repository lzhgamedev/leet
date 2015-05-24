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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = new ListNode(0);
        ListNode* p2;
        if(!head)
            return head;
        p1->next = head;
        head = p1;
        while(p1->next && p1->next->val < x) {
            p1 = p1->next;
        }
        p2 = p1->next;
        while(p2 && p2->next) {
            while(p2->next && p2->next->val >= x) {
                p2 = p2->next;
            }
            if(!p2->next)
                break;
            ListNode* t = p2;
            while(p2->next && p2->next->val < x) {
                p2 = p2->next;
            }
            ListNode* q = p2->next;
            p2->next = p1->next;
            p1->next = t->next;
            t->next = q;
            p1 = p2;
            p2 = q;
        }
        return head->next;
    }
};