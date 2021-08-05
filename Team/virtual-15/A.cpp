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

const int N = 1e5;
vvi DP(N, vi(2));
vi adj[N];
vi l(N), r(N);

void dfs(int node = 0, int par = -1){
	for (int child : adj[node]){
		if(child == par){
			continue;
		}
		dfs(child, node);
		DP[node][0] += max(DP[child][0] + abs(l[child] - l[node]), DP[child][1] + abs(r[child] - l[node]));
		DP[node][1] += max(DP[child][0] + abs(l[child] - r[node]), DP[child][1] + abs(r[child] - r[node]));
	}
}

void solve(){
	int n; cin >> n;

	for (int i = 0; i < n; ++i){
		adj[i].clear();
		DP[i] = {0, 0};
	}

	for (int i = 0; i < n; ++i){
		cin >> l[i] >> r[i];
	}
	for (int i = 0; i < n - 1; ++i){
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

    dfs();

    cout << max(DP[0][0], DP[0][1]) << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}