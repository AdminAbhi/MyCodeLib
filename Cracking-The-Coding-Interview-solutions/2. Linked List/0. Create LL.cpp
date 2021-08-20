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

int main(){
	
	Node *head = createLL();
	
	print(head);
	
	return 0;
}
