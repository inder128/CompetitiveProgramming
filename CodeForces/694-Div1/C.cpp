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

const int N = 3e5;
vi adj[N];
vector <bool> chosen(N), vis(N);


void dfs(int node = 0){
	vis[node] = true;
	for(int child : adj[node]){
		if(vis[child]){
			continue;
		}
		dfs(child);
	}
}


void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i){
    	chosen[i] = false;
    	vis[i] = false;
    	adj[i].clear();
    }
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs();
    if(count(vis.begin(), vis.begin() + n, true) < n){
    	cout << "No" << el;
    	return;
    }


    fill(rng(vis), false);
    queue <int> Q; Q.push(0);
    while(SZ(Q)){
    	int node = Q.front(); Q.pop();
    	if(vis[node]){
    		continue;
    	}
    	vis[node] = true;
    	bool bl = false;
    	for(int child : adj[node]){
    		if(vis[child]){
    			if(chosen[child]){
    				bl = true;
    			}
    		}
    		else{
    			Q.push(child);
    		}
    	}
    	if(bl == false){
    		chosen[node] = true;
    	}
    }


    cout << "Yes" << el;
    vi ans;
    for(int i = 0; i < n; ++i){
    	if(chosen[i]){
    		ans.pb(i);
    	}
    }
    cout << SZ(ans) << el;
    for(int i : ans){
    	cout << i + 1 << " ";
    }
    cout << el;
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