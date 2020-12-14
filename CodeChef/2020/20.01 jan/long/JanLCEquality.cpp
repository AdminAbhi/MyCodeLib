//@Abhi     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI > VVI;
typedef vector<VLL > VVLL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
typedef vector<PI> VPI;
typedef vector<PLL> VPLL;

#define endl "\n"
#define PB push_back
#define MP make_pair
#define fst first
#define sec second
#define MOD7 1000000007
#define fn(i, n) for(int i = 0; i < (n); ++i)
#define fab(i, a, b) for(int i = (a); i < (b); ++i)
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VVLL v){ for(VLL i:v){ for(LL j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}


void buildTreeI(int n, int* arr, int* IST, int start, int end, int STNode){
    if(start == end){
        IST[STNode] = 0;
        return;
    }
    int mid = (start + end)/2;
    
    buildTreeI(n, arr, IST, start, mid, 2*STNode);
    buildTreeI(n, arr, IST, mid+1, end, 2*STNode +1);
    
    int flag = 0;
    if(end - start == 1 && arr[mid] < arr[mid + 1])
        flag = 1;
    else if(end - start == 2){
        if(arr[mid] < arr[mid +1] && arr[mid-1] > arr[mid]) flag = 1;
    }
    else if(arr[mid] < arr[mid + 1] && arr[mid-1] > arr[mid] && arr[mid+1] > arr[mid+2])
            flag = 1;
    else if(arr[mid] < arr[mid + 1] && arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid+2])
            flag = -1;
        
    IST[STNode] = IST[2*STNode] + IST[2*STNode + 1] + flag;
    
}
void buildTreeD(int n, int* arr, int* DST, int start, int end, int STNode){
    if(start == end){
        DST[STNode] = 0;
        return;
    }
    int mid = (start + end)/2;
    
    buildTreeD(n, arr, DST, start, mid, 2*STNode);
    buildTreeD(n, arr, DST, mid+1, end, 2*STNode +1);
    
    int flag = 0;
    if(end - start == 1 && arr[mid] > arr[mid + 1])
        flag = 1;
    else if(end - start == 2){
        if(arr[mid] > arr[mid +1] && arr[mid-1] < arr[mid]) flag = 1;
    }
    else if(arr[mid] > arr[mid + 1] && arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid+2])
            flag = 1;
    else if(arr[mid] > arr[mid + 1] && arr[mid-1] > arr[mid] && arr[mid+1] > arr[mid+2])
            flag = -1;
    
    DST[STNode] = DST[2*STNode] + DST[2*STNode + 1] + flag;
    
}

int find(int* ST, int l, int r, int s, int n, int idx){
       
        if(l <= s && r >= n)
            return ST[idx];
        if (n < l || s > r)  
            return 0; 
        int mid = (s + n)/2;  
        return find(ST, l, r, s, mid, 2*idx) +  find(ST, l, r, mid+1, n, 2*idx+1);  
}

int main() {
	BoostIO;
	
	   int n, q;
	   cin >> n >> q;
	   int arr[n];
	   for(int i=0; i<n; i++){
	       cin >> arr[i]; 
	   }
	   for(int i=0; i<n; i++)
	       cout << arr[i] << " ";
	   cout<<endl;
	   
	   int IST[2*n]={0};
	   int DST[2*n]={0};
	   
	   buildTreeI(n, arr, IST, 0, n-1, 1);
	   buildTreeD(n, arr, DST, 0, n-1, 1);
	   
	   for(int i=1; i<2*n; i++)
	       cout << IST[i] << " " << DST[i] << endl;
	   
	   cout<<"...........\n";
	       
	   for(int i=0; i<q; i++){
	       int l,r;
	       cin >> l >> r;
	       //cout<< l << r <<endl;
	       
	       int inc=0, dec=0;
	       
	       if(r-l == 1){
	           if(arr[l-1] < arr[r-1])
	                inc = 1;
	           if(arr[l-1] > arr[r-1])
	                dec = 1;
	       }
	       else{
	            inc = find(IST, l, r, 1, n, 1);
	            dec = find(DST, l, r, 1, n, 1);
	       }
	       
	       cout << inc <<" "<< dec << endl;
	   }
	   
	return 0;
}