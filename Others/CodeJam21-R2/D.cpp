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


struct edge{
    int u, v;
    int cap, flow = 0;
    edge(int u, int v, int cap) : u(u), v(v), cap(cap) {}
};
 
 
struct Dinic{
    vi lvl, ptr;
    vvi adj;
    vector <edge> edges;
    queue <int> Q;
    int n, m = 0;
    int s, t;
    const int inf = 1e9;
    
    Dinic(int n, int s, int t) : n(n), s(s), t(t){
        adj.resize(n);
        lvl.resize(n);
        ptr.resize(n);
    }
    void addEdge(int u, int v, int c){
    	// db(u, v);
        edges.emplace_back(u, v, c);
        edges.emplace_back(v, u, 0);
        adj[u].pb(m);
        adj[v].pb(m + 1);
        m += 2;
    }
    
    
    bool bfs(){
        while(!Q.empty()){
            int f = Q.front();
            Q.pop();
            for(auto it: adj[f]){
                if(lvl[edges[it].v] != -1 or edges[it].cap - edges[it].flow < 1){
                    continue;
                }
                lvl[edges[it].v] = lvl[f] + 1;
                Q.push(edges[it].v);
            }
        }
        return lvl[t] != -1;
    }
    
    
    int dfs(int u, int bneck){
        if(bneck == 0 or u == t){
            return bneck;
        }
        for(int& id = ptr[u]; id < adj[u].size(); id++){
            int it = adj[u][id];
            if(lvl[edges[it].v] != lvl[u] + 1 or edges[it].cap - edges[it].flow < 1){
                continue;
            }
            int f = dfs(edges[it].v, min(bneck, edges[it].cap - edges[it].flow));
            if(f == 0){
                continue;
            }
            edges[it].flow += f;
            edges[it ^ 1].flow -= f;
            return f;
        }
        return 0;
    }
    
    
    int flow(){
        int f = 0;
        while(true){
            lvl.assign(n, -1);
            lvl[s] = 0;
            Q.push(s);
            if(bfs() == false){
                break;
            }
            ptr.assign(n, 0);
            while(int bneck = dfs(s,inf)){
                f += bneck;
            }
        }
        return f;
    }
};


void solve(){
    int n, m, x; cin >> n >> m >> x >> x;
    vector <string> a(n), b(n); 
    cin >> a >> b;
    Dinic dn(n * m + 2, n * m, n * m + 1);

    int tot = 0;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		tot += a[i][j] != b[i][j];
    	}
    }

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		if((i + j) % 2){
    			dn.addEdge(i * m + j, n * m + 1, 1);
    		}
    		else{
    			dn.addEdge(n * m, i * m + j, 1);
    		}
    	}
    }

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m - 1; ++j){
    		int u = i * m + j, v = i * m + (j + 1);
    		if(a[i][j] != b[i][j] and a[i][j + 1] != b[i][j + 1] and a[i][j] != a[i][j + 1]){
    			if((i + j) % 2 == 0){
    				dn.addEdge(u, v, 1);
    			}
    			else{
    				dn.addEdge(v, u, 1);
    			}
    		}
    	}
    }

    for(int i = 0; i < n - 1; ++i){
    	for(int j = 0; j < m; ++j){
    		int u = i * m + j, v = (i + 1) * m + j;
    		if(a[i][j] != b[i][j] and a[i + 1][j] != b[i + 1][j] and a[i][j] != a[i + 1][j]){
    			if((i + j) % 2 == 0){
    				dn.addEdge(u, v, 1);
    			}
    			else{
    				dn.addEdge(v, u, 1);
    			}
    		}
    	}
    }

    int mx = dn.flow();
    cout << tot - 2 * mx + mx << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin >> T;
    while(T--){
    	cout << "Case #" << tc << ": ";
    	tc++;
        solve();
    }
    return 0;
}