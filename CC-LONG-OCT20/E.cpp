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

void solve(){
    srand(time(0)); 
    int n, d; cin>>n>>d;
    vvi nodes(n, vi(d));
    for (int i = 0; i < n; ++i){
        for(auto &ii : nodes[i]) 
            ii = rand()%10;
        db(i, nodes[i]);
    }

    vector <pi> edge(n*n);
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            for (int k = 0; k < d; ++k){
                edge[i*n + j].F += abs(nodes[i][k] - nodes[j][k]);
            }
            edge[i*n + j].S = i*n + j;
        }
    }
    sort(rng(edge));
    reverse(rng(edge));

    vi par(n), sz(n, 1);
    iota(rng(par), 0);
    function <int(int)> getPar = [&](int k) {
        return k == par[k] ? k : par[k] = getPar(par[k]);
    };

    int ans = 0;
    for (int i = 0; i < n*n; ++i){
        int u = edge[i].S/n, v = edge[i].S % n;
        int pu = getPar(u), pv = getPar(v);
        if(pu == pv) continue;
        db(u, v);
        ans += edge[i].F;
        if(sz[pu] > sz[pv]) swap(pu, pv);
        par[pu] = pv, sz[pv] += sz[pu];
    }

    cout<<ans<<el;
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