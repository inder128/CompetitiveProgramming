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
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// nice question;
// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/D
const int N = 1e5;
int n, m, d;
vector <pi> adj[N];

bool good(int mxW, bool print = false){
	vi dist(n, -1);
	dist[0] = 0;
	queue <int> Q;
	Q.push(0);
	while(Q.size()){
		int node = Q.front(); Q.pop();
		if(dist[node] == d) break;
		for(pi ch : adj[node]){
			if(dist[ch.F] != -1) continue;
			if(ch.S > mxW) continue;
			dist[ch.F] = dist[node] + 1;
			Q.push(ch.F);
		}
	}

	if(print == false) return dist[n - 1] != -1;

	vector <pi> adj2[n];
	for (int i = 0; i < n; ++i){
		for(pi ch : adj[i]){
			adj2[ch.F].pb({i, ch.S});
		}
	}

	cout<<dist[n - 1]<<el;
	vi path;
	int curr = n - 1;
	while(curr){
		path.pb(curr + 1);
		for(pi ch : adj2[curr]){
			// see wrong submission;
			if(dist[ch.F] == dist[curr] - 1 and ch.S <= mxW){
				curr = ch.F;
				break;
			}
		}
	}
	path.pb(1);
	reverse(rng(path));
	for(int v : path) cout<<v<<" ";
	cout<<el;

	return true;
}

void solve(){
	cin>>n>>m>>d;
	for (int i = 0; i < m; ++i){
		int u, v, w; cin>>u>>v>>w;
		u--, v--;
		adj[u].pb({v, w});
	}
	int l = -1; // bad;
	int r = 1e9 + 1; // possibly good;
	while(l + 1 < r){
		int m = (l + r) >> 1;
		if(good(m)){
			r = m;
		}
		else{
			l = m;
		}
	}

	if(r == 1e9 + 1){
		cout<<-1<<el;
		return;
	}

	good(r, true);
}


 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}