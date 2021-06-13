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
    int n, m; cin >> n >> m;
    vector <pi> adj[n];
    vi slf(n, 1e9);
    for(int i = 0; i < m; ++i){
    	int u, v, c; cin >> u >> v >> c;
    	u--, v--;
    	if(u == v){
    		mini(slf[u], c);
    	} 
    	else{
    		adj[u].pb({v, c});
    	}
    }

    vvi cost(n, vi(n, 1e9));
    for(int root = 0; root < n; ++root){
	    priority_queue <pi, vector <pi>, greater <>> PQ;
	    PQ.push({cost[root][root] = 0, root});
	    while(SZ(PQ)){
	        auto [wt, node] = PQ.top(); PQ.pop();
	        if(wt > cost[root][node]){
	            continue;
	        }
	        for(auto [child, w] : adj[node]){
	            if(cost[root][child] > cost[root][node] + w){
	                cost[root][child] = cost[root][node] + w;
	                PQ.push({cost[root][child], child});
	            }
	        }
	    }
    }

    for(int root = 0; root < n; ++root){
    	int ans = 1e9;
    	for(int mid = 0; mid < n; ++mid){
    		if(mid == root){
    			mini(ans, slf[root]);
    		}
    		else{
    			mini(ans, cost[root][mid] + cost[mid][root]);
    		}
    	}
    	if(ans == 1e9){
    		ans = -1;
    	}
    	cout << ans << el;
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