
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        
        ListNode *odd = head, *even = head->next;
        ListNode *p = even;
        
        bool togg = 1;
        
        while(odd && even){
            if(togg) {
                odd->next = even->next;
                if(!odd->next) break;
                odd = odd->next;
            }
            else{
                even->next = odd->next;
                even = even->next;
            }
            togg = 1 - togg;
        }
        if(odd) odd->next = p;
        return head;
    }
};
