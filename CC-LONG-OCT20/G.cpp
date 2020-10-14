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

const int N = 1e5 + 5;
vector <pi> adj[N];
vi change(N);

void dfs(int node = 1, int par = -1){
    for (pi &chPr : adj[node]){
        if(chPr.F == par) continue;
        change[chPr.F] -= chPr.S;
        dfs(chPr.F, node);
    }
}

void solve(){
    int n, m; cin>>n>>m;
    vector <pair <int, pi>> edges(m);
    for(auto &eg : edges){
        cin>>eg.S.F>>eg.S.S>>eg.F;
    }

    sort(rng(edges));

    vi par(n+1), sz(n+1, 1);
    iota(rng(par), 0);
    function <int(int)> getPar = [&](int k) {
        return k == par[k] ? k : par[k] = getPar(par[k]);
    };

    ll wgt = 0;
    for (auto &eg : edges){
        int u = eg.S.F, v = eg.S.S;
        if(u == 1 or v == 1){
            change[u + v - 1] = eg.F;
            continue;
        }
        int pu = getPar(u), pv = getPar(v);
        if(pu == pv) continue;
        adj[u].pb({v, eg.F});
        adj[v].pb({u, eg.F});
        wgt += eg.F;
        if(sz[pu] > sz[pv]) swap(pu, pv);
        par[pu] = pv, sz[pv] += sz[pu];
    }

    auto itr = min_element(change.begin() + 2, change.begin() + n + 1);
    adj[1].pb({itr - change.begin(), 1e9});
    wgt += *itr;
    dfs();

    sort(change.begin() + 2, change.begin() + n + 1);

    cout<<wgt<<" ";
    for (int i = 3; i <= n; ++i){
        wgt += change[i];
        cout<<wgt<<" ";
    }
    cout<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}