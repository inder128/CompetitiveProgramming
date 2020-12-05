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

const int N = 1e5, logN = 40;
unordered_set <int> adj[N];
vi subtreeSize(N);

// centroid tree data structure;
vi papa(N), level(N);
vvi dist(N, vi(logN));
// dist[i][l] -> distance of node(i) from its ancestor at l'th level in centroid tree;
// every node will have a unique ancestor at some specific level;

// problem specific data structure;
vi order(N);

void decompose(int root = 0, int par = -1, int rnk = 0){
    // genric code;
    function <int(int, int)> getSize = [&](int node, int par){
        subtreeSize[node] = 1;
        for(auto child : adj[node]){
            if(child == par) continue;
            subtreeSize[node] += getSize(child, node);
        }
        return subtreeSize[node];
    };
    int totalSize = getSize(root, -1);
    function <int(int, int )> findCentroid = [&](int node, int par){
        for(auto child : adj[node]){
            if(child == par) continue;
            if(subtreeSize[child] > totalSize / 2){
                return findCentroid(child, node);
            }
        }
        return node;
    };
    int centroid = findCentroid(root, -1);

    // problem specific code;
    order[centroid] = rnk;

    // genric code;
    for(auto newRoot : adj[centroid]){
        adj[newRoot].erase(centroid);
        decompose(newRoot, centroid, rnk + 1);
    }
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
    for(int i = 0; i < n; ++i){
        cout<<(char)('A' + order[i])<<" ";
    }
    cout<<el;
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