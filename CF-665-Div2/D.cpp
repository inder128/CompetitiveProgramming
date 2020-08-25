#include <bits/stdc++.h>
using namespace std;
 
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}"; }
    #define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...); }
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
/*-----------------------------Code begins----------------------------------*/

const int N = 1e5;
vi adj[N];
vl egw;
int n, mod = 1e9 + 7;

int dfs(int node = 0, int par = -1){
    int nCh = 1;
    for(int child : adj[node]){
        if(child == par) continue;
        int tCh = dfs(child, node);
        egw.pb(tCh*1ll*(n-tCh));
        nCh += tCh;
    }
    return nCh;
}

void solve(){
    cin>>n;
    egw.clear();
    for (int i = 0; i < n; ++i){
        adj[i].clear();
    }
    for (int i = 0; i < n-1; ++i){
        int u, v; cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    int m; cin>>m;
    vl fac(m); for(ll &i : fac) cin>>i;
    while(fac.size() < n-1) fac.pb(1);
    sort(rng(fac));
    while(fac.size() > n-1){
        int bck = fac.back(); fac.pop_back();
        fac.back() *= bck;
        fac.back() %= mod;
    }
    sort(rng(egw));
    ll ans = 0;
    for (int i = 0; i < n-1; ++i){
        ans += egw[i]*fac[i];
        ans %= mod;
    }
    cout<<ans<<el; 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}