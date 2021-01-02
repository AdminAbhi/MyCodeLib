
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
    int numComponents(ListNode* head, vector<int>& G) {
        int cc = 0;
        set<int> st;
        for(int i : G) st.insert(i);
        
        while(head){
            if(st.find(head->val) != st.end() && (head->next == NULL || st.find(head->next->val) == st.end())) cc++;
            head = head->next;
        }
        return cc;
    }
};
