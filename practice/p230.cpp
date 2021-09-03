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

void solve(){
	int n, m; cin >> n >> m;
	vector <pi> adj[n];
	for(int i = 0; i < m; ++i){
		int u, v, w; cin >> u >> v >> w;
		u--, v--;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}

    vector <ll> cost(n * (m + 1), 1e18);
    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <>> PQ;
    PQ.push({cost[0] = 0, 0});

    vector <int> mn(n, m + 2);

    while(SZ(PQ)){
        auto [wt, node] = PQ.top(); PQ.pop();
        ll u = node / (m + 1), eg = node % (m + 1);
        if(wt > cost[node] or eg == m or eg > mn[u]){
            continue;
        }
        mn[u] = eg;
        for(auto [v, w] : adj[u]){
        	int child = v * (m + 1) + eg + 1;
            if(cost[child] > cost[node] + w * (eg + 1)){
                cost[child] = cost[node] + w * (eg + 1);
                PQ.push({cost[child], child});
            }
        }
    }


    for(int i = 0; i < n; ++i){
    	ll x = *min_element(cost.begin() + (i) * (m + 1), cost.begin() + (i + 1) * (m + 1));
    	if(x >= 1e18){
    		x = -1;
    	}
    	cout << x << el;
    }
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