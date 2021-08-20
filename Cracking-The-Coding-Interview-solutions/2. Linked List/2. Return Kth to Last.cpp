#include<bits/stdc++.h>
using namespace std;

// Linked List Class ------------------------

class Node{
	public:
		int val;
		Node* next;
};

Node * createLL(){
	int n; cin >> n;
	if(n<1) return NULL;
	
	Node *head = new Node();
	Node *temp = head;
	int x; cin >> x;
	temp->val = x;
	 
	for(int i=0; i<n-1; i++){
		cin >> x;
		Node *p = new Node();
		p->val = x;
		temp->next = p;
		temp = temp->next;	
	}
	return head;
}

void print(Node *head){
	Node *temp = head;
	while(temp){
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}
// ------------------------------------------

// Double Pass
// Time  - O(2n)
// Space - O(1)

Node* removeKthFromEnd(Node* head, int k) {
        int n = 0;
        Node* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        n -= k+1;
        if(n < 0){
            Node *p = head;
            head = head->next;
            delete(p);
            return head;
        }
        temp = head;
        while(n--){
            temp = temp->next;
        }
		Node *p = temp->next;
        temp->next = temp->next->next;
        delete(p);
        return head;
    }


// Single Pass
// Time  - O(n)
// Space - O(1)


Node* removeNthFromEnd(Node* head, int k) {
        Node *t1 = head, *t2 = head;
        while(k > 0){
            t2 = t2->next;
            k--;
        }
        if(t2 == nullptr){
            Node *p = head;
            head = head->next;
            delete(p);
            return head;
        }
        while(t2->next){
            t1 = t1->next;
            t2 = t2->next;
        }
        Node *p = t1->next;
        t1->next = t1->next->next;
        delete(p);
        return head;
    }


int main(){
	
	Node *head = createLL();
	
	print(head);
	
	int k; cin >> k;
	
	removeKthFromEnd(head, k);
	
	print(head);
	
	return 0;
}
