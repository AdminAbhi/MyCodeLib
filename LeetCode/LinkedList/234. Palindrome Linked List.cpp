
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


// Time  = O(n)
// Space = O(n)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode *p = head;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        while(p){
            if(st.top() != p->val) return false;
            st.pop();
            p = p->next;
        }
        return true;
    }
};


// Time  = O(n)
// Space = O(1)


class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL, *curr = head, *nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverse(slow);
        fast = head;
        while(slow && fast){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
