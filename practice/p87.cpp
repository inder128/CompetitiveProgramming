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

void solve(){
    vi a(6); cin>>a;
    int n; cin>>n;
    vector <pi> pnts;
    for (int i = 0; i < n; ++i){
        int x; cin>>x;
        for (int j = 0; j < 6; ++j){
            pnts.pb({x - a[j], i});
        }
    }
    if(n == 1){
        cout<<0<<el;
        return;
    }
    sort(rng(pnts));
    int count = 1, l = 0;
    vi cnt(n);
    cnt[pnts[0].S] = 1;
    int ans = LLONG_MAX;
    for (int i = 1; i < 6*n; ++i){
        cnt[pnts[i].S]++;
        if(cnt[pnts[i].S] == 1) count++;
        while(cnt[pnts[l].S] > 1){
           cnt[pnts[l].S]--; 
           l++;
        }
        if(count == n){
            mini(ans, pnts[i].F - pnts[l].F);
        }
    }
    cout<<ans<<el;
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