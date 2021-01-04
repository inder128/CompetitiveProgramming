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
istream&operator>>(istream&is,vector<T>&node){for(auto&it:node)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto node : V) os << node << " "; return os << "]"; }
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



const int N = 1e5;
vi adj[N];
vector<bool> vis(N);
vi tin(N), low(N);
int timer = 0;

vector <pi> edges;

bool dfs(int node, int par = -1){
	db(node + 1);
    vis[node] = true;
    tin[node] = low[node] = timer++;
    for(int child : adj[node]){
        if(child == par){
        	continue;
        }
        if(vis[child]){
            low[node] = min(low[node], tin[child]);
            if(tin[child] < tin[node]){
            	edges.pb({node, child});
            }
        }
        else{
        	edges.pb({node, child});
            if(dfs(child, node) == false){
            	return false;
            }
            low[node] = min(low[node], low[child]);
            if(low[child] > tin[node]){
                return false;
            }
        }
    }
    return true;
}

void solve() {
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
    for (int i = 0; i < n; ++i) {
        if(vis[i]){
        	continue;
        }
        if(dfs(i) == false){
        	cout << 0 << el;
        	return;
        }
    }
    for(pi eg : edges){
    	cout << eg.F + 1 << " " << eg.S + 1 << el;
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