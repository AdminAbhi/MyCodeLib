#include<bits/stdc++.h>
using namespace std;

class BSTNode{
	public:
	int data;
	BSTNode *left;
	BSTNode *right;
	
	BSTNode(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

BSTNode *createBST(vector<int> &arr, int l, int r){
	if(l > r) return nullptr;
	if(l == r){
		return new BSTNode(arr[l]);
	}
	int mid = (l+r)/2;
	BSTNode *node = new BSTNode(arr[mid]);
	node->left = createBST(arr, l, mid-1);
	node->right = createBST(arr, mid+1, r);
	return node;
}

void print(BSTNode *root){
	queue<pair<int, BSTNode *>> q;
	q.push({0,root});
	int line = 0;
	while(!q.empty()){
		auto p = q.front(); q.pop();
		if(p.second){
			if(line != p.first){
				cout << endl;
				line++;
			}
			cout << p.second->data << " ";
			q.push({p.first+1, p.second->left});
			q.push({p.first+1, p.second->right});
		}
	}
}

int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	BSTNode *bst = createBST(arr, 0, n-1);
	
	print(bst);
	
	return 0;
}
