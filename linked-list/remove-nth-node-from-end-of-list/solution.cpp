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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = head, *second = head;
        while(second->next != NULL) {
            second = second->next;
            n--;
            if(n < 0) {
                first = first->next;
            }
        }
        if(n <= 0) {
            ListNode *tmp = first->next;
            first->next = tmp->next;
            tmp->next = NULL;
        }
        //delete head
        else {
            head = first->next;
            first->next = NULL;
        }
        
        return head;
    }
};