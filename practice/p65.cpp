#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define int long long
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/contest/1097/problem/D
// check editorial 
// check tle submission
// DP[i][j] is a multipicative function (proof by induction);
const int mod = 1e9 + 7;

int pow(int x, int y){
    int ans = 1;
    while(y){
        if(y % 2) ans = ans * x % mod;
        y /= 2;
        x = x * x % mod;
    }
    return ans;
}

int inv(int n){
    return pow(n, mod - 2);
}

void solve(){
    int n, k; cin>>n>>k;

    vector <pi> pf;
    for (int i = 2; i*i <= n and n > 1; ++i){
        if(n % i) continue;
        pf.pb({i, 0});
        while(n % i == 0){
            pf.back().S++;
            n /= i;
        }
    }
    if(n > 1) pf.pb({n, 1});

    int ans = 1;

    for(pi &p : pf){
        vvi DP(p.S + 1, vi(k + 1));
        for (int i = 0; i <= k; ++i){
            DP[0][i] = 1;
        }
        for (int i = 1; i <= p.S; ++i){
            DP[i][0] = pow(p.F, i);

            // prefix sum;
            DP[i][0] = (DP[i][0] + DP[i - 1][0]) % mod;
        }

        // prefix sum :-
        // DP[i][j] = actual DP[0][j] + actual DP[1][j] ----- + actual DP[i][j];

        for (int i = 1; i <= p.S; ++i){
            for (int j = 1; j <= k; ++j){
                DP[i][j] = DP[i][j - 1] * inv(i + 1) % mod;

                // prefix sum;
                DP[i][j] = (DP[i][j] + DP[i - 1][j]) % mod;
            }
        }

        ans = (ans * (DP[p.S][k] - (p.S ? DP[p.S - 1][k] : 0) + mod)) % mod;
    }

    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}