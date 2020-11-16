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

// https://codeforces.com/contest/1364/problem/D
// nice question;
// nice editorial;
// check wrong soln in p81.cpp;

const int N = 1e5;
vi adj[N], col(N, -1), cyc;

bool dfs(int node = 0, int c = 0, int par = -1){
	col[node] = c;
	for(int child : adj[node]){
		if(child == par) continue;
		if(col[child] != -1){
			cyc.pb(child);
			cyc.pb(node);
			return true;
		}
		bool ans = dfs(child, c ^ 1, node);
		if(ans){
			if(node == cyc[0]) return false;
			cyc.pb(node);
			return true;
		}
		if(cyc.size()) return false;
	}
	return false;
}

void solve(){
	int n, m, k; cin>>n>>m>>k;
	vector <pi> edges(m);
    for (int i = 0; i < m; ++i){
    	int u, v; cin>>u>>v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	edges[i] = {u, v};
    }
    dfs();
    if(cyc.size() == 0){
    	int c1 = count(col.begin(), col.begin() + n, 1);
    	int pnts = (k + 1) / 2;
    	int c = (c1 >= pnts);
    	cout<<1<<el;
    	for (int i = 0; i < n and pnts; ++i){
    		if(col[i] != c) continue;
    		cout<<i + 1<<" ";
    		pnts--;
    	}
    	return;
    }

    int l = 1, r = cyc.size();
    map <int, int> ind;
    for (int i = 0; i < cyc.size(); ++i){
    	ind[cyc[i]] = i + 1;
    }

    // db(cyc);
    for(pi eg : edges){
    	int ui = ind[eg.F], vi = ind[eg.S];
    	if(ui == 0 or vi == 0) continue;
    	if(ui > vi) swap(ui, vi);
    	if(vi - ui == 1 or (ui == l and vi == r)) continue;
    	if(ui < l or vi > r) continue;
    	l = ui, r = vi;
    	// db(l, r, ui, vi);
    }

    if(r - l + 1 <= k){
    	cout<<2<<el<<(r - l + 1)<<el;
    	for (int i = l - 1; i <= r - 1; ++i){
    		cout<<cyc[i] + 1<<" ";
    	}
    	cout<<el;
    	return;
    }

    cout<<1<<el;
    for (int i = 0; i < (k + 1) / 2; ++i){
    	cout<<cyc[l - 1 + 2*i] + 1<<" ";
    }
    cout<<el;
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