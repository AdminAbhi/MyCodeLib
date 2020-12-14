#include <bits/stdc++.h>
#define A 101
using namespace std;
vector<int>days(400,0);
int dayofweek(int d, int m, int y) {
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
	y -= m < 3; 
	return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7; 
}
bool leap(int y){
	if(y % 100 == 0 && y % 400 != 0) return false;
	if(y % 4 == 0) return true;
	return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ss = 1;
    int cnt = 0;
     while(ss <= 400){
			int d = dayofweek(1,2,ss);
			if(d == 6) cnt++;
			if(d == 0 && !leap(ss)) cnt++;
			days[ss] = cnt;
			ss++;
		}
    int t;
    cin>>t;
    while(t--){
		int sm,sy,em,ey;
		cin >> sm >> sy;
		cin >> em >> ey;
		if(sm > 2) sy++;
		if(em < 2) ey--;
		sy--;
		int st =  sy / 400;
		int eyr = ey / 400; 
		int rst = sy % 400;
		int rey = ey % 400;
		int left = st * A; 
		int right = eyr * A;
		if(rey > 0) right += days[rey];
		if(rst > 0) left += days[rst]; 
		cout << right - left << '\n';
    }
    return 0;
}
