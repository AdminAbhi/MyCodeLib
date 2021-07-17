#include<bits/stdc++.h>
using namespace std;

// Time  - O(n * logn)
// space - O(1)

bool is_permutation1(string s1, string s2){
	if(s1.length() != s2.length()) return false;
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	
	if(s1 == s2) return true;
	return false;
}

// Time  - O(max(n,m))
// space - O(1)

bool is_permutation(string s1, string s2){
	if(s1.length() != s2.length()) return false;
	
	vector<int> cnt(256,0);
	
	for(char c: s1) cnt[c]++;
	
	for(char c: s2){
		cnt[c]--;
		if(cnt[c] < 0) return false;
	} 

	return true;
}


int main(){
	string s1, s2; 
	cin >> s1 >> s2;
	
	if(is_permutation(s1, s2)){
		cout << "Yes";
	} 
	else{
		cout << "No";
	} 
	return 0;
}
