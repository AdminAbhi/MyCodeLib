#include<bits/stdc++.h>
using namespace std;

// Time  - O(n*m)
// space - O(1)

bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        s += s;
        if(s.find(goal) == std::string::npos) return false;
		return true;
}

int main(){
	string s, goal;
	cin >> s >> goal;
	cout << rotateString(s, goal);
	return 0;
}
