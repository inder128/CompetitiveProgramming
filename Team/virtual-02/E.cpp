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

// nice question;
// https://codeforces.com/gym/102219/problem/F

const int mod = 1e9 + 7;

void addSelf(int& x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
}

void subSelf(int& x, int y){
    addSelf(x, -y);
}

void multSelf(int& x, int y){
    x = x * 1ll * y % mod;
}


void solve(){
    int n, e, k; cin >> n >> e >> k;

    set <pi> forbidden;
    for(int i = 0; i < k; ++i){
        int u, v; cin >> u >> v;
        forbidden.insert({u, v});
    }

    int MASK = 1 << (2 * e + 1);
    vvi DP(n + 1, vi(1024));
    DP[0][0] = 1;

    for(int i = 1; i <= n; ++i){
        for(int fill = 0; fill < MASK; ++fill){
            // invalid state;
            if(__builtin_popcount(fill) + max(0, i - (e + 1)) != i){
                continue;
            }
            for(int lastFill = i - e, lastFillMsk = 0; lastFill <= min(n, i + e); ++lastFill, ++lastFillMsk){
                // invalid previous state;
                if(lastFill <= 0 or (fill & (1 << lastFillMsk)) == 0){
                    continue;
                }
                // not allowed;
                if(forbidden.count({i, lastFill})){
                    continue;
                }
                // (1 * (i - e - 1 > 0)) -> only when (i - e - 1) exists;
                int lastState = ((fill - (1 << lastFillMsk)) * 2) + (1 * (i - e - 1 > 0));
                addSelf(DP[i][fill], DP[i - 1][lastState]);
            }
        }
    }

    int finalState = 0;
    for(int i = n, j = e; i >= 1 and j >= 0; --i, --j){
        finalState += (1 << j);
    }
    cout << DP[n][finalState] << el;
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