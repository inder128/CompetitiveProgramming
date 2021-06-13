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

// https://codeforces.com/contest/1521/problem/D

vector <pi> ans;

const int N = 1e5;
vector <bool> vis(N);
set <int> adj[N];

void dfs(int node = 0, int par = -1){
	if(SZ(adj[node]) == 0) return;

	int child;
	for(auto it = adj[node].begin(); it != adj[node].end(); it = adj[node].upper_bound(child)){
		child = *it;
		if(child == par) continue;
		dfs(child, node);
	}

	int chno = 0;
	if(SZ(adj[node]) == 0) return;
	for(auto it = adj[node].begin(); it != adj[node].end(); it = adj[node].upper_bound(child)){
		child = *it;
		if(child == par) continue;
		chno++;
		if(chno == 2 and par != -1){
			adj[par].erase(node);
			adj[node].erase(par);
			ans.pb({par, node});
		}
		if(chno > 2){
			adj[node].erase(child);
			adj[child].erase(node);
			ans.pb({node, child});
		}
	}
}

int dfs2(int node, int par){
	for(int child : adj[node]){
		if(child == par) continue;
		return dfs2(child, node);
	}
	vis[node] = true;
	return node;
}

void solve(){
    int n; cin >> n;
    ans.clear();
    for(int i = 0; i < n; ++i){
    	adj[i].clear();
    	vis[i] = false;
    }

    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].insert(v);
    	adj[v].insert(u);
    }

    dfs();
    int k = SZ(ans);

    int l = -1;
    for(int i = 0; i < n; ++i){
    	if(SZ(adj[i]) > 1 or vis[i]) continue;

    	if(l != -1){
    		ans.pb({l, i});
    	}

    	l = dfs2(i, -1);
    }

    assert(SZ(ans) == 2 * k);
    cout << k << el;
    for(int i = 0; i < k; ++i){
    	cout << ans[i].F + 1 << " " << ans[i].S + 1 << " ";
    	cout << ans[i + k].F + 1 << " " << ans[i + k].S + 1 << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}