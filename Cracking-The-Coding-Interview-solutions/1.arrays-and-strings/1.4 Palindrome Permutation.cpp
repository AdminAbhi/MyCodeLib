#include<bits/stdc++.h>
using namespace std;

// Time  - O(n)
// space - O(1)

bool isPermutaionOfPalindrome1(string s){
	vector<int> cnt(26);
	int cntOdd = 0;
	for(char c: s){
		cnt[c - 'a']++;
		if(cnt[c - 'a'] % 2 == 0){
			cntOdd--;
		}
		else{
			cntOdd++;
		}
	}
	return cntOdd <= 1;
}


// only for a-z
// Time  - O(n)
// space - O(1) - without extra vector;

bool isPermutaionOfPalindrome(string s){
	int cnt = 0;
	for(char c: s){
		cnt ^= 1 << int(c - 'a');
		cout<< cnt << endl;
	}
	if(cnt == 0) return true;
	return (cnt & (cnt-1)) == 0;
	
}

int main(){
	string s; cin >> s;
	
	cout << isPermutaionOfPalindrome(s);
	
	return 0;
}
