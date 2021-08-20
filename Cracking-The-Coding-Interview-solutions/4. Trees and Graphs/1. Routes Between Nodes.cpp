#include<bits/stdc++.h>
using namespace std;

// DFS
// Time  - O(n)
// Space - O(n)
 
bool routeBetweenNodes(vector<vector<int>> &adj, vector<int> &vis, int a, int b){
	if(a == b) return true;
	if(vis[a]) return false;
	vis[a] = 1;
	for(int i: adj[a]){
		if(routeBetweenNodes(adj, vis, i, b)) return true;
	}
	return false;
}

// BFS
// Time  - O(n)
// Space - O(n)

bool routeBetweenNodes2(vector<vector<int>> &adj, vector<int> &vis, int a, int b){
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int curr = q.front(); 
		q.pop();
		vis[curr] = 1;
		if(curr == b) return true;
		for(int i: adj[curr]){
			if(vis[i]) continue;
			q.push(i);
		} 
	}
	return false;
}

int main(){
	int n; cin >> n;
	vector<vector<int>> adj(n+1);
	for(int i=0; i<n; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			vector<int> vis(n+1,0);
			cout << routeBetweenNodes2(adj, vis, i, j) << " ";
		}
		cout << endl;
	}
	
	return 0;
}
