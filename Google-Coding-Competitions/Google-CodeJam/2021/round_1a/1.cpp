#include <bits/stdc++.h>
using namespace std;

void rev(vector<int> &arr, int i, int j){
    while(i < j){
        swap(arr[i], arr[j]);
        i++, j--;
    }
}

void sol(){
    int n; cin >> n;
    priority_queue <int, vector<int>, greater<int>> pq;
    vector<int> arr(n); for(int i=0; i<n; i++){
		cin >> arr[i];
		pq.push(arr[i]);
	} 

    long long cost = 0;
    
    for(int i=0; i<n-1; i++){
        int p = pq.top(); pq.pop();
        int idj = i;
        for(int j=i; j<n; j++){
            if(arr[j] == p){
                idj = j;
                break;
            }
        }
        cost += idj - i + 1;
        rev(arr, i, idj);
    }
    cout << cost << endl;
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

