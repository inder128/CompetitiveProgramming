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

// Codeforces Question Link :-
// https://codeforces.com/problemset/problem/1288/D
// Binary Search method in Editorials;
// Use Binary Search in minimization or maximisation problems;

// O(n*m*2^m);
// Time Limit -> 5 seconds;
// 3*10^5*2^11
// 300000*2048
// 600000000 
// 6*10^8 -> O(6*10^8) Max;

void solve(){
    int n, m; cin>>n>>m;
    vvi mat(n, vi(m));
    for(vi &v : mat) for(int &i : v) cin>>i;
    int st = 1<<m;
    vector <pi> maxMinSetPrefix(st, {INT_MIN, -1});
    maxMinSetPrefix[0].F = INT_MAX;
    int ans = -1, ii, jj;
    for(int j = 0; j < n; j++){
        for(int mask = 0; mask < st; mask++){
            int mnV = INT_MAX;
            for(int i = 1; i < m; i++){
                if((mask&(1<<i)))
                    mnV = min(mnV, mat[j][i]);
            }
            if(min(mnV, maxMinSetPrefix[mask^(st-1)].F) > ans){
                ans = min(mnV, maxMinSetPrefix[mask^(st-1)].F);
                ii = j, jj = maxMinSetPrefix[mask^(st-1)].S;
            }
            if(mnV > maxMinSetPrefix[mask].F){
                maxMinSetPrefix[mask] = {mnV, j};
            }
        }
    }
    if(ii==-1) ii = jj;
    if(jj==-1) jj = ii;
    cout<<jj+1<<" "<<ii+1<<el;
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