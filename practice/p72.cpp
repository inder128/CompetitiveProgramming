#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
// #define int long long
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/contest/1338/problem/B
// tricky question;

const int N = 1e5;
vi adj[N], dist(N), isLeaf(N);

void dfs(int node, int par, int depth){
	isLeaf[node] = (adj[node].size() == 1);
	dist[node] = depth;
	for(int ch : adj[node]){
		if(ch == par) continue;
		dfs(ch, node, depth + 1);
	}
}

void solve(){
    int n; cin>>n;
    for (int i = 0; i < n - 1; ++i){
    	int u, v; cin>>u>>v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    for (int i = 0; i < n; ++i){
    	if(adj[i].size() != 1) continue;
    	dfs(i, -1, 0);
    	break;
    }
    bool isOdd = false;
    for (int i = 0; i < n; ++i){
    	if(!isLeaf[i]) continue;
    	isOdd |= (dist[i] % 2);
    }
    cout<<(isOdd ? 3 : 1)<<" ";
    int ans = (n - 1) - count(isLeaf.begin(), isLeaf.begin() + n, 1);
    for (int i = 0; i < n; ++i){
    	if(isLeaf[i]) continue;
    	bool leafAdj = false;
    	for(int ch : adj[i]){
    		leafAdj |= isLeaf[ch];
    	}
    	if(leafAdj) ans++;
    }
    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}