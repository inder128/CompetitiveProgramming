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
	int n; cin >> n;
    set <array <int, 4>> pieces;
    pieces.insert({1, n, 0, 0});
    
    int q; cin >> q;
    set <int> taken;
    while(q--){
    	int x, y; cin >> x >> y;
    	char d; cin >> d;
    	if(taken.count(x)){
    		cout << 0 << el;
    		continue;
    	}
    	else{
    		taken.insert(x);
    	}
    	
    	int ans = 0;
    	auto itr = pieces.upper_bound({x, INT_MAX, INT_MAX, INT_MAX});
    	if(itr != pieces.begin()){
    		itr--;
    	}
    	auto [l, r, a, b] = *itr;
    	pieces.erase({l, r, a, b});

    	db(l, r, a, b);
    	

    	if(d == 'U'){
    		ans = r - x + 1 + a;
    		if(x > l){
    			pieces.insert({l, x - 1, a + r - x + 1, b});
    		}
    		if(x < r){
    			pieces.insert({x + 1, r, a, 0});
    		}
    	}
    	else{
    		ans = x - l + 1 + b;
    		if(x > l){
    			pieces.insert({l, x - 1, 0, b});
    		}
    		if(x < r){
    			pieces.insert({x + 1, r, a, b + x - l + 1});
    		}
    	}


    	cout << ans << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}