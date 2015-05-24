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
    void reorderList(ListNode* head) {
        int count = total(head);
        if(count == 0)
            return;
        int reverse_index = count / 2 + 1;
        ListNode* rhead = reversePart(reverse_index, head);
        int i = 0;
        ListNode* p = head;
        while(i < reverse_index - 1) {
            ListNode* q = rhead;
            rhead = rhead->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            i++;
        }
        p->next = NULL;
    }
    int total(ListNode* head) {
        int count = 0;
        ListNode* p = head;
        while(p) {
            count++;
            p = p->next;
        }
        return count;
    }
    ListNode* reversePart(int index, ListNode* head) {
        ListNode* p = head;
        while(index > 1) {
            p = p->next;
            index--;
        }
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