#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &arr, vector<int> &vis, vector<vector<int>> &adj, int start, int &ans){
	vis[start] = 1;
	for(int i: adj[start]){
		if(vis[i]) continue;
		ans += arr[i];
		dfs(arr, vis, adj, i, ans);
	}
}

int main() {
	int n; cin >> n;
	vector<int> arr(n), vis(n, 0);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	vector<vector<int>> adj(n+1);
	int m; cin >> m;
	
	for(int i=0; i<m; i++){
		int u, v; cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	int maxx = 0;
	for(int i=0; i<n; i++){
		if(vis[i]) continue;
		int ans = arr[i];
		dfs(arr, vis, adj, i, ans);
		maxx = max(maxx, ans);
	}
	cout << maxx;
	return 0;
}
