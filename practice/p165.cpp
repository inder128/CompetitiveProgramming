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

typedef array <int, 3> node;
const int N = 2e5;
vector <pi> adj[N];
vi f{0, 1, -1, 0};

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
    	int u, v, w; cin >> u >> v >> w;
    	u--, v--;
    	adj[u].pb({v, w});
    	adj[v].pb({u, w});
    }
    
    vvi cost(n, vi(4, 1e18));
    cost[0][0] = 0;
    priority_queue <node, vector <node>, greater <>> PQ;
    PQ.push({0, 0, 0});

    while(SZ(PQ)){
    	auto [wt, st, node] = PQ.top(); PQ.pop();
    	if(wt > cost[node][st]){
    		continue;
    	}
    	for(auto [child, w] : adj[node]){
    		for(int i = 0; i < 4; ++i){
    			if(st & i){
    				continue;
    			}
    			if(cost[child][st | i] > wt + w + f[i] * w){
    				cost[child][st | i] = wt + w + f[i] * w;
    				PQ.push({cost[child][st | i], st | i, child});
    			}
    		}
    	}
    }

    for(int i = 1; i < n; ++i){
    	cout << cost[i][3] << " ";
    }
    cout << el;
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