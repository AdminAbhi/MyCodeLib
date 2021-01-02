
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode *head){
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        
        ListNode res, *sum;
        sum = &res;
        
        while(l1 || l2){
            int v;
            if(l1 && l2){
                v = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1){
                v = l1->val + carry;
                l1 = l1->next;
            }
            else{
                v = l2->val + carry;
                l2 = l2->next;
            }
            carry = v/10;
            v %= 10;
            ListNode *p = new ListNode(v);
            sum->next = p;
            sum = sum->next;
        }
        
        if(carry){
            ListNode *p = new ListNode(carry);
            sum->next = p;
            sum = sum->next;
        }
        
        return reverse(res.next);
    }
};
