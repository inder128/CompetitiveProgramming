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
    int n, p, k; cin >> n >> p >> k;
    vvi S(n, vi(p + 1));
    for(int i = 0; i < n; ++i){
    	cin >> S[i][p];
    }
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < p; ++j){
    		cin >> S[i][j];
    	}
    }

    sort(rng(S), [&](const vi& v1, const vi& v2){
    	return v1[p] > v2[p];
    });
    S.insert(S.begin(), vi(p + 1));


    vvi DP(n + 1, vi(1 << p, -1e18));
    DP[0][0] = 0;
    for(int i = 1; i <= n; ++i){
    	for(int msk = 0; msk < (1 << p); ++msk){
    		if(i - __builtin_popcount(msk) <= k){ // can go in audience;
    			DP[i][msk] = DP[i - 1][msk] + S[i][p];
    		}

    		maxi(DP[i][msk], DP[i - 1][msk]);
    		for(int pos = 0; pos < p; ++pos){
    			// invalid last state;
				if((msk & (1 << pos)) == 0){
					continue;
				}
				maxi(DP[i][msk], DP[i - 1][msk - (1 << pos)] + S[i][pos]);
			}
		}
    }

    cout << DP[n][(1 << p) - 1] << el;
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