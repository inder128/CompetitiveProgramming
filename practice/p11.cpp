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
    int n, m, k; cin>>n>>m>>k;
    vi tc(n + 1), ss(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i){
         cin>>tc[i]>>ss[i]>>c[i];
    } 
    vi par(n + 1);
    for (int i = 0; i < m; ++i){
        int p, c; cin>>p>>c;
        par[c] = max(par[c], p);
    }
    vvi ch(n + 1);
    for (int i = 1; i <= n; ++i)
        if(par[i]) ch[par[i]].pb(i);

    int mxK = 5005;
    vvi DP(n + 1, vi(mxK, INT_MIN));
    for (int i = 0; i <= k; ++i) DP[0][i] = 0;

    for (int i = 1; i <= n; ++i){
        //cg[j] = max score obtained if j soldiers stays;
        vi cg;
        for(int child : ch[i])
            cg.pb(c[child]);
        if(par[i] == 0) cg.pb(c[i]);
        sort(rng(cg)); reverse(rng(cg));
        cg.insert(cg.begin(), 0);
        for (int j = 2; j < cg.size(); ++j)
            cg[j] += cg[j-1];

        // DP[i][s] -> max score if s soldiers are taken to attack city i+1;
        // sr -> no. of soldiers stays to defend reachable castles;
        // ta -> no. of soldiers which attacked city i;
        for (int s = 0; s < mxK; ++s){
            if(i < n and s < tc[i+1]) continue;
            for (int sr = 0; sr < cg.size(); ++sr){
                //calcculation ta to satisfy s and sr;
                int ta = s + sr - ss[i];
                //int valid ta's;
                if(ta < tc[i] or ta >= mxK) continue;
                // transition state
                DP[i][s] = max(DP[i][s], DP[i-1][ta] + cg[sr]);
            }
        }
    }

    int mx = *max_element(rng(DP[n]));
    if(mx < 0) mx = -1;
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