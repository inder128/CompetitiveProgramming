#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
// #define int long long
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

// https://www.spoj.com/problems/QTREE5/
// O(n*log(n) + q*log(n)*log(n)) -> tle solution;
// centroid decomposition;
// ipc2020;

// for unordered_set <pi>;
struct pairHash{
    inline size_t operator()(const pi &p) const{
        return p.F * 31 + p.S;
    }
};

const int N = 1e5, logN = 40;
unordered_set <int> adj[N];
vi size(N);

// centroid tree data structure;
vi papa(N), level(N);
vvi dist(N, vi(logN));
// dist[i][l] -> distance of node(i) from its ancestor at l'th level in centroid tree;
// every node will have a unique ancestor at some specific level;

// problem specific data structure;
set <pi> childAns[N];
vector <bool> isWhite(N);
vi nearestWhite(N, 1e9);


int getSize(int node, int par = -1){
    size[node] = 1;
    for(auto child : adj[node]){
        if(child == par) continue;
        size[node] += getSize(child, node);
    }
    return size[node];
}

int findCentroid(int node, int par, int &sz){
    for(auto child : adj[node]){
        if(child == par) continue;
        if(size[child] > sz / 2){
            return findCentroid(child, node, sz);
        }
    }
    return node;
}

void compute(int node, int par, int &centlvl){
    for(auto child : adj[node]){
        if(child == par) continue;
        // problem specific code;
        dist[child][centlvl] = dist[node][centlvl] + 1;
        compute(child, node, centlvl);
    }
}

void dfs(int node, int par, int &centroid){
    for(auto child : adj[node]){
        if(child == par) continue;

        childAns[centroid].insert(
            {
                dist[child][level[centroid]] + nearestWhite[child], 
                child
            }
        );

        dfs(child, node, centroid);
    }
}


void reCompute(int node){
    if(isWhite[node]){
        nearestWhite[node] = 0;
    }
    else{
        nearestWhite[node] = (childAns[node].size() ? childAns[node].begin()->F : 1e9);
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

    for(auto newRoot : adj[centroid]){
        adj[newRoot].erase(centroid);
        decompose(newRoot, centroid);
    }

    dfs(centroid, -1, centroid);
    reCompute(centroid);

    adj[centroid].clear();
}



void solve(){
    int n; cin>>n;
    for(int i = 0; i < n - 1; ++i){
        int u, v; cin>>u>>v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    decompose();

    int q; cin>>q;
    while(q--){
        int op; cin>>op;
        if(op == 0){
            int u; cin>>u;
            u--;

            int pu = u;
            vector <pi> oldValPr;
            while(pu != -1){
                oldValPr.pb({nearestWhite[pu], pu});
                pu = papa[pu];
            }

            isWhite[u] = !isWhite[u];
            reCompute(u);

            // u, pu, ppu, pppu , ----- ;
            for(int i = 1; i < oldValPr.size(); ++i){
                int pu = oldValPr[i].S;
                for(int j = 0; j < i; ++j){
                    int cu = oldValPr[j].S;
                    childAns[pu].erase({oldValPr[j].F + dist[cu][level[pu]], cu});
                    childAns[pu].insert({nearestWhite[cu] + dist[cu][level[pu]], cu});      
                }
                reCompute(pu);
            }

        }
        else{
            int u; cin>>u;
            u--;

            // get(u);
            int ans = 1e9, pu = u;
            while(pu != -1){
                mini(ans, nearestWhite[pu] + dist[u][level[pu]]);
                pu = papa[pu];
            }

            if(ans >= 1e9) ans = -1;
            cout<<ans<<el;
        }
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