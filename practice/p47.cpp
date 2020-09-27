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
typedef long long ll; typedef pair<int,int> pi; 
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// Good question 
// https://codeforces.com/problemset/problem/1312/E

const int N = 505;
vvi DP(N, vi(N, -1));
vi arr(N);

int calc(int l, int r){
    if(DP[l][r] != -1) return DP[l][r];
    if(l == r) return DP[l][r] = arr[l];
    DP[l][r] = 0;
    for (int i = l; i < r; ++i){
        int lCalc = calc(l, i), rCalc = calc(i+1, r);
        if(lCalc and rCalc and lCalc == rCalc)
            return DP[l][r] = lCalc + 1;
    }
    return DP[l][r];
}

void solve(){
    int n; cin>>n;
    for (int i = 1; i <= n; ++i){
        cin>>arr[i];
    }
    vi dp(n+1, 1e9);
    dp[0] = 0;

    for (int r = 1; r <= n; ++r){
        for (int l = 1; l <= r; ++l){
            if(calc(l, r))
                dp[r] = min(dp[r], 1 + dp[l-1]);
        }
    }

    cout<<dp[n]<<el;
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