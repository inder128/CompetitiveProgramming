#include <bits/stdc++.h>
using namespace std;
 
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}"; }
    #define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...); }
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
/*-----------------------------Code begins----------------------------------*/

ll n2(ll n){
    return (n*(n+1))/2;
}

ll calc(ll n){
    return ((n*(n+1)*(2*n+1))/6 + (n*(n+1))/2)/2;
}

void solve(){
    ll n; cin>>n;
    ll nn = n;
    ll l = 0, r = 1e6, ans = 0;
    while(l <= r){
        ll m = (l+r)/2;
        ll an = calc(m);
        // db(m, an);
        if(an < nn) ans = m, l = m+1;
        else r = m-1;
    }
    nn -= calc(ans);
    // db(ans);
    ll tl = n2(ans);

    l = 0, r = 1e7;
    while(l <= r){
        ll m = (l+r)/2;
        ll an = n2(m);
        if(an < nn) ans = m, l = m+1;
        else r = m-1;
    }
    tl += ans;
    // cout<<n<<" : "<<tl + 1<<el;
    cout<<tl + 1<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T=1000, tc = 1;
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}