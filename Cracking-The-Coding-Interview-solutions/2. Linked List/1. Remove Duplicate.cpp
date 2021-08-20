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

// Time  - O(n logn)
// space - O(n)

void removeDuplicates(Node *head){
	Node *temp = head;
	set<int> st;
	while(temp && temp->next){
		st.insert(temp->val);
		if(st.find(temp->next->val) != st.end()){
			Node *p = temp->next;
			temp->next = temp->next->next;
			delete(p);
		}
		else temp = temp->next;
	}
}

// Time  - O(n*n)
// Space - O(1)

void removeDuplicates2(Node *head){
	Node *temp1 = head;
	while(temp1 && temp1->next){
		Node *temp2 = temp1;
		while(temp2 && temp2->next){
			if(temp1->val == temp2->next->val){
				Node *p = temp2->next;
				temp2->next = temp2->next->next;
				delete(p);
			}
			else temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

int main(){
	
	Node *head = createLL();
	
	print(head);
	
	removeDuplicates2(head);
	
	print(head);
	
	return 0;
}
