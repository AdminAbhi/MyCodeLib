
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
    bool hasCycle(ListNode *head) {
        ListNode *curr = head, *nxt = head;
        while(nxt){
            if(nxt) nxt = nxt->next;
            if(nxt) nxt = nxt->next;
            curr = curr->next;
            if(curr == nxt && nxt != NULL) return true;
        }
        return false;
    }
};
