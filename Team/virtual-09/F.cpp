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


const int N = 19;
int DP[N][N][1 << N];


void solve(){
    int n, m; cin >> n >> m;
    set <pi> edges;
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	edges.insert({u, v});
    	edges.insert({v, u});
    }

    vi cnt(n + 1);
    for(int msk = 0; msk < (1 << n); ++msk){
    	vi nodes;
    	for(int i = 0; i < n; ++i){
    		if(msk >> i & 1){
    			nodes.pb(i);
    		}
    	}
    	if(SZ(nodes) < 2){
    		continue;
    	}
    	if(SZ(nodes) == 2){
    		DP[nodes[0]][nodes[1]][msk] = edges.count({nodes[0], nodes[1]});
    		DP[nodes[1]][nodes[0]][msk] = DP[nodes[0]][nodes[1]][msk];
    		continue;
    	}
    	for(int i = 0; i < SZ(nodes); ++i){
    		for(int j = i + 1; j < SZ(nodes); ++j){
    			// DP[nodes[i]][nodes[j]] ??
    			// i -> k -> some nodes -> j;
    			for(int k = 0; k < SZ(nodes); ++k){
    				if(k == i or k == j){
    					continue;
    				}
    				DP[nodes[i]][nodes[j]][msk] += edges.count({nodes[i], nodes[k]}) * DP[nodes[k]][nodes[j]][msk - (1 << nodes[i])];
    			}
    			DP[nodes[j]][nodes[i]][msk] = DP[nodes[i]][nodes[j]][msk];
    			// db(nodes[i], nodes[j], msk, DP[nodes[j]][nodes[i]][msk]);
    			cnt[SZ(nodes)] += edges.count({nodes[i], nodes[j]}) * DP[nodes[i]][nodes[j]][msk];
    		}	
    	}	
    }

    int ans = 0;
    for(int i = 3; i <= n; ++i){
    	ans += cnt[i] / i;
    }

    cout << ans << el;
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