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

int no;
map <int, int> val;
vector <pi> edges;
vvi a;

class DSU{ 
public: 
    vi par;
    vector <vi> nodes;
    int n;

    DSU(int n){ 
        this->n = n; 
        par.resize(n);
        nodes.resize(n);
        for (int i = 0; i < n; ++i){
            par[i] = i;
            nodes[i].pb(i);
        }
    }

    int size(int u){
        return nodes[u].size();
    }

    bool unite(int u, int v){
        u = par[u], v = par[v];
        if(u == v) return false;

        if(size(u) > size(v)) swap(u, v);
        
        while(nodes[u].size()){
            int w = nodes[u].back(); nodes[u].pop_back();
            nodes[v].pb(w);
            par[w] = v;
        }

        return true;
    }
};

int dfs(vi leaves){
	int n = SZ(leaves);
	if(n == 1){
		val[leaves[0]] = a[leaves[0]][leaves[0]];
		return leaves[0];
	}
	
	int root = no++;

	int mx = 0;
	for(int i : leaves){
		for(int j : leaves){
			maxi(mx, a[i][j]);
		}
	}

	
	DSU dsu(n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(a[leaves[i]][leaves[j]] != mx){
				dsu.unite(i, j);
			}
		}
	}

	for(auto v : dsu.nodes){
		int nn = SZ(v);
		if(nn){
			for(int &i : v){
				i = leaves[i];
			}

			int child = dfs(v);
			edges.pb({child, root});
		}
	}

	val[root] = mx;
	return root;
}

void solve(){
    int n; cin >> n;
    a = vvi(n, vi(n)); cin >> a;

    no = n;

    vi leaves(n);
    iota(rng(leaves), 0);

    int root = dfs(leaves);

    cout << no << el;
    for(int i = 0; i < no; ++i){
    	cout << val[i] << " ";
    }
    cout << el;
    cout << root + 1 << el;
    for(auto [u, v] : edges){
    	cout << u + 1 << " " << v + 1 << el;
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