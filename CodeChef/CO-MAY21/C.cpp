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
vi adj[N], a(N);
map <int, vi> pre, tim;
int t;

const int mod = 1e9 + 7;

int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}

int sub(int x, int y){
    return add(x, -y);
}

int mul(int x, int y){
    return (x * 1ll * y) % mod;
}

int binPow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x){
    return binPow(x, mod - 2);
}

int divide(int x, int y){
    return mul(x, inv(y));
}

int dfs(int node = 0, int par = -1){
	int st = t++;

	int la = 0;
	bool isLeaf = true;
	for(int child : adj[node]){
		if(child == par){
			continue;
		}
		isLeaf = false;
		la = add(la, dfs(child, node));
	}
	int lsm = la;

	if(isLeaf){
		la = 1;
	}
	else{
		int i = upper_bound(rng(tim[a[node]]), st) - tim[a[node]].begin();
		la = sub(la, sub(pre[a[node]].back(), pre[a[node]][i - 1]));
	}

	tim[a[node]].pb(t++);
	pre[a[node]].pb(add(pre[a[node]].back(), la));

	return add(la, lsm);
}

void solve(){
    int n; cin >> n;

    t = 0;
    pre.clear();
    tim.clear();
    for(int i = 0; i < n; ++i){
    	adj[i].clear();
    }

    for(int i = 0; i < n - 1; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
        pre[a[i]] = {0};
        tim[a[i]] = {-1};
    }

    cout << dfs() << el;
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