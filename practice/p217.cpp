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

// https://codeforces.com/contest/1519/problem/E

const int N = 4e5;
map <pi, int> ind;
vi used(N);
vector <char> state(N, 'w');
vector <pi> adj[N];
vi ans;

void add(int u, int v){
	ans.pb(u);
	ans.pb(v);
	used[u] = used[v] = true;
}

bool dfs(int node, int pari){
	state[node] = 'g';
	vi edges;
	for(auto [child, i] : adj[node]){
		if(i == pari or used[i]) continue;
		if(state[child] == 'g'){
			edges.pb(i);
		}
		else if(dfs(child, i)){
			edges.pb(i);
		}
	}
	state[node] = 'b';
	for(int i = 0; i + 1 < SZ(edges); i += 2){
		add(edges[i], edges[i + 1]);
	}
	if(SZ(edges) % 2 and pari != -1){
		add(edges.back(), pari);
		return false;
	}
	else{
		return true;
	}
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
pi get(int a, int b){
	int g = gcd(a, b);
	return {a / g, b / g};
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
    	int a, b, c, d; cin >> a >> b >> c >> d;
    	pi m1 = get((a + b) * d, b * c);
    	pi m2 = get(a * d, b * (c + d));

    	if(ind.count(m1) == 0){
    		ind[m1] = SZ(ind);
    	}
    	if(ind.count(m2) == 0){
    		ind[m2] = SZ(ind);
    	}

    	adj[ind[m1]].pb({ind[m2], i});
    	adj[ind[m2]].pb({ind[m1], i});
    }

    for(int i = 0; i < SZ(ind); ++i){
    	// db(i, adj[i]);
    }

    // for(auto [fac, i] : ind) db(fac, i);

    for(int i = 0; i < SZ(ind); ++i){
    	if(state[i] == 'b'){
    		continue;
    	}
    	dfs(i, -1);
    }


    cout << SZ(ans) / 2 << el;
    for(int i = 0; i < SZ(ans); i += 2){
    	cout << ans[i] + 1 << " " << ans[i + 1] + 1 << el;
    }
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