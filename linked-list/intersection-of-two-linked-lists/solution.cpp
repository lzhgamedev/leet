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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = 0;
        ListNode *l, *s;
        l = headA;
        s = headB;
        bool a_long = true;
        
        if(l == NULL || s == NULL)
            return NULL;
        
        while(l && s){
            if(l->next == NULL) {
                ListNode *tmp = l;
                l = s;
                s = tmp;
                a_long = false;
                break;
            }
            if(s->next == NULL) {
                break;  
            }
            l = l->next;
            s = s->next;
        }
        while(l->next != NULL) {
            diff++;
            l = l->next;
        }
        if(l != s)
            return NULL;
            
        l = a_long ? headA : headB;
        s = a_long ? headB : headA;
        while(l && s) {
            if(diff > 0) {
                diff--;
                l = l->next;
            }
            else {
                if(l == s)
                    return l;
                l = l->next;
                s = s->next;
            }
        }
    }
};