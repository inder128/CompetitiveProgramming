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
    int n, x; cin>>n>>x;
    int xx = x;

    vi fac;
    for (int i = 2; i*i <= x; ++i){
    	if(x % i) continue;
        fac.pb(1);
        while(x % i == 0){
        	x /= i;
        	fac.back() *= i;
        }
    }
    if(x > 1) fac.pb(x);

    
    if(fac.size() <= n){
        int ans = 0;
    	for (int i = 0; i < n; ++i){
    		ans += (i < fac.size() ? fac[i] : 1);
    	}
        cout<<ans<<el;
        return;
    }


    int sz = fac.size();
    vvi DP(n + 1, vi(1<<sz, INT_MAX));
    DP[0][0] = 0;

    for (int i = 1; i <= n; ++i){
        for (int msk = 0; msk < (1<<sz); ++msk){
            for (int msk2 = 0; msk2 < (1<<sz); ++msk2){
                if((~msk)&(msk2)) continue;
                int mul = 1;
                for (int j = 0; j < sz; ++j){
                    if((msk2&(1<<j)) == 0) continue;
                    mul *= fac[j];
                }
                mini(DP[i][msk], DP[i - 1][msk^msk2] + mul);
            }
        }
    }

    cout<<DP[n][(1<<sz) - 1]<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}