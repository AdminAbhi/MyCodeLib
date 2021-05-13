#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		n += 1;
		vector<int> ans(102, 0);
		ans[1] = 1;
		ans[2] = 2;
		ans[3] = 4;
		for(int i=4; i<=n; i++){
			int sum = 0;
			for(int j=1; j<=3; j++){
				if(i - j >= 0) sum += ans[i-j];
			}
			ans[i] = sum;
		}
		cout << ans[n] << endl;
	}
	return 0;
}
