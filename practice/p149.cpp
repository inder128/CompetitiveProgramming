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


const int N = 1e5;
set <pi> egs[N];
vector <pi> adj[N];
vector <bool> vis(N);
vector <double> ans(N);
double eps = 1e-6;
vi nodes;

void dfs(int node){
	nodes.pb(node);
	pi par = *egs[node].begin();
	for(pi cw : adj[node]){
		if(SZ(egs[cw.F])){
			egs[cw.F].insert({-par.F, cw.S - par.S});
			continue;
		}
		egs[cw.F].insert({-par.F, cw.S - par.S});
		dfs(cw.F);
	}
}


bool dfsa(int node){
	vis[node] = true;
	for(pi cw : adj[node]){
		if(vis[cw.F]){
			if(abs(ans[cw.F] + ans[node] - cw.S) >= eps){
				return false;
			}
		}
		else{
			ans[cw.F] = cw.S - ans[node];
			if(dfsa(cw.F) == false){
				return false;
			}
		}
	}
	return true;
}


void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
    	int u, v, w; cin >> u >> v >> w;
    	u--, v--;
    	adj[u].pb({v, w});
    	adj[v].pb({u, w});
    }

    for(int node = 0; node < n; ++node){
    	if(SZ(egs[node])){
    		continue;
    	}
    	nodes.clear();

    	egs[node].insert({1, 0});
	    dfs(node);

	    vi vals;
	    bool done = false;
	    for(int i : nodes){
	    	if(SZ(egs[i]) == 1){
	    		pi p = *egs[i].begin();
	    		vals.pb(-1 * p.F * p.S);
	    	}
	    	else{
	    		vi nums[3];
	    		for(pi p : egs[i]){
	    			nums[p.F + 1].pb(p.S);
	    		}
	    		if(SZ(nums[0]) > 1 or SZ(nums[2]) > 1){
	    			cout << "NO" << el;
	    			return;
	    		}
	    		ans[node] = (nums[0][0] - nums[2][0]) / 2.0;
	    		bool sol = dfsa(node);
	    		if(sol == false){
	    			cout << "NO" << el;
	    			return;
	    		}
	    		done = true;
	    		break;
	    	}
	    }
	    if(done){
	    	continue;
	    }

	    sort(rng(vals));
	    int x = vals[SZ(vals) / 2];
	    for(int i : nodes){
	    	pi p = *egs[i].begin();
	    	ans[i] = p.F * x + p.S;
	    }
    }


    cout << "YES" << el;
	for(int i = 0; i < n; ++i){
	   	cout << ans[i] << " ";
	}
	cout << el;   
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