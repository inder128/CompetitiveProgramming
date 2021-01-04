#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
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
    vector <pi> edges(m);
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	edges[i] = {u, v};
    }

    vector <bool> clique(1 << n);
    for(int msk = 0; msk < (1 << n); ++msk){
    	int ec = 0, nc = __builtin_popcount(msk);
    	for(int j = 0; j < m; ++j){
    		if((msk & (1 << edges[j].F)) and (msk & (1 << edges[j].S))){
    			ec++;
    		}
    	}
    	if(ec == nc * (nc - 1) / 2){
    		clique[msk] = true;
    	}
    }

	vi DP(1 << n, 1e9);
	DP[0] = 0;
	for(int msk = 1; msk < (1 << n); ++msk){
		for(int subMsk = msk; subMsk; subMsk = (subMsk - 1) & msk){
			if(clique[subMsk]){
				mini(DP[msk], DP[msk ^ subMsk] + 1);
			}
		}
	}

	cout << DP[(1 << n) - 1] << el;
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