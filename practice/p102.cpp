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

const int N = 2e5;
vector <pi> adj[N];

struct path{
    int u, v;
    ll c;
    bool operator<(const path& opath){
        return c > opath.c;
    }
};

void solve(){
    int n, m, k; cin>>n>>m>>k;

    priority_queue <path, vector <path>, less<>> PQ;

    vector <int> weights;

    for(int i = 0; i < m; ++i){
        int u, v, w; cin>>u>>v>>w;
        u--, v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        PQ.push({u, v, w});
        weights.pb(w);
    }

    
    sort(rng(weights));
    ll mxWt = m >= k ? weights[k - 1] : 1e18;
    
    ll cost;
    set <pi> taken;

    while(k){
        // pop and pushes;
        auto mnPath = PQ.top(); PQ.pop();
        int u = mnPath.u, v = mnPath.v;
        cost = mnPath.c;

        // already considered;
        if(taken.count({min(u, v), max(u, v)})) continue;

        taken.insert({min(u, v), max(u, v)});
        k--;


        for(auto nu : adj[u]){
            // already considered;
            if(taken.count({min(nu.F, v), max(nu.F, v)})) continue;

            // invalid
            if(nu.F == v) continue;
            if(cost + nu.S > mxWt) continue;
            
            PQ.push({nu.F, v, cost + nu.S});
        }
        for(auto nv : adj[v]){
            // already considered;
            if(taken.count({min(u, nv.F), max(u, nv.F)})) continue;
            
            // invalid
            if(u == nv.F) continue;
            if(cost + nv.S > mxWt) continue;
            
            PQ.push({u, nv.F, cost + nv.S});
        }
    }

    cout<<cost<<el;
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