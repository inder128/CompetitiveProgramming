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
    int n, m; cin >> n >> m;
    vi adj[n];
    for (int i = 0; i < m; ++i){
    	int a, b; cin >> a >> b;
    	a--, b--;
    	adj[a].pb(b);
    }

    vi rt(n, 1e9);
    for (int i = 0; i < n; ++i){
    	if(SZ(adj[i]) == 0){
    		rt[i] = 0;
    	}
    	for(int j : adj[i]){
    		if(j > i){
    			mini(rt[i], j - i);
    		}
    		else{
    			mini(rt[i], n - (i - j));
    		}
    	}
    }

    db(rt);

    for (int i = 0; i < n; ++i){
    	int tmx = 0;
    	for (int j = 0; j < n; ++j){
    		int curr = (i + j) % n;
    		if(SZ(adj[curr]) == 0){
    			continue;
    		}
    		maxi(tmx, (SZ(adj[curr]) - 1) * n + rt[curr] + j);
    		// db((SZ(adj[curr]) - 1) * n + rt[curr] + j);
    	}
    	cout << tmx << " ";
    }
    cout << el;
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