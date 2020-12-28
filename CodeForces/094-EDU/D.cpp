#include <bits/stdc++.h>
using namespace std;
 
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
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
 
/*-----------------------------Code begins----------------------------------*/

void solve(){
    int n; cin>>n;
    map <int, vi> M;
    vi a(n); for(int &i : a) cin>>i;

    vi sa = a;
    sort(rng(sa));
    sa.resize(unique(rng(sa)) - sa.begin());

    int sn = sa.size();
    ll ans = 0;
    vvi DP(n, vi(sn));
    for (int i = 0; i < a.size(); ++i){
        int x = a[i], lx = -1;
        vi cnt(sn);
        for (int j = 0; j < i; ++j){
            int y = a[j];
            int yi = lower_bound(rng(sa), y) - sa.begin();
            cnt[yi]++;
            if(lx != -1) ans += DP[lx][yi];
            if(y == x) lx = j;
        }
        for (int y : sa){
            int j = lower_bound(rng(sa), y) - sa.begin();
            DP[i][j] = cnt[j] + (lx>=0 ? DP[lx][j] : 0);
        }
    }

    cout<<ans<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}