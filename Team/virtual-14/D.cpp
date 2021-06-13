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

const int N = 2e5;
set <int> adj[N];
vi par(N), sz(N);
vi fib(30);

void dfs(int node, int p){
	sz[node] = 1;
	par[node] = p;
	for(int child : adj[node]){
		if(child == p){
			continue;
		}
		dfs(child, node);
		sz[node] += sz[child];
	}
}

int get(int node, int rsz){
	if(sz[node] == rsz){
		return node;
	}
	for(int child : adj[node]){
		if(child == par[node]){
			continue;
		}
		int ans = get(child, rsz);
		if(ans != -1){
			return ans;
		}
	}
	return -1;
}

bool check(int root, int fi){
	if(fi <= 1){
		return true;
	}

	dfs(root, -1);

	int nr = get(root, fib[fi - 1]);
	if(nr != -1){
		adj[par[nr]].erase(nr);
		adj[nr].erase(par[nr]);
		return check(nr, fi - 1) and check(root, fi - 2);
	}


	nr = get(root, fib[fi - 2]);
	if(nr == -1){
		return false;
	}

	adj[par[nr]].erase(nr);
	adj[nr].erase(par[nr]);

	return check(nr, fi - 2) and check(root, fi - 1);
}

void solve(){
    int n; cin >> n;
    if(n == 1){
    	cout << "YES" << el;
    	return;
    }

    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].insert(v);
    	adj[v].insert(u);
    }

    fib[0] = fib[1] = 1;
    for(int i = 2; i < 30; ++i){
    	fib[i] = fib[i - 1] + fib[i - 2];

    	if(n == fib[i]){
    		if(check(0, i)){
    			cout << "YES" << el;
    		}
    		else{
    			cout << "NO" << el;
    		}
    		return;
    	}
    }

    cout << "NO" << el;
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