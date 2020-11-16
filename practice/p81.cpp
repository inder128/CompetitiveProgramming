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


const int N = 1e5;
vi adj[N], col(N, -1);

int dfs(int node = 0, int c = 0, int par = -1){
	col[node] = c;
	for(int child : adj[node]){
		if(child == par) continue;
		if(col[child] != -1) return child;
		int ver = dfs(child, c ^ 1, node);
		if(ver != -1) return ver;
	}
	return -1;
}

void solve(){
	int n, m, k; cin>>n>>m>>k;
    for (int i = 0; i < m; ++i){
    	int u, v; cin>>u>>v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    int ver = dfs();
    if(ver == -1){
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

    // bfs
    // wrong
    // wrong
    // wrong
    // wrong
    // wrong
    // consoder -> ver = 1;
    //   5 - 6
    //  /     \
    // 1 - 2 - 4
    //      \ /
    //       3
    queue <int> Q;
	Q.push(ver);
	vi dist(n, -2);
	dist[ver] = 0;
	int u = -1, v = -1;
	while(Q.size()){
		int node = Q.front(); Q.pop();
		for(int child : adj[node]){
			if(dist[child] == dist[node] - 1) continue;
			if(dist[child] != -2){
				v = child, u = node;
				break;
			}
			Q.push(child);
			dist[child] = dist[node] + 1;
		}
		if(v != -1) break;
	}


	vi path;
	int curr = u;
	while(curr != ver){
		path.pb(curr);
		for(int child : adj[curr]){
			if(dist[child] == dist[curr] - 1){
				curr = child;
				break;
			}
		}
	}

	path.pb(ver);
	reverse(rng(path));	

	curr = v;
	while(curr != ver){
		path.pb(curr);
		for(int child : adj[curr]){
			if(dist[child] == dist[curr] - 1 and child != u){
				curr = child;
				break;
			}
		}
	}

	// db(u, v, ver);
	if(path.size() <= k){
		cout<<2<<el<<path.size()<<el;
		for(int i : path) cout<<i + 1<<" "; cout<<el;
		return;
	}

	cout<<1<<el;
	for (int i = 0; i < (k + 1) / 2; ++i){
		cout<<path[2*i] + 1<<" ";
	}
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