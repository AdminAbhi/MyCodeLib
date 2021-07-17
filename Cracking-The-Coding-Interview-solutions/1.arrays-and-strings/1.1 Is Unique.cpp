#include<bits/stdc++.h>
using namespace std;

// Time  - O(n^2)
// space - O(1)

bool isUnique1(string s){
	for(int i=0; i<s.length(); i++){
		for(int j=i+1; j<s.length(); j++){
			if(s[i] == s[j]) return false;
		}
	}
	return true;
}

// time  - O(n * logn)
// space - O(n)

bool isUnique2(string s){
	set<char> st;
	for(char c: s){
		if(st.find(c) != st.end()) return false;
		st.insert(c);
	}
	return true;
} 

// time  - O(min(c, n))
// space - O(c)

bool isUnique3(string s){
	int n = 256;
	vector<int> cache(n,0);
	for(char c: s){
		if(cache[c]) return false;
		cache[c] = 1;
	}
	return true;
}

// time  - O(n)
// space - O(1)

bool isUnique4(string s){
	int cache = 0;
	for(char c: s){
		if(cache & (1 << c)) return false;
		cache |= (1 << c);
	}
	return true;
}


int main(){
	string s;
	cin >> s;
	cout << isUnique1(s) << endl;
	cout << isUnique2(s) << endl;
	cout << isUnique3(s) << endl;
	cout << isUnique4(s) << endl;
}
