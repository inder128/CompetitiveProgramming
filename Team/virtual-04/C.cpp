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
vi adj[N], order(N);
vector <char> status(N);
int t;

struct edge{
	int u, v, w, i;
	bool operator<(const edge& other) const {
		return w < other.w;
	};
};


bool dfs(int node){
	status[node] = 'g';
	for(int child : adj[node]){
		if(status[child] == 'b'){
			continue;
		}
		if(status[child] == 'g'){
			return true;
		}
		if(dfs(child)){
			return true;
		}
	}
	order[node] = t--;
	status[node] = 'b';
	return false;
}


void solve(){
    int n, e; cin >> n >> e;
    vector <edge> edges(e);
    for(int i = 0; i < e; ++i){
    	int u, v, w; cin >> u >> v >> w;
    	u--, v--;
    	edges[i] = {u, v, w, i};
    }
    sort(rng(edges));

    int l = -1, r = e - 1; 
    // invarients;
    // after removing first r edges graph do not contains cycle;
    // after removing first l edges graph contains cycle;

    auto check = [&](int m){
    	for(int i = 0; i < n; ++i){
    		adj[i].clear();
    		status[i] = 'w';
    	}
    	for(int i = m; i < e; ++i){
    		int u = edges[i].u, v = edges[i].v;
    		adj[u].pb(v);
    	}
    	t = n;
    	bool containCycle = false;
    	for(int i = 0; i < n; ++i){
    		if(status[i] == 'b') continue;
    		assert(status[i] != 'g');
    		if(dfs(i)){
    			containCycle = true;
    			break;
    		}
    	}
    	return containCycle;
    };

    while(l + 1 < r){
    	int m = (l + r) >> 1;
    	
    	if(check(m) == false){
    		r = m;
    	}
    	else{
    		l = m;
    	}
    }

    if(r == 0){
    	cout << 0 << " " << 0 << el;
    }
    else{
    	check(r);
    	vi ans;
    	for(int i = 0; i < r; ++i){
    		int u = edges[i].u, v = edges[i].v;
    		if(order[u] > order[v]){
    			ans.pb(edges[i].i);
    		}
    	}
    	cout << edges[r - 1].w << " " << SZ(ans) << el;
    	sort(rng(ans));
    	for(int i : ans){
    		cout << i + 1 << " ";
    	}
    	cout << el;
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