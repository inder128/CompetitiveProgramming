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

// https://acm.timus.ru/problem.aspx?space=1&num=1471
// centroid decomposition;
// ipc2020;

struct pairHash{
    inline size_t operator()(const pi &p) const{
        return p.F * 31 + p.S;
    }
};

const int N = 1e5, logN = 18;
unordered_set <pi, pairHash> adj[N];
vi size(N);

// centroid tree data structure;
vi papa(N), level(N);

// problem specific data structure;
vvi dist(N, vi(logN));
// dist[i][l] -> distance of node(i) from its ancestor at l'th level in centroid tree;
// every node will have a unique ancestor at some specific level;


int getSize(int node, int par = -1){
    size[node] = 1;
    for(pi childPr : adj[node]){
        if(childPr.F == par) continue;
        size[node] += getSize(childPr.F, node);
    }
    return size[node];
}

int findCentroid(int node, int par, int &sz){
    for(pi childPr : adj[node]){
        if(childPr.F == par) continue;
        if(size[childPr.F] > sz / 2){
            return findCentroid(childPr.F, node, sz);
        }
    }
    return node;
}

void compute(int node, int par, int &centlvl){
    for(pi childPr : adj[node]){
        if(childPr.F == par) continue;
        // problem specific code;
        dist[childPr.F][centlvl] = dist[node][centlvl] + childPr.S;
        compute(childPr.F, node, centlvl);
    }
}


void decompose(int root = 0, int par = -1){
    int sz = getSize(root);
    int centroid = findCentroid(root, -1, sz);

    papa[centroid] = par;
    if(par != -1){
        level[centroid] = level[par] + 1;
    }

    compute(centroid, -1, level[centroid]);

    for(pi newRootPr : adj[centroid]){
        adj[newRootPr.F].erase({centroid, newRootPr.S});
        decompose(newRootPr.F, centroid);
    }
    adj[centroid].clear();
}



void solve(){
    int n; cin>>n;
    for(int i = 0; i < n - 1; ++i){
        int u, v, w; cin>>u>>v>>w;
        // u--, v--;
        adj[u].insert({v, w});
        adj[v].insert({u, w});
    }
    decompose();

    // problem specific code;
    int q; cin>>q;
    while(q--){
        int u, v; cin>>u>>v;
        // u--, v--;

        if(level[u] > level[v]) swap(u, v);
        // level[u] <= level[v]; u -> v;

        int au = u, av = v;
        while(level[av] > level[u]) av = papa[av];

        // level[au] == level[av];
        while(au != av){
            au = papa[au];
            av = papa[av];
        }

        // au == av => lca of u, v;
        cout<<dist[u][level[au]] + dist[v][level[au]]<<el;
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