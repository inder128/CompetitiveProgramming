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


bool isPrime(int x){
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}


const int N = 2e2;
vi adj[N];
vector <bool> vis(N);
vvi cycs;
vi cyc;


void dfs(int node, int par = -1){
    cyc.pb(node);
    vis[node] = true;
    for(int child : adj[node]){
        if(child == par or vis[child]){
            continue;
        }
        dfs(child, node);
    }
}


void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;

    vector <pi> odds, evens;
    for(int i = 0; i < n; ++i){
        if(a[i] % 2){
            odds.pb({a[i], i});
        }
        else{
            evens.pb({a[i], i});
        }
    }
    if(SZ(odds) != SZ(evens)){
        cout << "Impossible" << el;
        return;
    }

    vector <pi> edges;
    Dinic dn(n + 2, n, n + 1);
    for(int i = 0; i < n / 2; ++i){
        for(int j = 0; j < n / 2; ++j){
            if(isPrime(evens[i].F + odds[j].F)){
                edges.pb({evens[i].S, odds[j].S});
                dn.addEdge(i, j + n / 2, 1);
            }
        }
    }
    for(int i = 0; i < n / 2; ++i){
        dn.addEdge(n, i, 2);
        dn.addEdge(i + n / 2, n + 1, 2);
    }

    int mxFlow = dn.flow();

    if(mxFlow != n){
        cout << "Impossible" << el;
        return;
    }


    for(int i = 0; i < SZ(edges); ++i){
        if(dn.edges[2 * i].flow == 1){
            adj[edges[i].F].pb(edges[i].S);
            adj[edges[i].S].pb(edges[i].F);
        }
    }

    for(int i = 0; i < n; ++i){
        if(vis[i]){
            continue;
        }
        dfs(i);
        cycs.pb(cyc);
        cyc.clear();
    }

    cout << SZ(cycs) << el;
    for(auto cyc : cycs){
        cout << SZ(cyc) << " ";
        for(int u : cyc){
            cout << u + 1 << " ";
            // cout << a[u] << " ";
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