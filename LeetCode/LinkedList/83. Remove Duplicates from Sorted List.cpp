
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *nxt = NULL, *curr = head;
        while(curr){
            nxt = curr->next;
            while(nxt && nxt->val == curr->val){
                nxt = nxt->next;
            }
            curr->next = nxt;
            curr = curr->next;
        }
        return head;
    }
};
