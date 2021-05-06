#include <bits/stdc++.h>
using namespace std;

void rev(vector<int> &arr, int i, int j){
    while(i < j){
        swap(arr[i], arr[j]);
        i++, j--;
    }
}

void sol(){
    int n, c; cin >> n >> c;
    if(c >= (n*(n+1))/2 or c < n-1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	vector<int> arr(n);
	for(int i=1; i<=n; i++) arr[i-1] = i;
	
	vector<pair<int,int>> vp;
	
	for(int i=0; i<n-1; i++){
		int j = i + min(n-i-1, c - (n-i-1));
		//rev(arr, i, j);
		vp.push_back({i, j});
		c -= j - i +1;
	}
	for(int i=vp.size()-1; i>=0; i--){
		//cout << vp[i].first << vp[i].second << endl;
		rev(arr, vp[i].first, vp[i].second);
	}
	for(int i: arr) cout << i << " ";
	cout << endl; 
}

int main() {
	int T; cin >> T;
	int t = 1;
	while(t <= T){
	    cout << "Case #" << t << ": ";
	    sol();
	    t++;
	}
	return 0;
}

