#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
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
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// nice problem
// Dynamic root shifting
// see tle submission
const int N = 1e5;
int M;
vl DP(N, 1), ans(N, 1);
vi adj[N];

void dfs(int node = 0, int par = -1){
    for (int child : adj[node]){
        if(child == par) continue;
        dfs(child, node);
        DP[node] *= DP[child];
        DP[node] %= M;
    }
    DP[node]++;
}

void calc(int root = 0, int par = -1){
    ans[root] = (DP[root] - 1 + M) % M;

    int chs = adj[root].size();
    vl preMul(chs + 2, 1), suffMul(chs + 2, 1);
    for (int i = 1; i <= chs; ++i){
        preMul[i] = preMul[i - 1]*DP[adj[root][i - 1]] % M;
    }
    for (int i = chs; i >= 1; --i){
        suffMul[i] = suffMul[i + 1]*DP[adj[root][i - 1]] % M;
    }

    
    for (int i = 1; i <= chs; ++i){
        int newRoot = adj[root][i - 1];
        if(newRoot == par) continue;

        DP[root] = (preMul[i - 1]*suffMul[i + 1] + 1) % M;
        ll newRootOldVal = DP[newRoot];
        DP[newRoot] = ((DP[newRoot] - 1)*DP[root] + 1) % M;

        calc(newRoot, root);

        DP[newRoot] = newRootOldVal;
    }
}

void solve(){
    int n; cin>>n>>M;
    for (int i = 0; i < n - 1; ++i){
        int u, v; cin>>u>>v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(); calc();
    for (int i = 0; i < n; ++i){
        cout<<ans[i]<<el;
    }
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