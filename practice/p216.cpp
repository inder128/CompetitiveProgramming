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

// https://codeforces.com/contest/1515/problem/F

const int N = 3e5;
vector <pi> adj[N], childs[N];
vector <bool> vis(N), taken(N);
int x;
vi ans, val(N);

void dfs2(int node){
	sort(rng(childs[node]), [&](pi p1, pi p2){
		return val[p1.F] > val[p2.F];
	});
	for(auto [child, egno] : childs[node]){
		if(taken[egno] == false){
			ans.pb(egno);
			taken[egno] = true;
			dfs2(child);
		}
	}
}

void dfs(int node = 0){
	vis[node] = true;
	for(auto [child, egno] : adj[node]){
		if(vis[child] == true) continue;
		childs[node].pb({child, egno});
		dfs(child);
	}

	int have = val[node], req = SZ(childs[node]) * x;
	for(auto [child, egno] : childs[node]){
		have += val[child];
	}

	val[node] = have - req;
	if(val[node] >= 0){
		dfs2(node);
	}
}

void solve(){
    int n, m; cin >> n >> m >> x;
    for(int i = 0; i < n; ++i){
    	cin >> val[i];
    }
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb({v, i});
    	adj[v].pb({u, i});
    }
    if(accumulate(rng(val), 0ll) < x * (n - 1)){
    	cout << "NO" << el;
    	return;
    }
    dfs();
    cout << "YES" << el;
    for(int i : ans) cout << i + 1 << el;
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