#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.F << ")"; }
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

const ll mod = 1e9 + 7;
typedef vector <vl> vvl;

ll get(string a, string b){
    int n = a.length(), m = b.length();
    vvl DP(n+1, vl(m+1));
    for (int i = 0; i <= n; ++i) DP[i][0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            DP[i][j] = (DP[i-1][j] + (a[i-1]==b[j-1])*DP[i-1][j-1]) % mod;

    // db(a, b, DP[n][m]);
    return DP[n][m];
}

void solve(){
    string a, b, c; cin>>a>>b>>c;
    int al = a.length(), bl = b.length(), cl = c.length();

    vi ai[26], bi[26];
    for (int i = 0; i < al; ++i) ai[a[i]-'a'].pb(i);
    for (int i = 0; i < bl; ++i) bi[b[i]-'a'].pb(i);

    vector <vvl> DP(al+1, vvl(bl+1, vl(cl+1)));
    vector <vvl> cnt(al+1, vvl(bl+1, vl(cl+1)));
    for (int i = 0; i <= al; ++i)
        for (int j = 0; j <= bl; ++j)
            DP[i][j][0] = 1;

    for (int i = 0; i <= al; ++i){
        for (int j = 0; j <= bl; ++j){
            for (int k = 1; k <= cl; ++k){
                if(i==0 and j==0) continue;
                if(j==0){
                    DP[i][j][k] = DP[i-1][j][k] + (a[i-1]==c[k-1])*DP[i-1][j][k-1];
                }
                else if(i==0){
                    DP[i][j][k] = DP[i][j-1][k] + (b[j-1]==c[k-1])*DP[i][j-1][k-1];
                }
                else{
                    int ch = c[k-1]-'a';
                    // int ii = lower_bound(rng(ai[ch]), i) - ai[ch].begin() - 1;
                    // if(ii != -1) DP[i][j][k] += DP[ai[ch][ii]][j][k-1];
                    // int jj = lower_bound(rng(bi[ch]), j) - bi[ch].begin() - 1;
                    // if(jj != -1) DP[i][j][k] += DP[i][bi[ch][jj]][k-1];
                    // if(ii!=-1 and jj!=-1) DP[i][j][k] += DP[ai[ch][ii]][bi[ch][jj]][k];
                    // db(ii, jj);
                    for(int ii : ai[ch]){
                        if(ii >= i) break;
                        DP[i][j][k] += DP[ii][j][k-1];
                    }
                    for(int jj : bi[ch]){
                        if(jj >= j) break;
                        DP[i][j][k] += DP[i][jj][k-1];
                    }
                }
                DP[i][j][k] %= mod;
            }
        }
    }
    cout<<(DP[al][bl][cl] - get(a, c) - get(b, c) + 2*mod) % mod<<el;
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