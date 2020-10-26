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

int calc(string s, string f){
    // here all operations will be in pairs;
    int n = s.length() - 1;
    vvi DP(n + 1, vi(2, 1e9));
    // DP[i][0] -> min no. of operations to make s[1--i-1] == f[1---i-1] and s[i] == f[i];
    // DP[i][1] -> min no. of operations to make s[1--i-1] == f[1---i-1] and s[i] != f[i];
    // base case;
    DP[0] = DP[1] = {0, 0};
    // DP[1][s[1] == f[1]] -> tis state will be impossible;
    DP[1][s[1] == f[1]] = 1e9;

    for(int i = 2; i <= n; i++){
        // considering all possiblities;
        if(s[i] != f[i] and s[i - 1] != f[i - 1]){
            mini(DP[i][0], DP[i - 2][0] + 1);
            mini(DP[i][1], DP[i - 1][0]);
        }
        if(s[i] != f[i] and s[i - 1] == f[i - 1]){
            mini(DP[i][0], DP[i - 1][1] + 1);
            mini(DP[i][1], DP[i - 1][0]);
        }
        if(s[i] == f[i] and s[i - 1] != f[i - 1]){
            mini(DP[i][0], DP[i - 1][0]);
            mini(DP[i][1], DP[i - 2][0] + 1);
        }
        if(s[i] == f[i] and s[i - 1] == f[i - 1]){
            mini(DP[i][0], DP[i - 2][0]);
            mini(DP[i][1], DP[i - 1][1] + 1);
        }
    }

    return DP[n][0];
}


void solve(){
    int n, ans = 1e9; cin>>n; 
    string s, f, ss, ff; cin>>s>>f; 

    // considering all four possiblities;
    ss = s, ff = f;
    mini(ans, 0 + calc("$" + ss, "$" + ff));

    ss = s, ff = f;
    ss[0] = s[0] == '0' ? '1' : '0';
    mini(ans, 1 + calc("$" + ss, "$" + ff));

    ss = s, ff = f;
    ss.back() = s.back() == '0' ? '1' : '0';
    mini(ans, 1 + calc("$" + ss, "$" + ff));

    ss = s, ff = f;
    ss[0] = s[0] == '0' ? '1' : '0';
    ss.back() = s.back() == '0' ? '1' : '0';
    mini(ans, 2 + calc("$" + ss, "$" + ff));

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