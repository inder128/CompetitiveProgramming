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

// https://codeforces.com/contest/1510/problem/G

const int N = 101;
vvi DP, nxt;
vi adj[N], sz(N);
vi path;


void dfs(int node = 0, int par = -1){
	sz[node] = 1;
	for(int child : adj[node]){
		if(child == par){
			continue;
		}
		dfs(child, node);
		sz[node] += sz[child];
	}
}


int get(int node, int par, int k){
	if(DP[node][k] != -1){
		return DP[node][k];
	}

	if(k == 1){
		return DP[node][k] = 0;
	}

	int &ans = DP[node][k];
	ans = 1e6;

	int smch = sz[node] - 1;
	for(int child : adj[node]){
		if(child == par){
			continue;
		}

		for(int i = 1; i < k; ++i){
			if(k - 1 - i <= smch - sz[child]){
				int pans = get(child, node, i) + 1 + 2 * (k - 1 - i);
				if(pans < ans){
					ans = pans;
					nxt[node][k] = child * 1000 + i;
				}
			}
		}
	}

	return ans;
}

void rt(int node, int par, int x){
	path.pb(node);

	x--;

	for(int child : adj[node]){
		if(x == 0){
			break;
		}
		if(child == par){
			continue;
		}

		int xx = min(x, sz[child]);

		x -= xx;

		rt(child, node, xx);
		path.pb(node);
	}
}

void go(int node, int par, int k){

	path.pb(node);

	if(k == 1){
		return;
	}


	int nc = nxt[node][k] / 1000, i = nxt[node][k] % 1000;

	int rem = k - 1 - i;

	for(int child : adj[node]){
		if(rem == 0){
			break;
		}

		if(child == par or child == nc){
			continue;
		}


		int x = min(rem, sz[child]);

		rem -= x;

		rt(child, node, x);

		path.pb(node);
	}
	go(nc, node, i);

}

void solve(){
    nxt = DP = vvi(N, vi(N, -1));
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; ++i){
    	adj[i].clear();
    }
    path.clear();

    for(int i = 1; i < n; ++i){
    	int pi; cin >> pi; 
    	adj[pi - 1].pb(i + 1 - 1);
    	adj[i + 1 - 1].pb(pi - 1);
    }

    dfs();

    int ans = get(0, -1, k);
    cout << ans << el;
    go(0, -1, k);


    assert(ans + 1 == SZ(path));
    for(int i : path){
    	cout << i + 1 << " ";
    }
    cout << el;
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