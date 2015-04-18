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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *reverse_head, *p, *q;
        reverse_head = head;
        int i = m;
        
        //find reverse head
        while(i > 2) {
            reverse_head = reverse_head->next;
            i--;
        }
        if(m >= 2)
            p = reverse_head->next;
        else
            p = reverse_head;
           
        //reverse 
        q = p->next;
        p->next = NULL;
        i = n - m;
        while(i > 0) {
            ListNode *tmp = q;
            q = q->next;
            tmp->next = p;
            p = tmp;
            i--;
        }
        
        //connect 
        if(m >= 2) {
            reverse_head->next->next = q;
            reverse_head->next = p;
        }
        else {
            head = p;
            reverse_head->next = q;
        }
        return head;
    }
};