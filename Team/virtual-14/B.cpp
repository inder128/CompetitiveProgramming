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
    int n, q; cin >> n >> q;
    map <pi, char> mp;


    set <pi> samelp, lp;

    while(q--){
    	char c; cin >> c;
    	if(c == '+'){
    		int u, v;
    		char ch; cin >> u >> v >> ch;

    		if(mp.find({v, u}) != mp.end()){
    			if(mp[{v, u}] == ch){
    				samelp.insert({v, u});
    				samelp.insert({u, v});
    			}
    			lp.insert({v, u});
    			lp.insert({u, v});
    		}

    		mp[{u, v}] = ch;
    	}
    	else if(c == '-'){
    		int u, v; cin >> u >> v;

    		if(mp.find({v, u}) != mp.end()){
    			if(mp[{v, u}] == mp[{u, v}]){
    				samelp.erase({v, u});
    				samelp.erase({u, v});
    			}
    			lp.erase({v, u});
    			lp.erase({u, v});
    		}

    		mp.erase({u, v});
    	}
    	else{
    		int k; cin >> k;
    		if(k % 2 == 0){
    			if(SZ(samelp)){
    				cout << "YES" << el;
    			}
    			else{
    				cout << "NO" << el;
    			}
    		}
    		else{
    			if(SZ(lp)){
    				cout << "YES" << el;
    			}
    			else{
    				cout << "NO" << el;
    			}
    		}
    	}
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}