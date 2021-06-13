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
    int n; cin >> n;
    vi a(n); cin >> a;
    for(int i = 0; i < n; ++i){
        a[i]--;
    }

    int m = 18;
    vvi DPinv(m, vi(1 << m));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            if(i == j){
                continue;
            }
            int cj = 0;
            for(int k = 0; k < n; ++k){
                if(a[k] == j){
                    cj++;
                }
                if(a[k] == i){
                    DPinv[i][1 << j] += cj;
                }
            }
        }
    }
    for(int i = 0; i < m; ++i){
        for(int mask = 1; mask < (1 << m); ++mask){
            if(mask >> i & 1){
                continue;
            }
            int j = ffs(mask) - 1;
            DPinv[i][mask] = DPinv[i][mask - (1 << j)] + DPinv[i][1 << j];
        }
    }

    int fullMask = (1 << m) - 1;
    vi DP(1 << m);
    for(int mask = 1; mask < (1 << m); ++mask){
        DP[mask] = 1e14;
        for(int lst = 0; lst < m; ++lst){
            if((mask >> lst & 1) == 0){
                continue;
            }
            mini(DP[mask], DP[mask - (1 << lst)] + DPinv[lst][fullMask ^ mask]);
        }
    }

    cout << DP[fullMask] << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}