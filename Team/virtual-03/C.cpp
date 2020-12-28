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

// https://codeforces.com/problemset/problem/901/C
// nice question;

const int N = 3e5;
vvi cycs;
vi currCyc, adj[N];
vector <char> status(N, 'w');

bool dfs(int node, int par = -1){
	status[node] = 'g';
		
	for(int child : adj[node]){
		if(child == par or status[child] == 'b'){
			continue;
		}
		if(status[child] == 'g'){
			currCyc.pb(child);
			currCyc.pb(node);
			status[node] = 'b';
			return true;
		}
		if(dfs(child, node)){
			if(currCyc[0] == node){
				cycs.pb(currCyc);
				db(currCyc);
				currCyc.clear();
				status[node] = 'b';
				return false;
			}
			else{
				currCyc.pb(node);
				status[node] = 'b';
				return true;
			}
		}
	}

	status[node] = 'b';
	return false;
}


void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
   	for(int i = 0; i < n; ++i){
   		assert(status[i] != 'g');
   		if(status[i] == 'w'){
   			dfs(i);
   		}
   	}

   	vi mxl(n, -1);
   	for(vi& cyc : cycs){
   		int l = n, r = -1;
   		for(int node : cyc){
   			maxi(r, node);
   			mini(l, node);
   		}
   		mxl[r] = l;
   	}

   	vi mxi(n);
   	int curr = -1;
   	for(int i = 0; i < n; ++i){
   		maxi(curr, mxl[i]);
   		mxi[i] = curr;
   	}

   	// (mxi[i], i) -> segment contain cycle;

   	vi prefmxi = mxi;
   	for(int i = 1; i < n; ++i){
   		prefmxi[i] += prefmxi[i - 1];
   	}

   	int q; cin >> q;
   	while(q--){
   		int ql, qr; cin >> ql >> qr;
   		ql--, qr--;

   		int l = ql - 1, r = qr + 1;
   		while(l + 1 < r){
   			int m = (l + r) >> 1;
   			db(m);
   			if(mxi[m] < ql){
   				l = m;
   			}
   			else{
   				r = m;
   			}
   		}

   		int ans = qr * (qr + 1) / 2 - (ql - 1) * ql / 2;
   		ans -= (l - ql + 1) * (ql - 1);
   		ans -= prefmxi[qr] - (l >= 0 ? prefmxi[l] : 0);

   		cout << ans << el;
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