#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector<bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

const int N = 5000;
vb vis(N);
vector <pi> adj[N];
vi wgt(N);

void dfs(int node){
	vis[node] = true;
	for(pi childPr : adj[node]){
		if(!vis[childPr.F]) 
			dfs(childPr.F);
	}
}

int getMinWt(int u, int v, int par = -1){
	for(pi childPr : adj[u]){
		if(childPr.F == par) continue;
		else if(childPr.F == v) return wgt[childPr.S];
		int wt = getMinWt(childPr.F, v, u);
		if(wt >= 0) return min(wt, wgt[childPr.S]);
	}
	return -1;
}

void solve(){
	int n; cin>>n;
	vector <pi> egs(n-1);
	for (int i = 0; i < n-1; ++i){
		int x, y; cin>>x>>y;
		x--; y--;
		egs[i] = {x, y};
		adj[x].pb({y, i});
		adj[y].pb({x, i});
	}

	int m; cin>>m; 
	vector <pair<pi, int>> res(m);
	for (int i = 0; i < m; ++i){
		int u, v, w; cin>>u>>v>>w;
		u--; v--;
		res[i] = {{u, v}, w};
	}
    
    for (int i = 0; i < n-1; ++i){
    	auto eg = egs[i];
    	fill(vis.begin(), vis.begin() + n, false);
    	vis[eg.S] = true;
    	dfs(eg.F);
    	vis[eg.S] = false;
    	for(auto resEgPr : res){
    		pi &resEg = resEgPr.F;
    		// db(resEg, vis[resEg.F], vis[resEg.S]);
    		if(vis[resEg.F] != vis[resEg.S]) 
    			wgt[i] = max(wgt[i], resEgPr.S);
    	}
    	if(wgt[i] == 0) wgt[i] = 1e6;
    }


    for(auto resEgPr : res){
    	pi &resEg = resEgPr.F;
		int mnWt = getMinWt(resEg.F, resEg.S);
		if(mnWt != resEgPr.S){
			cout<<"-1\n";
			return;
		}
	}

	for (int i = 0; i < n-1; ++i){
		cout<<wgt[i]<<" ";
	}
	cout<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}