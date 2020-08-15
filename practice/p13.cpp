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

const int mod = 1e9 + 7;

void solve(){
    string s1, s2, r; 
    cin>>s1>>s2>>r;
    s1 = "$" + s1;
    s2 = "$" + s2;
    r = "$" + r;
    int n = s1.length();
    int m = s2.length();
    int o = r.length();

    vi ps1[26], ps2[26];
    for (int i = 1; i < n; ++i)
        ps1[s1[i] - 'a'].pb(i);
    for (int i = 1; i < m; ++i)
        ps2[s2[i] - 'a'].pb(i);

    vvi DP(n, vi(m, 1));
    for (int k = 1; k < o; ++k){
        vvi nDP(n, vi(m));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                for(int p1 : ps1[r[k] - 'a']){
                    if(p1 > i) break;
                    nDP[i][j] += DP[p1-1][j];
                    nDP[i][j] %= mod;  
                }
                for(int p2 : ps2[r[k] - 'a']){
                    if(p2 > j) break;
                    nDP[i][j] += DP[i][p2-1];
                    nDP[i][j] %= mod; 
                }
            }
        }
        DP = nDP;
    }
    int bc = DP[n-1][m-1];

    

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