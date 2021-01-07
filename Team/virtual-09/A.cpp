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
vi adj[N];
vi path;
vector <char> vis(N, 'w');
bool cyc = false;


bool dfs(int node){
	vis[node] = 'g';
	if(node % 2 and SZ(adj[node]) == 0){
		path.pb(node);
		return true;
	}
	for(int child : adj[node]){
		if(vis[child] == 'b'){
			continue;
		}
		if(vis[child] == 'g'){
			cyc = true;
		}
		else{
			if(dfs(child)){
				path.pb(node);
				return true;
			}
		}
	}
	vis[node] = 'b';
	return false;
}


void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i){
    	int k; cin >> k;
    	for(int j = 0; j < k; ++j){
    		int v; cin >> v;
    		v--;
    		adj[2 * i].pb(2 * v + 1);
    		adj[2 * i + 1].pb(2 * v);
    	}
    }
    int r; cin >> r;
    r--;

    dfs(2 * r);

    if(SZ(path) == 0){
    	if(cyc){
    		cout << "Draw" << el;
    	}
    	else{
    		cout << "Lose" << el;
    	}
    }
    else{
    	cout << "Win" << el;
    	reverse(rng(path));
    	for(int u : path){
    		cout << u / 2 + 1 << " ";
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