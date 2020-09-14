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

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a); 
}

ll solve1(ll n, ll x){
    ll ans = 1;
    for (ll i = 2; i*i <= x; ++i){
        if(x%i) continue;
        while(x%i == 0) x /= i;
        ans *= n - n/i;
    }
    return ans;
}

ll solve2(ll n, ll x){
    ll ans = 0;
    for (ll i = 1; i <= n; ++i){
        if(gcd(x, i) == i) ans++;
    }
    return ans;
}

void solve(){
    ll n, x; cin>>n>>x;
    bool ans = (solve1(n, x)==solve2(n, x));
    db(solve1(n, x), solve2(n, x));
    db(ans);
}

/*
345*(1 - 1/3)*(1 - 1/5)*(1 - 1/23);

69
3 23
*/
 
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