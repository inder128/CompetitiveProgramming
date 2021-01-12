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
    vector <array <int, 5>> segs;
    vi op[n + 1], cl[n + 1], ccl[n + 1];
    for(int i = 0; i < k; ++i){
    	int s, t, d, w; cin >> s >> t >> d >> w;
    	segs.pb({w, d, s, t, i});
    	op[s].pb(i);
    	cl[t].pb(i);
    	ccl[d].pb(i);
    }

    vector <bool> safe(n + 1);
    vi valids[k];
    set <array <int, 5>, greater <>> currsegs;
    for(int i = 1; i <= n; ++i){

    	for(auto si : op[i]){
    		currsegs.insert(segs[si]);
    	}

    	if(SZ(currsegs)){
    		valids[(*currsegs.begin())[4]].pb(i);
    	}
    	else{
    		safe[i] = true;
    	}

    	for(auto si : cl[i]){
    		currsegs.erase(segs[si]);
    	}
    }

    vvi DP(n + 1, vi(m + 1, 1e18));
    DP[0] = vi(m + 1, 0);
    for(int i = 1; i <= n; ++i){
    	for(int j = 0; j <= m; ++j){
    		if(safe[i]){
    			mini(DP[i][j], DP[i - 1][j]);
    		}
    		for(int si : ccl[i]){
    			for(int li : valids[si]){
    				mini(DP[i][j], DP[li - 1][j] + segs[si][0]);
    			}
    		}
    		if(j){
    			mini(DP[i][j], DP[i - 1][j - 1]);
    		}
    	}
    }

    cout << *min_element(rng(DP[n])) << el;
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