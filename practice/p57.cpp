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
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// tricky question
// very nice editorial
// https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_d
const ll mod = 1e9 + 7;

void solve(){
    ll n, a, b; cin>>n>>a>>b;
    if(a + b > n){
        cout<<0<<el;
        return;
    }
    if(a > b){
    	swap(a, b);
    }

    ll sd = min(n - b + 1, a - 1);

    ll ls = ((sd*(sd - 1))/2 + max(0ll, (n - b + 1) - sd)*max(0ll, a - 1)) % mod;;
    // db(sd, ls);

    ll ovp = (2*ls + (((n - b + 1)*(b - a + 1)) % mod)) % mod;

    ll ans =  ((n - a + 1)*(n - a + 1)) % mod;
    ans *= ((n - b + 1)*(n - b + 1)) % mod;
    ans %= mod;
    ans -= (ovp*ovp) % mod;
    cout<<(ans +  mod) % mod<<el;

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