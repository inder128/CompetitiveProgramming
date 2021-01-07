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
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

void solve(){
    int n, m; cin >> n >> m;
    vi k(n + 1);
    for(int i = 1; i <= n; ++i){
    	cin >> k[i];	
    }
    sort(rng(k));
    vi c(m + 1);
    for(int i = 1; i <= m; ++i){
    	cin >> c[i];
    }
    vi kk(n + 1);
    for(int i = 1; i <= n; ++i){
    	kk[i] = c[k[i]];
    	kk[i] += kk[i - 1];
    }
    for(int i = 1; i <= m; ++i){
    	c[i] += c[i - 1];
    }


    for(int i = 1; i <= n; ++i){
    	k[i] -= i;
    }
    for(int i = n - 1; i >= 0; --i){
    	mini(k[i], k[i + 1]);
    }

    int ans = 1e18;
    // i i products are sold;
    for(int i = 0; i <= min(n, m); ++i){
    	if(i and k[n - i + 1] + n - i < 0){
    		continue;
    	}
    	mini(ans, c[i] + kk[n - i]);
    }

    cout << ans << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}