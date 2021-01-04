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
    int n, m, k; cin >> n >> m >> k;
    vi cost(k + 1);
    vi a(n); cin >> a;
    
    for(int i = 0; i < m; ++i){
    	int x, y; cin >> x >> y;
    	if(x <= k){
    		maxi(cost[x], y);
    	}
    }

    

    mini(n, k);
    sort(rng(a));
    sort(a.begin(), a.begin() + n, greater<int>());
    for(int i = 1; i < n; ++i){
    	a[i] += a[i - 1];
    }

    
    vi DP(n, 1e18);
    for(int i = 0; i < n; ++i){
    	DP[i] = (i + 1 - cost[i + 1] ? a[i + 1 - cost[i + 1] - 1] : 0);
    	for(int j = 1; j <= i; ++j){
    		int ln = i - j + 1;
    		int cst = (i - cost[ln] >= 0 ? a[i - cost[ln]] : 0) - a[j - 1];
    		mini(DP[i], DP[j - 1] + cst);
    	}
    	db(i, DP[i]);
    }


    cout << DP[n - 1] << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}