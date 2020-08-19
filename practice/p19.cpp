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

void solve(){
    ll n, T, a, b; cin>>n>>T>>a>>b;
    vector <pi> prob(n);
    ll easy = 0, hard = 0;
    for (int i = 0; i < n; ++i){
        cin>>prob[i].S;
        if(prob[i].S) hard++;
        else easy++;
    }
    for (int i = 0; i < n; ++i){
        cin>>prob[i].F;
    }
    sort(rng(prob));

    vector <pl> req; 
    req.pb({0, 0});
    vl time; 
    time.pb(0);
    for (int i = 0; i < n; ++i){
        if(i==0 or prob[i].F != prob[i-1].F) req.pb(req.back()), time.pb(prob[i].F);
        if(prob[i].S) req.back().S++;
        else req.back().F++;
    }
    time.pb(T+1); req.pb({0, 0});

    ll ans = 0;
    for (int i = 1; i < req.size(); ++i){
        if(time[i] - 1 < 0) continue;
        ll minReq = (req[i-1].F)*a + (req[i-1].S)*b;
        if(minReq > time[i] - 1) continue;
        ll rem =  (time[i] - 1) - minReq;
        ll ea = min(easy - req[i-1].F, rem/a);
        rem -= a*ea;
        ll hb = min(hard - req[i-1].S, rem/b);
        ans = max(ans, req[i-1].F + req[i-1].S + ea + hb);
    }
    cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}