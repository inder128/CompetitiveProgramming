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
#define mini(x, y) x = min(x, y)
#define maxi(x, y) x = max(x, y)
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


void solve(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size(); 

    vector <vvi> DP(n+1, vvi(m+1, vi(10, INT_MAX)));
    DP[0][0][0] = 0;
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            for (int bal = 0; bal < 10; ++bal){
                // this state is unreachable;
                if(DP[i][j][bal] == INT_MAX) continue;

                // if nxt char added is '(';
                int nxti = i, nxtj = j;
                if(i<n and s1[i]=='(') nxti++;
                if(j<m and s2[j]=='(') nxtj++;
                mini(DP[nxti][nxtj][bal+1], DP[i][j][bal] + 1);

                if(DP[i][j][bal] < INT_MAX)
                    db(i, j, bal, DP[i][j][bal]);
                
                // can't add ')' if bal is zero;
                if(bal == 0) continue;
                // if nxt char added is ')';
                nxti = i, nxtj = j;
                if(i<n and s1[i]==')') nxti++;
                if(j<m and s2[j]==')') nxtj++;
                mini(DP[nxti][nxtj][bal-1], DP[i][j][bal] + 1);

                
            }
        }
    }

    cout<<DP[n][m][0]<<el;
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


// #include <bits/stdc++.h>

// using namespace std;

// const int N = 202;
// const int INF = 1e9;

// int dp[N][N][2 * N];
// pair<pair<int, int>, pair<int, char>> p[N][N][2 * N];

// int main() {  
//     string s, t;
//     int n = s.size(), m = t.size();
    
//     dp[0][0][0] = 0;
//     for (int i = 0; i <= n; ++i) {
//         for (int j = 0; j <= m; ++j) {
//             for (int bal = 0; bal < 2 * N; ++bal) {
//                 if (dp[i][j][bal] == INF) continue;
                
//                 int nxti = i + (i < n && s[i] == '(');
//                 int nxtj = j + (j < m && t[j] == '(');
//                 if(dp[nxti][nxtj][bal + 1] > dp[i][j][bal] + 1) {
//                     dp[nxti][nxtj][bal + 1] = dp[i][j][bal] + 1;
//                     p[nxti][nxtj][bal + 1] = {{i, j}, {bal, '('}};
//                 }
                
//                 nxti = i + (i < n && s[i] == ')');
//                 nxtj = j + (j < m && t[j] == ')');
//                 if (bal > 0 && dp[nxti][nxtj][bal - 1] > dp[i][j][bal] + 1) {
//                     dp[nxti][nxtj][bal - 1] = dp[i][j][bal] + 1;
//                     p[nxti][nxtj][bal - 1] = {{i, j}, {bal, ')'}};
//                 }
//             }
//         }
//     }
    
//     int ci = n, cj = m, cbal = 0;
//     for (int bal = 0; bal < 2 * N; ++bal) {
//         if (dp[n][m][bal] + bal < dp[n][m][cbal] + cbal) {
//             cbal = bal;
//         }
//     }
//     string res = string(cbal, ')');
//     while (ci > 0 || cj > 0 || cbal != 0) {
//         int nci = p[ci][cj][cbal].first.first;
//         int ncj = p[ci][cj][cbal].first.second;
//         int ncbal = p[ci][cj][cbal].second.first;
//         res += p[ci][cj][cbal].second.second;
//         ci = nci;
//         cj = ncj;
//         cbal = ncbal;
//     }
//     reverse(res.begin(), res.end());
//     cout << res << endl;
    
//     return 0;
// }