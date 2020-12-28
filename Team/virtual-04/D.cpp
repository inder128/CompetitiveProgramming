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


#define cnt first
#define seglenbyksum second

const int N = 2e5;
int n, k;
vi adj[N];
vector <vector <pi>> DP(N, vector <pi>(5));
int ans = 0;


void add(vector <pi>& par, vector <pi>& child){
	for(int j = 0; j < k; ++j){
		int i = (j + 1) % k;
		par[i].cnt += child[j].cnt;
		par[i].seglenbyksum += child[j].seglenbyksum + (j == k - 1 ? child[j].cnt : 0);
	}
}


int compute(vector <pi>& par, vector <pi>& child){
	int ans = 0;
	for(int i = 0; i < k; ++i){
		for(int j = 0; j < k; ++j){
			int ci = par[i].cnt, cj = child[j].cnt;
			ans += ((i + j + 1 + k - 1) / k * (ci * cj)) + child[j].seglenbyksum * ci + par[i].seglenbyksum * cj;
		}
	}
	return ans;
}


void dfs(int node = 0, int par = -1){
	DP[node][0].cnt = 1;

	for(int child : adj[node]){
		if(child == par){
			continue;
		}
		dfs(child, node);

		ans += compute(DP[node], DP[child]);

		// add to DP[cnt];
		add(DP[node], DP[child]);
	}
}


void solve(){
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs();
    cout << ans << el;
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