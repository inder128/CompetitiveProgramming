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


void solve(){
    int n, m; cin >> n >> m;
    vector <vector <bool>> edges(n, vector <bool>(n));
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--, v--;
        edges[u][v] = edges[v][u] = 1;
    }

    vvi DP(1 << n, vi(n));
    int ans = 0;

    for(int msk = 1; msk < (1 << n); ++msk){
        int fs = 0;
        for(int i = 0; i < n; ++i){
            if(msk >> i & 1){
                fs = i;
                break;
            }
        }
        if(msk - (1 << fs) == 0){
            DP[msk][fs] = 1;
            continue;
        }
        for(int lst = 0; lst < n; ++lst){
            if((msk >> lst & 1) == 0 or lst == fs){
                continue;
            }
            for(int secondLst = 0; secondLst < n; ++secondLst){
                if((msk >> secondLst & 1) == 0 or secondLst == lst){
                    continue;
                }
                DP[msk][lst] += DP[msk ^ (1 << lst)][secondLst] * edges[lst][secondLst];
            }
            ans += edges[fs][lst] * DP[msk][lst] * (__builtin_popcount(msk) > 2);
        }
    }

    cout << ans / 2 << el;
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