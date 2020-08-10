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
// tricky DP; 
// https://codeforces.com/contest/1253/problem/E
// two ways;
// see submissions;

void solve(){
    int n, m; cin>>n>>m;
    vector <pi> x(n); 
    for(pi &i : x) cin>>i.F>>i.S;

    vi DP(m + 1, 1000000); DP[0] = 0;
    for (int i = 1; i <= m; ++i){
        for(pi p : x){
            if(p.F - p.S <= i and i <= p.F + p.S){
                DP[i] = DP[i-1];
                DP[i] = min(DP[i], max(0, p.F - p.S - 1));   
            }
            if(p.F + p.S < i){
                int ex = 0;
                if(p.F - (i - p.F) - 1 > 0) 
                    ex = DP[p.F - (i - p.F) - 1];
                DP[i] = min(DP[i], i - (p.F + p.S) + ex);              
                DP[i] = min(DP[i], max(p.F - p.S - 1, i - (p.F + p.S)));        
            }
        }
    }
    cout<<DP[m]<<el;
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