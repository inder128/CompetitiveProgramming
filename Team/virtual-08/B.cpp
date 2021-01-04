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


const int logN = 20, N = 1e5;
vi bl[N][logN];
vi adj[N];
vi par(N), lvl(N);
int t = 0;
vector <pi> tio(N);


vi merge(const vi& n1, const vi& n2){
	vi res(11, 1e18);
	res[0] = n2[0];
	int l = 1, r = 1;
	for(int i = 1; i < 11; ++i){
		if(n1[l] < n2[r]){
			res[i] = n1[l];
			l++;
		}
		else{
			res[i] = n2[r];
			r++;
		}
	}
	return res;
}


void dfs(int node = 0, int p = -1, int l = 0){
	tio[node].F = t++;
	par[node] = p;
	lvl[node] = l;
	for(int child : adj[node]){
		if(child == p){
			continue;
		}
		dfs(child, node, l + 1);
	}
	tio[node].S = t++;
}

bool isPar(int p, int u){
	return tio[p].F <= tio[u].F and tio[u].S <= tio[p].S;
}


int lca(int u, int v){
	// u != v;
	// lca(u, v) != u and lca(u, v) != v;
	// lvl[u] >= lvl[v];


	int j = lvl[u] - lvl[v];
	for(int i = logN - 1; i >= 0; --i){
		if((1 << i) <= j){
			u = bl[u][i][0];
			u = par[u];
			j -= (1 << i);
		}
	}


	for(int i = logN - 1; i >= 0; --i){
		int nu = bl[u][i][0], nv = bl[v][i][0];
		if(nu == nv or par[nu] == par[nv]){
			continue;
		}
		u = par[nu], v = par[nv];
	}

	return u;
}

vi get(int p, int u){
	vi ans(11, 1e18);
	int j = lvl[u] - lvl[p];
	for(int i = logN - 1; i >= 0; --i){
		if((1 << i) <= j){
			ans = merge(ans, bl[u][i]);
			u = par[bl[u][i][0]];
			j -= (1 << i);
		}
	}
	ans = merge(ans, bl[p][0]);
	return ans;
}


void solve(){
	for(int i = 0; i < N; ++i){
        for(int j = 0; j < logN; ++j){
            bl[i][j] = vi(11, 1e18);
        }
    }

    int n, m, q; cin >> n >> m >> q;
    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs();

    vi cv[n];
    for(int i = 0; i < m; ++i){
    	int c; cin >> c;
    	c--;
    	cv[c].pb(i);
    }
    for(int i = 0; i < n; ++i){
    	sort(rng(cv[i]));
    }
    for(int i = 0; i < n; ++i){
    	bl[i][0][0] = i;
    	for(int j = 0; j < min(10ll, SZ(cv[i])); ++j){
    		bl[i][0][j + 1] = cv[i][j];
    	}
    }
    for(int j = 1; j < logN; ++j){
    	for(int i = 0; i < n; ++i){
    		int p = bl[i][j - 1][0];
    		if(p == -1 or par[p] == -1){
    			bl[i][j] = bl[i][j - 1];
    		}
    		else{
    			bl[i][j] = merge(bl[i][j - 1], bl[ par[p] ][j - 1]);
    		}
    	}
    }

    while(q--){
    	int u, v, a; cin >> u >> v >> a;
    	u--, v--;

    	if(lvl[u] < lvl[v]){
    		swap(u, v);
    	}
    	// lvl[u] >= lvl[v];


    	vi res;
		if(u == v){
			res = bl[u][0];
		}
		else if(isPar(v, u)){
			res = get(v, u);
		}
		else{
			int an = lca(u, v);
			res = merge(get(an, u), get(par[an], v));
		}

    	vi ans;
    	for(int i = 1; i <= a and res[i] < 1e18; ++i){
    		ans.pb(res[i]);
    	}
    	cout << SZ(ans) << " ";
    	for(int i : ans){
    		cout << i + 1 << " ";
    	}
    	cout << el;
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