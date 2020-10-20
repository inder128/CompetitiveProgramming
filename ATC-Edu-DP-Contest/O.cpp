#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
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

vvi DP(21, vi(1<<21));
const int mod = 1e9 + 7;

void solve(){
    int n; cin>>n;
    bool comp[n][n];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin>>comp[i][j];
        }
    }

    for (int i = 0; i < n; ++i){
        DP[0][1<<i] = comp[0][i];
    }
    for (int i = 1; i < n; ++i){
        for (int j = 0; j < (1<<n); ++j){
            if(__builtin_popcount(j) != i + 1) continue;
            for (int b = 0; b < n; ++b){
                if(!(j&(1<<b))) continue;
                if(!comp[i][b]) continue;
                DP[i][j] += DP[i - 1][j^(1<<b)];
                DP[i][j] %= mod;
            }
        }
    }

    cout<<DP[n - 1][(1<<n) - 1]<<el;
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