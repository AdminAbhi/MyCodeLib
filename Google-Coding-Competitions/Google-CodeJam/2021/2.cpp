#include <bits/stdc++.h>
using namespace std;


void sol(){
    int x, y; cin >> x >> y;
    string s; cin >> s;
    string s1 = "";
    for(int i=0; i<s.size(); i++) if(s[i] != '?') s1.push_back(s[i]);
	int cost = 0;
	for(int i=1; i<s1.size(); i++){
		if(s1[i-1] == 'C' and s1[i] == 'J') cost += x;
		else if(s1[i-1] == 'J' and s1[i] == 'C') cost += y;
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

