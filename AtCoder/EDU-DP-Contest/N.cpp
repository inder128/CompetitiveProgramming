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

// similar technique is used in kickstart20RoundG/B.cpp

void solve(){
    int n; cin>>n;
    vl arr(n);
    for(ll &i : arr) cin>>i;
    for (int i = 1; i < n; ++i){
        arr[i] += arr[i - 1];
    }

    vector <vl> DP(n, vl(n));
    // DP[l][r] = minimum cost to merge arr[l ---- r] in a single element;
    // DP[l][r] will be formed by some merge of DP[l][m] and DP[m + 1][r] for some m in {l, r - 1};

    for (int ln = 2; ln <= n; ++ln){
        for (int l = 0, r = ln - 1; r < n; ++l, ++r){
            ll tmpCost = LLONG_MAX;
            for (int m = l; m < r; ++m){
                mini(tmpCost, DP[l][m] + DP[m + 1][r]);
            }
            DP[l][r] = tmpCost + arr[r] - (l ? arr[l - 1] : 0);
        }
    }

    cout<<DP[0][n - 1]<<el;
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