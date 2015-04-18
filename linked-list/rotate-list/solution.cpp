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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *p, *q;
        int length = 1;
        int offset;
        if(head == NULL)  
            return head;
        p = head;
        q = head;
        while(q->next != NULL) {
            q = q->next;
            length++;
        }
        k = length - k % length;
        offset = k;
        while(k > 1) {
            p = p->next;
            k--;
        }
        if(offset >= 1) {
            q->next = head;
            head = p->next;
            p->next = NULL;
        }
        return head;
    }
};