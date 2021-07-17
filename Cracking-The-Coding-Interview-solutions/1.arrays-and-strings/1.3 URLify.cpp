#include<bits/stdc++.h>
using namespace std;

// Time  - O(n)
// space - O(1)


void URLify(string &s){
	int space = 0, inilength = s.length();
	for(int i=0; i<inilength; i++){
		if(s[i] == ' ') space++;
	}
	int finlength = s.length() + space*2;
	s.resize(finlength);
	s[finlength] = '\0';
	int index = finlength;
	for(int i=inilength-1; i>=0; i--){
		if(s[i] == ' '){
			s[index-1] = '0';
			s[index-2] = '2';
			s[index-3] = '%';
			index -= 3;
		}
		else{ 
			s[index-1] = s[i];
			index--;
		}
	} 
	
}

int main(){
	string s;
	
	getline(cin, s);
	
	URLify(s);
	
	cout << s;
	
	return 0;
}
