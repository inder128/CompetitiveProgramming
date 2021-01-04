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

const int N = 2e5 + 1;
vector <pi> adj[N];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
    	int u, v, w; cin >> u >> v >> w;
    	w *= 2;
    	adj[u].pb({v, w});
    	adj[v].pb({u, w});
    }
    for(int i = 1; i <= n; ++i){
    	int w; cin >> w;
    	adj[0].pb({i, w});
    	adj[i].pb({0, w});
    }

    priority_queue <pi, vector<pi>, greater<pi>> PQ;
    PQ.push({0, 0});
    vector <bool> vis(n + 1);
    vi dist(N + 1, 1e18);
    while(SZ(PQ)){
    	pi tp = PQ.top(); PQ.pop();
    	int node = tp.S;
    	if(vis[node]){
    		continue;
    	}
    	vis[node] = true;
    	dist[node] = tp.F;
    	for(pi childPr : adj[node]){
    		int child = childPr.F;
    		if(vis[child]){
    			continue;
    		}
    		if(dist[child] > dist[node] + childPr.S){
    			dist[child] = dist[node] + childPr.S;
    			PQ.push({dist[child], child});
    		}
    	}
    }

    for(int i = 1; i <= n; ++i){
    	cout << dist[i] << " ";
    }
    cout << el;
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