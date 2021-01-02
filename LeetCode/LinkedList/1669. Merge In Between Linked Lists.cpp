
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *l1 = list1, *l2 = list1;
        
        a--;
        b -= a-1;
        
        while(a--){
            l1 = l1->next;
            l2 = l2->next;
        } 
        
        while(b--) l2 = l2->next;
        
        l1->next = list2;
        
        while(l1->next){
            l1 = l1->next;
        }
        
        l1->next = l2;
            
        return list1;
    }
};
