#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

const int N = 1e5;
int n, m, k; // number of nodes
vector <pi> adj[N];

vector<bool> visited(N), isBridge(2*N), rel(N);
vector<int> tin(N, -1), low(N, -1), A(N), D(2*N), dist(N, INT_MAX);
int timer = 0;

void dfs(int v = 0, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (pi toPr : adj[v]) {
    	int to = toPr.F;
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                isBridge[toPr.S] = true;
        }
    }
}

void solve(){
    cin>>n>>m>>k;
    for (int i = 0; i < n; ++i){
    	cin>>A[i];
    }
    for (int i = 0; i < m; ++i){
    	int u, v; cin>>u>>v;
    	u--, v--;
    	adj[u].pb({v, i});
    	adj[v].pb({u, i});
    	cin>>D[i];
    }

    dfs();


    priority_queue <pi, vector<pi>, greater <pi>> Q; 
    for (int i = 0; i < n; ++i){
    	int sr = 0;
    	for(pi pr : adj[i]){
    		sr += (!isBridge[pr.S]);
    	}
    	if(sr >= k){
    		Q.push({0, i});
    	}
    }
    
    while(!Q.empty()){
    	pi node = Q.top(); Q.pop();
    	if(rel[node.S]) continue;
    	rel[node.S] = true;
    	dist[node.S] = node.F;
    	for(pi pr : adj[node.S]){
    		if(isBridge[pr.S]) continue;
    		if(dist[node.S] + D[pr.S] < dist[pr.F])
    		dist[pr.F] = dist[node.S] + D[pr.S];
    		Q.push({dist[node.S] + D[pr.S], pr.F});
    	}
    }


    ll sdist = 0, sai = 0;
    for (int i = 0; i < n; ++i){
    	// db(i, dist[i]);
    	if(dist[i] != INT_MAX){
    		sdist += dist[i];
    	}
    	else{
    		sai += A[i];
    	}
    }

    cout<<sdist<<" "<<sai<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}