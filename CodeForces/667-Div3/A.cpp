#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
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

const int N = 202;
vector <vvi> DP(N, vvi(N, vi(N, -1e9)));

void solve(){
    int n, k; cin>>n>>k;
    string str, t; cin>>str>>t;
    char s = t[0], d = t[1];
    DP[0][0][0] = 0;
    for (int ln = 0; ln < n; ++ln){
        for (int ch = 0; ch <= k; ++ch){
            for (int sc = 0; sc <= n; ++sc){
                if(DP[ln][ch][sc] == -1e9) continue;
                // db(ln, ch, sc, DP[ln][ch][sc]);
                // change str[ln] to s;
                maxi(DP[ln+1][ch + (str[ln]!=s)][sc + 1], DP[ln][ch][sc]);

                // change str[ln] to d;
                maxi(DP[ln+1][ch + (str[ln]!=d)][sc + (d==s)], DP[ln][ch][sc] + sc);

                // do nothing;
                maxi(DP[ln+1][ch][sc], DP[ln][ch][sc]);
            }
        }
    }

    int ans = 0;
    for (int ch = 0; ch <= k; ++ch){
        for (int sc = 0; sc <= n; ++sc){
            maxi(ans, DP[n][ch][sc]);
        }
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