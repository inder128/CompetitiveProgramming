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

const int inf = 1e9;

struct e{
    int u,v;
    ll cap,flow=0;
    e(int u, int v, ll cap) : u(u), v(v), cap(cap){}
};
 
 
struct dinic{
    vi lvl,ptr;
    vvi adj;
    vector<e> edges;
    queue<int> q;
    int n,m=0;
    int s,t;
    
    dinic(int n, int t) : n(n), t(t){
        adj.resize(n);
        lvl.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u, int v, ll c){
        edges.emplace_back(u,v,c);
        edges.emplace_back(v,u,0);
        adj[u].pb(m);
        adj[v].pb(m+1);
        m+=2;
    }
    
    
    bool bfs(){
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto it: adj[f]){
                if(lvl[edges[it].v]!=-1||edges[it].cap-edges[it].flow<1)
                    continue;
                lvl[edges[it].v]=lvl[f]+1;
                q.push(edges[it].v);
                
            }
        }
        return lvl[t]!=-1;
    }
    
    
    
    ll dfs(int u, ll bneck){
        if(!bneck||u==t)return bneck;
        for(int & id=ptr[u]; id<adj[u].size(); id++){
            int it=adj[u][id];
            if(lvl[edges[it].v]!=lvl[u]+1||edges[it].cap-edges[it].flow<1)
                continue;
            ll f=dfs(edges[it].v,min(bneck,edges[it].cap-edges[it].flow));
            if(!f)continue;
            edges[it].flow+=f;
            edges[it^1].flow-=f;
            return f;
        }
        return 0;
    }
    
    
    
    ll flow(){
        ll f=0;
        while(true){
            lvl.assign(n,-1);
            lvl[s]=0;
            q.push(s);
            if(!bfs())break;
            ptr.assign(n,0);
            while(ll bneck=dfs(s,inf)){f+=bneck;};
        }
        return f;
    }
    
};


vi dx{-1, 0, 0, 1}, dy{0, -1, 1, 0};
 


void solve(){
    int N, M, c;  cin >> M >> N >> c;
    vector <string> mat(N);
    for(int i = 0; i < N; ++i){
        cin >> mat[i];
    }
    map <char, int> cost;
    cost['B'] = 1e9;
    cost['.'] = 1e9;
    for(int i = 0; i < c; ++i){
        cin >> cost[(char)('a' + i)];
    }
    // cost[c] -> cost to baricade letter c;


    // n -> total no. of vertices, t -> target, s -> source;
    int n = 2 * N * M + 1, t = n - 1;

    dinic dn(n, t);

    auto entryIndex = [&](int i, int j){
    	if(i >= 0 and i < N and j >= 0 and j < M){
    		return 2 * (i * M + j);
    	}
    	return t;
    };

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            int u = entryIndex(i, j);
            if(mat[i][j] == 'B'){
                dn.s = u;
            }

            dn.add_edge(u, u + 1, cost[mat[i][j]]);

            for(int k = 0; k < 4; ++k){
            	int ni = i + dx[k], nj = j + dy[k];
            	int v = entryIndex(ni, nj);
            	dn.add_edge(u + 1, v, 1e9);
            	// multiple edge from 1 to t;
            }
        }
    }

    int ans = dn.flow();
    if(ans >= 1e9) ans = -1;

    cout << ans << el;
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