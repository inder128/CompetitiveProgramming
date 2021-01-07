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

const int N = 19;
int DP[N][1 << N];
bool edges[N][N];


void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--, v--;
        edges[u][v] = edges[v][u] = 1;
    }

    vi cnt(n + 1);

    vi nodes[1 << n];
    for(int msk = 0; msk < (1 << n); ++msk){
        for(int i = 0; i < n; ++i){
            if(msk >> i & 1){
                nodes[msk].pb(i);
            }
        }
    }

    for(int root = 0; root < n; ++root){

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < (1 << n); ++j){
                DP[i][j] = 0;
            }
        }
        DP[root][1 << root] = 1;

        for(int msk = 0; msk < (1 << n); ++msk){
            if((msk >> root & 1) == 0){
                continue;
            }
            for(int lst : nodes[msk]){
                if(lst == root){
                    continue;
                }

                for(int secondLst : nodes[msk]){
                    if(secondLst == lst or edges[lst][secondLst] == 0){
                        continue;
                    }
                    DP[lst][msk] += DP[secondLst][msk - (1 << lst)];
                }

                if(msk - (1 << root) - (1 << lst) and edges[lst][root]){
                    cnt[__builtin_popcount(msk)] += DP[lst][msk];
                }
            }
        }
    }


    int ans = 0;
    for(int i = 3; i <= n; ++i){
        ans += cnt[i] / (2 * i);
    }
    cout << ans << el;
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