#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
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
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
/*-----------------------------Code begins----------------------------------*/

// codeforces question link : -
// https://codeforces.com/contest/1254/problem/B2

void solve(){
    int n; cin>>n;  
    vl a(n); 
    for (int i = 0; i < n; ++i){
        cin>>a[i];
        if(i) a[i] += a[i-1];
    }
    
    ll sm = a[n-1];
    if(sm == 1){
        cout<<"-1\n";
        return;
    }
    vl divs;
    for (ll d = 2; d*d <= sm; ++d){
        if(sm%d) continue;
        divs.pb(d);
        while(sm%d == 0){
            sm /= d;
        }
    }
    if(sm != 1) divs.pb(sm);


    ll ans = LLONG_MAX;
    for(ll d : divs){
        ll ta = 0;
        for (int i = 0; i < n-1; ++i){
            ta += min(a[i]%d, d - a[i]%d);
        }
        ans = min(ans, ta);
    }

    cout<<ans<<el;
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