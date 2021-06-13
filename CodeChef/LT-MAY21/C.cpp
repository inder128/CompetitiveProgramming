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

const int N = 1e6;
vi adj[N];
string token;

pi dfs(int node = 0){
	int ans = 0;
	vi lng;
	for(int child : adj[node]){
		auto [ansc, chain] = dfs(child);
		ans += ansc;
		lng.pb(chain);
	}
	if(token[node] == '0'){
		ans += lng;
	}
	sort(rng(lng), greater <int> ());

	if(SZ(lng) == 0){
		lng.pb(0);
	}
	if(token[])

	// db(node, ans, lng);
	return {ans, lng};
}

void solve(){
    int n; cin >> n;
    cin >> token;
    for(int i = 0; i < n; ++i){
    	adj[i].clear();
    }
    for(int i = 1; i <= n - 1; ++i){
    	int p; cin >> p;
    	p--;
    	adj[p].pb(i);
    }
    cout << dfs().F << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}