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


const int N = 1e5;
vector <pi> adj[N];
vector <bool> dead(N);
vi dr(N, 1e9), dt(N, 1e9);


void bfs(int root, vi& d){
	queue <int> Q; Q.push(root);
	d[root] = 0;
	while(SZ(Q)){
		int node = Q.front(); Q.pop();
		for(auto cw : adj[node]){
			if(d[cw.F] > d[node] + 1){
				d[cw.F] = d[node] + 1;
				Q.push(cw.F);
			}
		}
	}
}


void solve(){
	int n, m; cin >> n >> m;
    vector <pair <pi, int>> edges;
    for(int i = 0; i < m; ++i){
    	int u, v, w; cin >> u >> v >> w;
    	u--, v--;
    	edges.pb({{u, v}, w});
    	adj[u].pb({v, w});
    	adj[v].pb({u, w});
    }

    bfs(0, dr);
    bfs(n - 1, dt);

    for(int i = 0; i < n; ++i){
    	if(dr[i] + dt[i] > dr[n - 1]){
    		dead[i] = true;
    		// db(i);
    	}
    }

    vi good(dr[n - 1]);
    for(auto eg : edges){
    	if(dead[eg.F.F] or dead[eg.F.S]){
    		continue;
    	}
    	good[min(dr[eg.F.F], dr[eg.F.S])] += eg.S;
    }

    vi DP(n, 1e9), link(n);
    vector <bool> vis(n);
    DP[0] = 0;
    vis[0] = true;
    queue <int> Q; Q.push(0);
    while(SZ(Q)){
    	int node = Q.front(); Q.pop();
    	for(auto aw : adj[node]){
    		if(dead[aw.F] == false and dr[aw.F] == dr[node] - 1){
    			int df = aw.S ? -1 : 1;
    			if(DP[node] > DP[aw.F] + good[dr[aw.F]] + df){
    				DP[node] = DP[aw.F] + good[dr[aw.F]] + df;
    				link[node] = aw.F;
    			}
    		}
    		if(dead[aw.F] == false and vis[aw.F] == false and dr[aw.F] == dr[node] + 1){
    			Q.push(aw.F);
    			vis[aw.F] = true;
    		}
    	}
    }

    set <pi> path;
    int curr = n - 1;
    while(curr){
    	path.insert({curr, link[curr]});
    	path.insert({link[curr], curr});
    	curr = link[curr];
    }
    // db(path);

    vector <pair <pi, int>> ans;
    for(auto eg : edges){
    	if(path.count(eg.F)){
    		if(eg.S == 0){
    			ans.pb({eg.F, !eg.S});
    		}
    	}
    	else{
    		if(eg.S == 1){
    			ans.pb({eg.F, !eg.S});
    		}
    	}
    }


    cout << SZ(ans) << el;
    for(auto eg : ans){
    	cout << eg.F.F + 1 << " " << eg.F.S + 1 << " " << eg.S << el;
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