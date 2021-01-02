
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
        int n1 = 0, n2 = 0;
        ListNode *temp = headA;
        
        while(temp) n1++, temp = temp->next;
        temp = headB;
        while(temp) n2++, temp = temp->next;
        
        int diff = abs(n1 - n2);
        if(n2 > n1) while(diff--) headB = headB->next;
        else if(n1 > n2) while(diff--) headA = headA->next;
        
        while(headA != headB) headA = headA->next, headB = headB->next;
        
        return headA;
    }
};
