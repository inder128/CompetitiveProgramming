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

// nice question; 
const int N = 1e5, mod = 1e9 + 7;
vl ways(N + 1), factors[N + 1];

void solve(){
    ll k, q; cin>>k>>q;

    vector <vl> DP(N + 1, vl(2));
    // DP[i][0] -> no of ways to arrange k symbols at n places such that no adjecent symbols are same and first and last symbols are different;
    // DP[i][1] -> no of ways to arrange k symbols at n places such that no adjecent symbols are same and first and last symbols are same;
    // Base case;
    DP[2] = {k*(k - 1) % mod, 0};
    for(int i = 3; i <= N; i++){
        DP[i][0] += DP[i - 1][0]*(k - 2) % mod;
        DP[i][0] += DP[i - 1][1]*(k - 1) % mod;
        DP[i][0] %= mod;
        DP[i][1] = DP[i - 1][0];
    }

    for(int i = 2; i <= N; i++){
        ways[i] = (ways[i] + DP[i][0]) % mod;
        for(int j = 2*i; j <= N; j += i){
            ways[j] = (ways[j] - ways[i] + mod) % mod;
            factors[j].pb(i);
        }
    }

    while(q--){
        int n; cin>>n;
        ll ans = 0;
        for(ll fac : factors[n]){
            ans = (ans + ways[fac]) % mod;
        }
        cout<<ans<<el;
    }
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