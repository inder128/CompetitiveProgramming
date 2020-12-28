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

void solve(){
    int n; cin >> n;
    vi arr[n], all;
    for(int i = 0; i < n; ++i){
    	int k; cin >> k;
    	for(int j = 0; j < k; ++j){
    		int x; cin >> x;
    		arr[i].pb(x);
    		all.pb(x);
    	}
    }

    sort(rng(all));
    all.resize(unique(rng(all)) - all.begin());
    int m = SZ(all);

    unordered_set <int> adj[n + m];
    for(int u = 0; u < n; ++u){
    	for(int j = 0; j < SZ(arr[u]); ++j){
    		int v = lower_bound(rng(all), arr[u][j]) - all.begin() + n;
    		adj[v].insert(u);
    		adj[u].insert(v);
    	}
    }

    set <pi, greater <pi>> order;
 	for(int i = 0; i < n + m; ++i){
 		order.insert({SZ(adj[i]), i});
 	}

 	while(SZ(order)){
 		int u = order.begin()->S; order.erase(order.begin());

 		unordered_map <int, int> cameFrom;
 		int x, y, v = -1;
 		for(int child : adj[u]){
 			for(int neig : adj[child]){
 				if(neig == u) continue;
 				if(cameFrom.count(neig)){
 					v = neig;
 					x = child;
 					y = cameFrom[neig];
 				}
 				if(v != -1){
 					break;
 				}
 				cameFrom[neig] = child;
 			}
 			if(v != -1){
 				break;
 			}
 		}

 		if(v != -1){
 			if(u < n){
 				cout << u + 1 << " " << v + 1 << el;
 			}
 			else{
 				cout << x + 1 << " " << y + 1 << el;
 			}
 			return;
 		}

 		for(int child : adj[u]){
 			order.erase({SZ(adj[child]), child});
 			adj[child].erase(u);
 			order.insert({SZ(adj[child]), child});
 		}
 	}

 	cout << -1 << el;
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