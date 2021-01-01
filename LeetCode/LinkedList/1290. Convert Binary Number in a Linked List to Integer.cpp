
https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/


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
    int getDecimalValue(ListNode* head) {
        string s = "";
        while(head){
            s.push_back(head->val==0 ? '0': '1');
            head = head->next;
        }
        return stoi(s, 0, 2);
    }
};
