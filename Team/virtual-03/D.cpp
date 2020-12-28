#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

void solve(){
    int q; cin >> q;
    vector <double> pre, arr;
    while(q--){
    	int op; cin >> op;
    	if(op == 1){
    		double x; cin >> x;
	    	if(SZ(arr) == 0){
	    		pre.pb(x);
	    		arr.pb(x);
	    	} 
	    	else{
	    		arr.pb(x);
	    		pre.pb(pre.back() + x);
	    	}
    	}
    	else{
    		int l = 0, r = SZ(arr);
	    	while(l + 1 < r){
	    		int m = (l + r) >> 1;
	    		if(((m ? pre[m - 1] : 0) + arr.back()) / (m + 1) <= arr[m]){
	    			r = m;
	    		}
	    		else{
	    			l = m;
	    		}
	    	}

	    	cout << arr.back() - ((r ? pre[r - 1] : 0) + arr.back()) / (r + 1) << el;
    	}
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    cout << setprecision(12) << fixed;
    while(T--){
        solve();
    }
    return 0;
}