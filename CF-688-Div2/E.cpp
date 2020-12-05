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
vi adj[N], level(N);

void dfs(int node = 0, int par = -1){
	for(int child : adj[node]){
		if(child == par) continue;
		level[child] = level[node] + 1;
		dfs(child, node);
	}
}

int k;


int dp(int node = 0, int par = -1){
	int mn = 1e9;
	bool occ = false;
	int lvl = 0;

	for(int child : adj[node]){
		if(child == par) continue;
		
		int ans = dp(child, node);
		if(ans == 1e9) return ans;

		if(ans - level[node] > k) return 1e9;

		if(ans - level[node] == k and occ) return 1e9;

		if(ans - level[node] == k and occ == false){
			lvl = ans;
			occ = true;
		}
		else{
			mini(mn, ans);
		}
	}

	if(occ) return lvl;

	if(mn == 1e9) return level[node];
	

	return mn;
}


void solve(){
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
    	adj[i].clear();
    }
    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin>>u>>v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs();

    int l = 0, r = 2e5 + 3; 
    while(l + 1 < r){
    	k = (l + r) >> 1;
    	if(dp() <= k){
    		r = k;
    	}
    	else{
    		l = k;
    	}
    }

    cout<<r<<el;
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