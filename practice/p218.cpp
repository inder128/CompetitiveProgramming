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
typedef vector<pi> vpi;
 
/*-----------------------------Code Begins--------------------------------*/

vector <pi> get(vector <pi> vals, vector <pi> edges, vector <pi> ans){
	sort(rng(ans));

	int n = SZ(vals), m = SZ(ans);

	map <int, int> ind;
	for(int i = 0; i < m; ++i){
		ind[ans[i].S] = i;
	}

	vi invalids[n];
	for(auto [u, v] : edges){
		u--, v--;
		invalids[u].pb({ind[v]});
	}

	for(int i = 0; i < n; ++i){
		sort(rng(invalids[i]));
		if(SZ(invalids[i]) == m){
			vals[i].F = 1e9;
		}
		else{
			int j;
			for(j = 0; j < SZ(invalids[i]); ++j){
				if(invalids[i][j] == j) continue;
				else break;
			}
			vals[i].F += ans[j].F;
		}
	}

	return vals;
}

void solve(){
    vi n(4); cin >> n;
    vector <pi> vals[4];
    for(int i = 0; i < 4; ++i){
    	for(int j = 0; j < n[i]; ++j){
    		int x; cin >> x;
    		vals[i].pb({x, j});
    	}
    }

    vector <pi> edges[3];
    for(int i = 0; i < 3; ++i){
    	int m; cin >> m;
    	for(int j = 0; j < m; ++j){
    		int u, v; cin >> u >> v;
    		edges[i].pb({u, v});
    	}
    }

    vector <pi> ans = vals[3];
    for(int i = 2; i >= 0; --i){
    	ans = get(vals[i], edges[i], ans);
    }

    sort(rng(ans));
    if(ans[0].F >= 1e9){
    	ans[0].F = -1;
    }

    cout << ans[0].F << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}