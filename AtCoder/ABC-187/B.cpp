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

const int N = 2e5;
vi adj[N], par(N), weight(N);


void dfs(int node = 0, int p = -1){
	par[node] = p;
	for(int child : adj[node]){
		if(child == p){
			continue;
		}
		weight[child] += weight[node];
		dfs(child, node);
	}
}


void solve(){
    int n; cin >> n;
    vector <pi> edges(n - 1);
    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	edges[i] = {u, v};
    }

    dfs();

    int q; cin >> q;
    while(q--){
    	int op, i, inc; cin >> op >> i >> inc;
    	i--;
    	if(op == 1){ // a - b -> a ++;
    		if(par[edges[i].F] == edges[i].S){ // b is par of a;
    			weight[edges[i].F] += inc;
    		}
    		else{
    			weight[0] += inc;
    			weight[edges[i].S] -= inc;
    		}
    	}
    	else{
    		if(par[edges[i].S] == edges[i].F){ // a is par of b;
    			weight[edges[i].S] += inc;
    		}
    		else{
    			weight[0] += inc;
    			weight[edges[i].F] -= inc;
    		}
    	}
    }


    dfs();

	for(int i = 0; i < n; ++i){
		cout << weight[i] << el;
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