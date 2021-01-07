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

const int N = 3e5;
vi adj[N], adjr[N], cno(N, -1), tin(N), low(N);
set <pi> edges, bridgeEdges;
vector<bool> visited(N);
int timer = 0, csz = 0;

void dfs(int v = 0, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                bridgeEdges.insert({v, to});
                bridgeEdges.insert({to, v});
            }
        }
    }
}

void dfs2(int node = 0){
	cno[node] = csz;
	for(int child : adj[node]){
		if(cno[child] != -1){
			continue;
		}
		if(bridgeEdges.count({node, child})){
			continue;
		}
		dfs2(child);
	}
}


pi bfs(int root){
	vi dist(csz, 1e9);
	queue <int> Q; Q.push(root); dist[root] = 0;	
	int node;
	while(SZ(Q)){
		node = Q.front(); Q.pop();
		for(int child : adjr[node]){
			if(dist[child] > dist[node] + 1){
				dist[child] = dist[node] + 1;
				Q.push(child);
			}
		}
	}
	return {node, dist[node]};
}


void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	edges.insert({u, v});
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    dfs();

    for(int i = 0; i < n; ++i){
    	if(cno[i] == -1){
    		dfs2(i);
    		csz++;
    	}
    }

    for(pi eg : edges){
    	if(bridgeEdges.count(eg)){
    		adjr[cno[eg.F]].pb(cno[eg.S]);
    		adjr[cno[eg.S]].pb(cno[eg.F]);
    	}
    }


    pi res = bfs(0);
    res = bfs(res.F);
    cout << res.S << el;
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