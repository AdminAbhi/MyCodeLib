
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int idx = 0;
        vector<int> res 
        while(idx < v.size()){
            int tmp = idx;
            for(int i=idx+1; i<v.size(); i++){
                if(res[idx] < res[i]){
                    res[idx] = res[i];
                    idx++;
                } 
            }   
            if(tmp == idx) idx++;
        }
        
        return res;
    }
};
