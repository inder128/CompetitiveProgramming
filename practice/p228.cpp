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

// https://codeforces.com/contest/1527/problem/D

const int N = 2e5;
vi adj[N], sz(N), par(N), chain(N);
int f1, f2;


void dfs(int node = 0, int p = -1){
	sz[node] = 1;
	par[node] = p;
	for(int child : adj[node]){
		if(child == p){
			continue;
		}
		dfs(child, node);
		sz[node] += sz[child];
	}
}


void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
    	adj[i].clear();
    	chain[i] = false;
    }

    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    dfs();

    vi ans(n + 1);
    for(int child : adj[0]){
    	ans[0] += sz[child] * (sz[child] - 1) / 2;
    }

    int u = 1;
    while(par[u]){
    	chain[u] = true;
    	u = par[u];
    }
    sz[0] -= sz[u];
    chain[u] = true;
    chain[0] = true;

    int cnt = 1;
    for(int child : adj[0]){
    	if(chain[child]){
    		ans[1] += cnt * (sz[child] - sz[1]);
    		cnt += sz[child] - sz[1];
    	}
    	else{
    		ans[1] += cnt * sz[child];
	    	cnt += sz[child];
    	}	
    }

    int s = 1, e = 0;
    for(int i = 2; i <= n; ++i){
    	if(i == n){
    		ans[i] = 1;
    		continue;
    	}

    	if(chain[i]){
    		continue;
    	}

    	int u = i;
    	while(chain[u] == false){
    		chain[u] = true;
    		u = par[u];
    	}

    	if(u == s or u == e){
    		ans[i] = (sz[u] - sz[i]) * sz[s + e - u];
    		if(u == s){
    			s = i;
    		}
    		else{
    			e = i;
    		}
    	}
    	else{
    		ans[i] = sz[s] * sz[e];
    		break;
    	}
    }

    for(int i = 0; i <= n; ++i){
    	cout << ans[i] << " ";
    }
    cout << el;
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