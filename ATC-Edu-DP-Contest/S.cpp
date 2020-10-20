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


// nice problem;
const int mod = 1e9 + 7;

void solve(){
    string str; cin>>str;
    int d, n = str.length(); cin>>d;
    str = "$" + str;

    vi pre(n + 1);
    for (int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1] + (str[i] - '0');
    }

    vvi DP(n + 1, vi(d));
    // DP[i][j] -> no of ways to make sumDig(str[1---i])%d = j and digit < k;

    for (int i = 0; i < n; ++i){
        for (int dg = 0; dg < str[i + 1] - '0'; ++dg){
            DP[i + 1][(pre[i] + dg) % d]++;
            DP[i + 1][(pre[i] + dg) % d] %= mod;
        }
        for (int pd = 0; pd < d; ++pd){
            for (int dg = 0; dg < 10; ++dg){
                DP[i + 1][(pd + dg) % d] += DP[i][pd];
                DP[i + 1][(pd + dg) % d] %= mod;
            }
        }
    }

    // -1 for removing 0;
    // (pre[n]%d == 0) for adding str if sumdigs of str is divisible by d; 
    cout<<(DP[n][0] - 1 + (pre[n]%d == 0) + mod) % mod<<el;
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