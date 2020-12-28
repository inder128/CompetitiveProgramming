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
    int n, m; cin>>n>>m;
    string s, t; cin>>s>>t;
    s = "$" + s;
    t = "$" + t;

    vvi lasts(n + 1, vi(26));
    for (int i = 2; i <= n; ++i){
    	lasts[i] = lasts[i - 1];
    	lasts[i][s[i - 1] - 'a'] = i - 1;
    }

    vvi lastt(m + 1, vi(26));
    for (int i = 2; i <= m; ++i){
    	lastt[i] = lastt[i - 1];
    	lastt[i][t[i - 1] - 'a'] = i - 1;
    }

    vvi DP(n + 1, vi(m + 1));
    int ans = 0;

    for (int i = 1; i <= n; ++i){
    	for (int j = 1; j <= m; ++j){
    		if(s[i] != t[j]) continue;
    		DP[i][j] = 2;
    		for (int k = 0; k < 26; ++k){
    			int li = lasts[i][k];
    			int lj = lastt[j][k];
    			if(li == 0 or lj == 0) continue;
    			int cost = 4 - (i - li) - (j - lj);
    			// cost = 4 - i - j + DP[li][lj] + li + lj;
    			maxi(DP[i][j], DP[li][lj] + cost);
    		}
    		maxi(ans, DP[i][j]);
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