#include<bits/stdc++.h>
using namespace std;

// Time  - O(max(n, m))
// space - O(1)


int compress(string &chars) {
        int res = 0, idx = 0;
        if(chars.size() == 0) return res;
        int i = 0;
        while(i < chars.size()){
            int cnt = 1;
            while(i < chars.size()-1 && chars[i] == chars[i+1]){
                cnt++;
                i++;
            }
            res++;
            if(cnt > 1){
                chars[idx++] = chars[i];
                stack<char> temp; 
                while(cnt){
                    res++;
                    temp.push(cnt%10 + '0');
                    cnt /= 10;
                }
                while(!temp.empty()){
                    chars[idx++] = temp.top();
                    temp.pop();
                }
            }
            else{
                chars[idx++] = chars[i];
            }
            i++;
        }
        return res;
    }
    

int main(){
	
	string s; cin >> s;
	
	int n = compress(s);
	
	cout << s.substr(0,n);
	
	return 0;
}
