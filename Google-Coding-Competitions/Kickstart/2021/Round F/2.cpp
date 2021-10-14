//=============================================================================
// @abhi_admin     linkedin.com/in/adminabhi     Email: abhiavisekkr@gmail.com
//=============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define endl "\n"
#define fst first
#define sec second
#define PB push_back
#define MP make_pair
#define MOD7 1000000007
#define uset unordered_set
#define umap unordered_map
#define BoostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

inline void print(VI &v){ for(int i:v) cout<<i<<" "; cout<<endl;}
inline void print(VLL &v){ for(LL i:v) cout<<i<<" "; cout<<endl;}
inline void print(VVI &v){ for(VI i:v) print(i);}
inline void print(PI p){ cout<<"("<<p.fst<<":"<<p.sec<<"), ";}
inline void print(VPI &P){for(PI i:P) print(i); cout<<endl;}
inline void print(set<int> &s){for(int i:s)cout<<i<<" "; cout<<endl;}
inline void print(map<int,int> &m){for(auto i:m) print(i); cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

LL power(LL a, LL b, LL MOD){
    LL res = 1;
    while(b){
        if(b%2) res = (res*a) % MOD;
        a = (a*a) % MOD;
        b /= 2;
    }return res;
}
LL iMOD(LL a, LL p){
    return power(a, p-2, p);
}
//=============================================================================
//--------------------------Keep-Calm-and-Code---------------------------------
//=============================================================================




void sol(){
	LL D,N,K; cin >> D >> N >> K;
	VLL dur(D+2, 0);
	VLL cnt(D+2, 0);
	VLL hi(N), si(N), ei(N); 
	for(LL i=0; i<N; i++){
		cin >> hi[i] >> si[i] >> ei[i];
		dur[si[i]] += hi[i];
		dur[ei[i] + 1] -= hi[i];
		cnt[si[i]] += 1;
		cnt[ei[i] + 1] -= 1; 
	}
	for(LL i=1; i<D+2; i++){
		dur[i] += dur[i-1];
		cnt[i] += cnt[i-1];
	}
	VLL hash(K+1, 0);
	LL res = 0;
	for(LL i=0; i<D+2; i++){
		if(cnt[i] <= K){
			hash[cnt[i]] = max(hash[cnt[i]], dur[i]);
			res = max(res, hash[cnt[i]]);
		}
	}
	//print(cnt);
	//print(dur);
	cout << res << endl;
}


void sol1(){
	LL D,N,K; cin >> D >> N >> K;
	vector<VLL> hse(N, VLL(3)); 
	map<LL,VLL> ms, me;
	set<LL> st;
	for(LL i=0; i<N; i++){
		cin >> hse[i][0] >> hse[i][1] >> hse[i][2];
		st.insert(hse[i][1]);
		st.insert(hse[i][2]);
		ms[hse[i][1]].PB(i);
		me[hse[i][2]].PB(i);
	}
	VLL hash;
	for(LL i: st){
		hash.PB(i);
	}
	LL n = hash.size();
	LL res = 0;
	//sort(hse.rbegin(), hse.rend());
	
	for(int i=0; i<n; i++){
		set<LL> st;
		if(ms.find(hash[i]) != ms.end()){
			for(LL idx: ms[hash[i]]) st.insert(idx);
		}
		if(me.find(hash[i]) != me.end()){
			for(LL idx: me[hash[i]]) st.insert(idx);
		}
		VLL arr;
		for(LL idx: st){
			cout << idx << " ";
			arr.PB(hse[idx][0]);
		}
		cout << endl;
		
		sort(arr.rbegin(), arr.rend());
		LL sum = 0;
		for(int idx=0; idx < K && idx < arr.size(); idx++){
			sum += arr[idx];
		}
		res = max(res, sum);
	}
	
	cout << res << endl;
}


int main() {
	BoostIO;
	int T; cin >> T;
	int t = 1;
	while(t <= T){
		cout << "Case #" << t++ << ": ";
		sol1();
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
