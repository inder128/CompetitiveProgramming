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
vi adj[N], depth(N), ans(N);
vector <bool> vis(N);

void dfs(int node = 0){
	vis[node] = true;
	ans[node] = depth[node];
	for(int child : adj[node]){
		if(depth[child] <= depth[node]){
			mini(ans[node], depth[child]);
		}
		else{
			if(vis[child] == false){
				dfs(child);
			}
			mini(ans[node], ans[child]);
		}
	}
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i){
    	adj[i].clear();
    	depth[i] = 1e9;
    	ans[i] = 1e9;
    	vis[i] = false;
    }
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    }

    queue <int> Q;
    Q.push(0);
    depth[0] = 0;
    while(SZ(Q)){
    	int node = Q.front(); Q.pop();
    	for(int child : adj[node]){
    		if(depth[child] > depth[node] + 1){
    			depth[child] = depth[node] + 1;
    			Q.push(child);
    		}
    	}
    }

    dfs();

    for(int i = 0; i < n; ++i){
    	cout << ans[i] << " ";
    }
    cout << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}