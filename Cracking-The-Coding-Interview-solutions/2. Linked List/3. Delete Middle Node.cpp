#include<bits/stdc++.h>
using namespace std;


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
}

Node* deleteMid(Node* head)
{
    if(head == nullptr) return head;
    
    Node *slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast == nullptr){
        Node *p = slow->next;
        slow->data = slow->next->data;
        slow->next = slow->next->next;
        delete(p);
    }
    else {
        Node *p = slow->next;
        slow->next = slow->next->next;
        delete(p);
    }
    return head;
}

int main(){
	
	Node *head = createLL();
	
	print(head);

	deleteMid(head);
	
	print(head);
	
	return 0;
}
