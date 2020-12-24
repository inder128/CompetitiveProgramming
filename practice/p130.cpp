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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

const int N = 1e3;
vi adj[N];
vector <bool> del(N);
int alive, lca;

void dfs(int node, int par, vi& path){
	for(int child : adj[node]){
		if(child == par) continue;
		if(del[child]) continue;
		path.pb(node);
		dfs(child, node, path);
		return;
	}
	path.pb(node);
}


void deleteDfs(int node){
	alive--;
	del[node] = true;
	// db(node);
	for(int child : adj[node]){
		if(del[child]) continue;
		if(child == lca) continue;
		deleteDfs(child);
	}
}


void solve(){
    int n; cin>>n;
    alive = n;
    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin>>u>>v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    while(alive > 1){
    	for(int i = 0; i < n; ++i){
    		if(del[i]) continue;
    		int cnt = 0;
    		for(int child : adj[i]){
    			if(del[child]) continue;
    			cnt++;
    		}
    		if(cnt > 1) continue;
    		assert(cnt == 1);
			vi path;
			dfs(i, -1, path);
			assert(SZ(path) >= 2);
			cout<<"? "<<path[0] + 1<<" "<<path.back() + 1<<endl;
			cin>>lca;
			lca--;
			assert(count(rng(path), lca) == 1);
			for(int u : path){
				if(u == lca) continue;
				// check wrong submission;
				if(del[u]) continue;
				deleteDfs(u);
			}
			break;
    	}
    }

    assert(alive == 1);
    // db(alive);

    assert(count(del.begin(), del.begin() + n, false) == 1);

    for(int i = 0; i < n; ++i){
    	if(del[i]) continue;
    	cout<<"! "<<i + 1<<endl;
    }
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