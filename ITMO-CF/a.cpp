#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define int long long
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// // 1B
// void solve(){
// 	int n, q; cin>>n>>q;
// 	vi arr(n); cin>>arr;

		
//     while(q--){
//     	int x; cin>>x;

//     	// virtual elemets :- arr[-1] = -INF, arr[n] = INF;
//     	// invarients;
// 	    int l = -1; // a[l] <= x;
// 	    int r = n; // a[r] > x; 

// 	    // break when l and r are consecutive;
// 	    while(l + 1 < r){
// 	    	int m = (l + r) >> 1;

// 	    	// inequalities same as invarients;
// 	    	if(arr[m] <= x) l = m;
// 	    	else r = m;
// 	    }
//		// arr[l] the answer;
// 	    cout<<l + 1<<el;
// 	}	
// }





// // 1C
// void solve(){
// 	int n, q; cin>>n>>q;
// 	vi arr(n); cin>>arr;

		
//     while(q--){
//     	int x; cin>>x;

//     	// virtual elemets :- arr[-1] = -INF, arr[n] = INF;
//     	// invarients;
// 	    int l = -1; // a[l] < x;
// 	    int r = n; // a[r] >= x; 

// 	    // break when l and r are consecutive;
// 	    while(l + 1 < r){
// 	    	int m = (l + r) >> 1;

// 	    	// inequalities same as invarients;
// 	    	if(arr[m] < x) l = m;
// 	    	else r = m;
// 	    }

// 	    // arr[r] is the answer;
// 	    cout<<r + 1<<el;
// 	}	
// }




// // 1D
// void solve(){
// 	int n; cin>>n;
// 	vi arr(n); cin>>arr;
// 	sort(rng(arr));
		
// 	int q; cin>>q;	
//     while(q--){
//     	int ll, rr; cin>>ll>>rr;

//     	// finding minimal r such that arr[r] >= ll;
//     	int l = -1; // arr[l] < ll;
//     	int r = n; // arr[r] >= ll;
//     	while(l + 1 < r){
//     		int m = (l + r) / 2;
//     		if(arr[m] < ll) l = m;
//     		else r = m;
//     	}
//     	int ar = r;


//     	// finding maximal l such that arr[l] <= rr;
//     	l = -1; // arr[l] <= rr;
//     	r = n; // arr[r] > rr;
//     	while(l + 1 < r){
//     		int m = (l + r) / 2;
//     		if(arr[m] <= rr) l = m;
//     		else r = m;
//     	}
//     	int al = l;


//     	cout<<al - ar + 1<<" ";
// 	}	
// 	cout<<el;
// }





// // 2A
// int w, h, n;

// bool good(int x){
// 	return (x/w) * (x/h) >= n;
// }

// void solve(){
// 	cin>>w>>h>>n;
//  // invariants;
// 	int l = 0; // bad;
// 	int r = 1; // good;
// 	while(good(r) == false) r <<= 1;

// 	while(l + 1 < r){
// 		int m = (l + r) >> 1;
// 		// same conditions as invarint;
// 		if(good(m)){
// 			r = m;
// 		}
// 		else{
// 			l = m;
// 		}
// 	}

// 	cout<<r<<el;
// }



// 2B
vi lens;
int n, k;
bool calc(double sz){
	int segs = 0;
	for(int ln : lens){
		segs += (ln / sz);
	}
	return segs >= k;
}
void solve(){
	cin>>n>>k;
	lens.resize(n);
	cin>>lens;

	double l = 0; // good
	double r = 1e7 + 1; // bad

	// always do this when working with doubles in binary search;
	for (int i = 0; i < 100; ++i){
		double m = (l + r) / 2;
		if(calc(m)){
			l = m;
		}
		else{
			r = m;
		}
	}
	cout<<setprecision(12)<<fixed<<l<<el;
}


 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}