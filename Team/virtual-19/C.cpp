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

const int N = 1e3;
const int M = 8 * 9 * 5 * 7;
const int INF = 1e11;

vvi ans(N, vi(M, -1));
vvi adj(N, vi(10));

vvi vis(N, vi(M));

vi k(N), m(N);

vector <pi> cyc;


pi dfs(int i, int rem){
	rem = (rem + k[i] + INF * M) % M;
	if(ans[i][rem] != -1){
		return {-1, ans[i][rem]};
	}
	if(vis[i][rem]){
		return {i, rem};
	}
	else{
		vis[i][rem] = true;
		auto ret = dfs(adj[i][rem % m[i]], rem);
		if(ret.F != -1){
			cyc.pb({i, rem});
		}
		if(ret == pi(i, rem)){
			set <int> nodes;
    		for(auto [node, rem] : cyc){
    			nodes.insert(node);
    		}
    		for(auto [node, rem] : cyc){
    			ans[node][rem] = SZ(nodes);
    		}
    		cyc = {};
			return {-1, ans[i][rem]};
		}
		else{
			ans[i][rem] = ret.S;
			return ret;
		}
	}
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
    	cin >> k[i];
    }
    for(int i = 0; i < n; ++i){
    	cin >> m[i];
    	for(int j = 0; j < m[i]; ++j){
    		cin >> adj[i][j];
    		adj[i][j]--;
    	}
    }

    int q; cin >> q;
    while(q--){
    	int i, c; cin >> i >> c;
    	i--;
    	cout << dfs(i, c).S << el;
    }
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