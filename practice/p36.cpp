#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; 
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

const int N = 2e5;
vi adj[N];
vi depth(N);

// run bfs with a given root and returns farthest node from root;
// na1 and na2 are nodes which must be avoided while doing bfs;
int bfs(int root = 0, int na1 = -1, int na2 = -1){
    queue <int> Q;
    Q.push(root);
    depth[root] = 0;
    int node;
    while(!Q.empty()){
        node = Q.front(); Q.pop();
        for(int child : adj[node]){
            if(depth[child] != -1) continue;
            if(child == na1 or child == na2) continue;
            depth[child] = depth[node] + 1;
            Q.push(child);
        }
    }
    return node;
}

void solve(){
    int n; cin>>n;
    for (int i = 0; i < n-1; ++i){
        int u, v; cin>>u>>v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // findind the ending points of the diameter of the tree;
    fill(depth.begin(), depth.begin() + n, -1);
    int d1 = bfs();
    fill(depth.begin(), depth.begin() + n, -1);
    int d2 = bfs(d1);

    // finding the diameter;
    vi path;
    int node = d2;
    while(depth[node]){
        path.pb(node);
        for(int child : adj[node]){
            if(depth[child] == depth[node] - 1){
                node = child;
                break;
            }
        }
    }
    path.pb(node);

    // findind the third node;
    fill(depth.begin(), depth.begin() + n, -1);
    int d3 = 0;
    for (int i = 1; i < path.size()-1; ++i){
        int td3 = bfs(path[i], path[i-1], path[i+1]);
        if(depth[td3] > depth[d3]) d3 = td3;
    }

    cout<<path.size()-1 + depth[d3]<<el;
    cout<<d1+1<<" "<<d3+1<<" "<<d2+1<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}