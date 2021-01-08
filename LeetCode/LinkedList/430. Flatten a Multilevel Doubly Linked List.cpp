
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head, *nxt = NULL;
        while(curr){
            nxt = curr->next;
            
            if(curr->child){
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;
                
                while(curr->next){
                    curr = curr->next;
                }
                curr->next = nxt;
                if(nxt) nxt->prev = curr;
            } 
            
            curr = curr->next;
        }
        return head;
    }
};
