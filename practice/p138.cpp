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

// https://codeforces.com/contest/1463/problem/E
// editorial


const int N = 5e5;
vi nxt(N, -1), prv(N, -1), par(N), order, depends[N], rep(N), ans;
vector <char> status(N, 'w');

bool topo(int node){
    status[node] = 'g';

    for(int ch : depends[node]){
        if(status[ch] == 'b'){
            continue;
        }
        if(status[ch] == 'g'){
            return false;
        }
        bool sol = topo(ch);
        if(sol == false){
            return false;
        }
    }

    order.pb(node);
    status[node] = 'b';
    return true;
}

void solve(){
    // input
    int n, k; cin >> n >> k;
    int root;
    iota(rng(rep), 0);
    for(int i = 0; i < n; ++i){
        cin >> par[i];
        par[i]--;
        if(par[i] == -1){
            root = i;
        }
    }

    // links for making component;
    while(k--){
        int u, v; cin >> u >> v;
        u--, v--;
        nxt[u] = v;
        prv[v] = u;
    }

    // compress or find components;
    vvi comps;
    for(int i = 0; i < n; ++i){
        if(rep[i] != i or prv[i] == -1) continue;
        int p = i;
        while(prv[p] != -1){
            p = prv[p];
            if(p == i){
                cout << 0 << el;
                return;
            }
        }
        comps.pb({});
        while(p != -1){
            rep[p] = n + SZ(comps) - 1;
            comps.back().pb(p);
            p = nxt[p];
        }
    }

    // compressed graph;
    for(int i = 0; i < n; ++i){
        if(par[i] == -1) continue;
        int u = rep[i], v = rep[par[i]];
        if(u == v) continue;
        depends[u].pb(v);
    }

    // topological sort;    
    for(int i = 0; i < n + SZ(comps); ++i){
        if(status[rep[i]] == 'b'){
            continue;
        }
        assert(status[rep[i]] == 'w');
        bool sol = topo(rep[i]);
        if(sol == false){
            cout << 0 << el;
            return;
        }
    }

    // decompress;
    map <int, int> ind;
    for(int u : order){
        if(u < n){
            ind[u] = SZ(ans);
            ans.pb(u);
        }
        else{
            for(int v : comps[u - n]){
                ind[v] = SZ(ans);
                ans.pb(v);
            }
        }
    }

    // check;
    for(int i = 0; i < n; ++i){
        if(par[i] == -1) continue;
        if(ind[par[i]] > ind[i]){
            cout << 0 << el;
            return;
        }
    }

    for(int u : ans) cout << u + 1 << " "; cout << el;
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