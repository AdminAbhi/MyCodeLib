
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

// By swaping Values

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head;
        while(curr && curr->next){
            swap(curr->val, curr->next->val);
            curr = curr->next->next;
        }
        return head;
    }
};


// By swaping Nodes

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode res,  *nxt = NULL, *temp;
        res.next = head;
        ListNode *curr = &res;
        
        while(curr->next && curr->next->next){
            nxt = curr->next->next;
            temp = nxt->next;
            nxt->next = curr->next;
            nxt->next->next = temp;
            curr->next = nxt;
            curr = nxt->next;
        }
        return res.next;
    }
};
