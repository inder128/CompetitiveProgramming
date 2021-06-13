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

// https://codeforces.com/contest/1486/problem/F

const int N = 3e5;
vi adj[N], par(N), lvl(N), tadj[N];
vector <pi> tio(N);
vvi up(N, vi(20, -1));
int t = 0;

void dfs(int node = 0, int dad = -1){
	tio[node].F = t++;
 
	par[node] = up[node][0] = dad;
	for(int i = 1; i < 20; ++i){
		if(up[node][i-1] != -1){
			up[node][i] = up[up[node][i-1]][i-1];
		}
	}
 
	for(int child : adj[node]){
		adj[child].erase(find(rng(adj[child]), node));

		lvl[child] = lvl[node] + 1;
		dfs(child, node);

		tadj[node].pb(tio[child].F);
	}
 
	tio[node].S = t++;
}
 
bool isAncestor(int rt, int ch){
	return (tio[rt].F <= tio[ch].F and tio[rt].S >= tio[ch].S);
}
 
int lca(int u, int v){
	if(isAncestor(u, v)){
		return u;
	}
 
	for (int i = 19; i >= 0; --i){
		if(up[u][i] == -1) continue;
		if(isAncestor(up[u][i], v) == false){
			u = up[u][i];
		}
	}

	return par[u];
}

int get(int a, int c){
	int ans = adj[a][upper_bound(rng(tadj[a]), tio[c].F) - tadj[a].begin() - 1];
	return ans;
}

vi upar(N), niche[N], sm(N);
vector <pi> ances[N];
int ans = 0;

int dfs2(int node = 0, int dap = -1){
	map <int, int> gup;
	for(int child : adj[node]){
		gup[child] = dfs2(child, node);
	}

	for(int u : niche[node]){
		gup[u]--;
	}
	for(auto [u, v] : ances[node]){
		gup[u]--, gup[v]--;
	}

	int ret = 0;
	for(auto [x, cnt] : gup){
		ret += cnt;
	}


	int pass = SZ(niche[node]) + SZ(ances[node]) + upar[node] + ret;
	ans += sm[node] * (sm[node] - 1) / 2 + sm[node] * pass;

	ans += upar[node] * (SZ(niche[node]) + SZ(ances[node]));

	
	map <int, int> nicheCnt;
	for(int u : niche[node]){
		nicheCnt[u]++;
	}
	for(auto [u, v] : ances[node]){
		ans += SZ(niche[node]) + ret - nicheCnt[u] - nicheCnt[v] - gup[u] - gup[v];
	}

	for(auto u : niche[node]){
		ans += (ret - gup[u]);
	}

	
	int rem = SZ(niche[node]);
	for(auto [u, uCnt] : nicheCnt){
		rem -= uCnt;
		ans += uCnt * rem;
	}

	map <int, int> endCnt;
	map <pi, int> ancesCnt;
	for(auto [u, v] : ances[node]){
		endCnt[u]++, endCnt[v]++;
		ancesCnt[{u, v}]++;
	}
	int ancesAns = 0;
	for(auto [u, v] : ances[node]){
		ancesAns += SZ(ances[node]) - endCnt[u] - endCnt[v] + ancesCnt[{u, v}] + ancesCnt[{v, u}];
	}
	ans += ancesAns / 2;
	
	return ret + upar[node];
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    dfs();

   	int m; cin >> m;
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	if(u == v){
    		sm[u]++;
    		continue;
    	}

    	int a = lca(u, v);
    	if(a == u){
    		niche[u].pb({get(u, v)});
    		upar[v]++;
    	}
    	else if(a == v){
    		niche[v].pb({get(v, u)});
    		upar[u]++;
    	}
    	else{
    		upar[u]++;
    		upar[v]++;
    		ances[a].pb({get(a, u), get(a, v)});
    	}
    }

    dfs2();

    cout << ans << el;
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