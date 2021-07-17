#include<bits/stdc++.h>
using namespace std;

// Time  - O(max(n, m))
// space - O(1)


bool oneAway(string s1, string s2){
	if(abs(int(s1.length() - s2.length())) > 1) return false;
	int i=0, j=0;
	int edit = 0;
	for(int k=0; k<min(s1.length(), s2.length()); k++){
		if(s1[i] != s2[j] && edit >= 1) return false;
		else if(s1[i] != s2[j]){
			edit++;
			if(s1.length() > s2.length()){
				i++;
			} 
			else if(s1.length() < s2.length()){
				j++;
			}
			else{
				i++,j++;
			} 
		}
		else{
			i++, j++;
		}
	}
	return true;
}

int main(){
	
	string s1, s2; 
	cin >> s1 >> s2;
	
	cout << oneAway(s1, s2);
	
	return 0;
}
