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
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}";}
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

/*

leftest element which is (>= e and <= e + k);

(
1 5 4 3 8 6 9 7 2 4
1 1 2 3 1 4 5 6 4 7
)
.
*/

void solve(){
    int n, k; cin>>n>>k;
    vi a(n); for(int &i : a) cin>>i;
    vi eui(n, -1), eli(n, -1);
    set <pi> up, lw;
    for (int i = 0; i < n; ++i){
        auto itr = up.lower_bound({a[i], -1});
        for (; itr != up.end() ; itr = up.upper_bound(*itr)){
            if(itr->F > a[i] + k) break;
            eli[itr->S] = i;
            up.erase(*itr);
        }
        itr = lw.lower_bound({a[i] - k, -1});
        for (; itr != lw.end() ; itr = lw.upper_bound(*itr)){
            if(itr->F > a[i]) break;
            eui[itr->S] = i;
            lw.erase(*itr);
        }
        up.insert({a[i], i}), lw.insert({a[i], i});
    }

    vi dp(n, 1);
    for (int i = n-1; i >= 0; --i){
        if(eui[i] != -1)
            dp[i] = max(dp[i], dp[eui[i]] + 1);
        if(eli[i] != -1)
            dp[i] = max(dp[i], dp[eli[i]] + 1);
    }
    cout<<(*max_element(rng(dp)))<<el;
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