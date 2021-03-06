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

// https://codeforces.com/contest/1433/problem/F
// reminder DP;
// k is small -> hint in limits;

void solve(){
    int n, m, k; cin>>n>>m>>k;
    vvi mat(n, vi(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin>>mat[i][j];
        }
    }

    vvi valid(n, vi(k, -1));
    for (int i = 0; i < n; ++i){
        vi DP(70*m + 1, 1e9);
        DP[0] = 0;
        for (int j = 0; j < m; ++j){
            for (int sm = 70*m; sm >= mat[i][j]; --sm){
                mini(DP[sm], DP[sm - mat[i][j]] + 1); 
            } 
        }
        for (int sm = 70*m; sm >= 0; --sm){
            if(DP[sm] <= m / 2 and valid[i][sm % k] == -1){
                valid[i][sm % k] = sm
            }
        }
    }

    vi DP(k, -1);
    DP[0] = 0;
    for (int i = 0; i < n; ++i){
        vi newDP = DP;
        for(int val : valid[i]){
            if(val == -1) continue;
            for (int rem = 0; rem < k; ++rem){
                if(DP[rem] == -1) continue;
                if(newDP[(rem + val) % k] < DP[rem] + val){
                    newDP[(rem + val) % k] = DP[rem] + val;
                }
            }
        }
        DP = newDP;
    }

    cout<<DP[0]<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}