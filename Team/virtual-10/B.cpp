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

const int N = 2e5;
vi adj[N];
vi path;
vector <bool> vis(N);

void dfs(int node = 0){
	vis[node] = true;
	path.pb(node);
	for(int child : adj[node]){
		if(vis[child]){
			continue;
		}
		dfs(child);
		path.pb(node);
	}
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
    set <pi> edges;
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	if(u == v){
    		continue;
    	}
    	if(u > v){
    		swap(u, v);
    	}
    	edges.insert({u, v});
    }
    for(pi eg : edges){
    	adj[eg.F].pb(eg.S);
    	adj[eg.S].pb(eg.F);
    }
    dfs();

    assert(SZ(path) <= 2 * n);
    assert(count(vis.begin(), vis.begin() + n, true) == n);
    for(int i = 1; i < SZ(path); ++i){
    	assert(edges.count({path[i - 1], path[i]}) + edges.count({path[i], path[i - 1]}));
    }

    n = SZ(path);
    int l = 0;
    for(int i = 0; i < k; ++i){
    	int sz = n / k + (i < (n % k));
    	cout << sz << " ";
    	for(int j = l; j < l + sz; ++j){
    		cout << path[j] + 1 << " ";
    	}
    	cout << el;
    	l += sz;
    }
    assert(l == n);
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