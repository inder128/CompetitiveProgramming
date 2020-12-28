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

void solve(){
    int r, g, b; cin>>r>>g>>b;
    vi ra(r), ga(g), ba(b);
    for(int &i : ra) cin>>i;
    for(int &i : ga) cin>>i;
    for(int &i : ba) cin>>i;
    sort(rng(ra)); reverse(rng(ra));
    sort(rng(ga)); reverse(rng(ga));
    sort(rng(ba)); reverse(rng(ba));

    vector <vvi> DP(r+1, vvi(g+1, vi(b+1, INT_MIN)));
    DP[0][0][0] = 0;
    int mx = 0;
    for (int i = 0; i <= r; ++i){
        for (int j = 0; j <= g; ++j){
            for (int k = 0; k <= b; ++k){
                if(i and j)
                    DP[i][j][k] = max(DP[i-1][j-1][k] + ra[i-1]*ga[j-1], DP[i][j][k]);
                if(j and k)
                    DP[i][j][k] = max(DP[i][j-1][k-1] + ga[j-1]*ba[k-1], DP[i][j][k]);
                if(k and i)
                    DP[i][j][k] = max(DP[i-1][j][k-1] + ra[i-1]*ba[k-1], DP[i][j][k]);
                mx = max(mx, DP[i][j][k]);
            }
        }
    }

    cout<<mx<<el;
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