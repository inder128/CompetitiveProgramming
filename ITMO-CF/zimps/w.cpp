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

// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/I

class DSU{ 
public: 
    vi size, par, disToPar;
    int n;

    DSU(int n){ 
        this->n = n; 
        size.assign(n, 1);
        par.resize(n);
        disToPar.resize(n);
        iota(rng(par), 0);
    }

    int getPar(int u){
        if(u == par[u]) return u;
        int v = getPar(par[u]);
        disToPar[u] = (disToPar[u] + disToPar[par[u]]) % 2;
        par[u] = v;
        return v;
    }

    bool unite(int u, int v){
        int pu = getPar(u), pv = getPar(v);

        if(pu == pv){
            return disToPar[u] != disToPar[v];
        }

        if(size[pu] > size[pv]) swap(pu, pv);

        size[pv] += size[pu], par[pu] = pv;

        disToPar[pu] = (disToPar[u] == disToPar[v]);

        return true;
    }
};

void solve(){
    int n, m; cin>>n>>m;
    DSU dsu(n);
    vector <pi> edjes(m);
    for (int i = 0; i < m; ++i){
        int u, v; cin>>u>>v;
        u--, v--;
    	edjes[i] = {u, v};
    }
    for (int i = 0; i < m; ++i){
        if(dsu.unite(edjes[i].F, edjes[i].S)){

        }
        else{
            cout<<i + 1<<el;
            return;
        }
    }
    cout<<-1<<el;
    return;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}