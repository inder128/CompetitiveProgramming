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

int n, l;
const int N = 2e5;
vi adj[N], par(N), lvl(N), subtreeSize(N);
vector <bool> del(N);


int dist(int u){
	cout << "d " << u + 1 << endl;
	int d; cin >> d;
	return d;
}

int nxt(int u){
	cout << "s " << u + 1 << endl;
	int s; cin >> s;
	return s - 1;
}

int get(int root){
	if(lvl[root] == l){
		return root;
	}
	if(lvl[root] == l - 1){
		return nxt(root);
	}

	function <int(int, int)> getSize = [&](int node, int p){
        subtreeSize[node] = 1;
        for(auto child : adj[node]){
            if(child == p or lvl[child] == l or del[child]) continue;
            subtreeSize[node] += getSize(child, node);
        }
        return subtreeSize[node];
    };
    int totalSize = getSize(root, par[root]);
    function <int(int, int)> findCentroid = [&](int node, int p){
        for(auto child : adj[node]){
            if(child == p or lvl[child] == l or del[child]) continue;
            if(subtreeSize[child] > totalSize / 2){
                return findCentroid(child, node);
            }
        }
        return node;
    };
    int centroid = findCentroid(root, par[root]);

	int d = centroid ? dist(centroid) : l;

	if(d == l - lvl[centroid]){
		return get(nxt(centroid));
	}
	else{
		del[centroid] = true;
		return get(root);
	}
}

void dfs(int node = 0, int p = -1, int l = 0){
	par[node] = p, lvl[node] = l;
	for(int child : adj[node]){
		if(child == p){
			continue;
		}
		dfs(child, node, l + 1);
	}
}

void solve(){
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs();
    l = dist(0);
    int ans = get(0);
    cout << "! " << ans + 1 << el;
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