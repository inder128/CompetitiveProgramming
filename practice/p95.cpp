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

const int N = 2e5;
vi adj[N], vis(N), cyc(N);

int dfs(int node = 0, int par = -1){
	vis[node] = 1;
	for(int ch : adj[node]){
		if(ch == par) continue;
		if(vis[ch]){
			cyc[node] = true;
			return ch;
		}
		int res = dfs(ch, node);
		if(res == node){
			cyc[node] = true;
			return -1;
		}
		if(res != -1){
			cyc[node] = true;
			return res;
		}
	}
	return -1;
}

int dfs2(int node, int par = -1){
	int ans = 1;
	for(int ch : adj[node]){
		if(ch == par) continue;
		if(cyc[ch]) continue;
		ans += dfs2(ch, node);
	}
	return ans;
}

void solve(){
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
    	cyc[i] = vis[i] = 0;
    	adj[i].clear();
    }
    for(int i = 0; i < n; ++i){
    	int u, v; cin>>u>>v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs();

    vi cmpSizes;
    for(int i = 0; i < n; ++i){
    	if(cyc[i] == false) continue;
    	cmpSizes.pb(dfs2(i));
    }


    int tot = accumulate(rng(cmpSizes), 0ll);
    int ans = 0;
    for(int cs : cmpSizes){
    	ans += cs * (cs - 1) / 2;
    	ans += cs * (tot - cs);
    }

    cout<<ans<<el;
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