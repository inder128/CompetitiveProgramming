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

const int N = 1e5;
vector <pi> adj[N];
vi col(N, -1);
int n;

void dfs(int node = 0, int c = 0){
	col[node] = c;
	for(pi ch : adj[node]){
		if(col[ch.F] != -1) continue;
		if(ch.S == c){
			dfs(ch.F, (c + 1) % n);
		}
		else{
			dfs(ch.F, ch.S);
		}
	}
}

void solve(){
    int m; cin>>n>>m;
    for (int i = 0; i < m; ++i){
    	int u, v, w; cin>>u>>v>>w;
    	u--, v--, w--;
    	adj[u].pb({v, w});
    	adj[v].pb({u, w});
    }
    dfs();
    for (int i = 0; i < n; ++i){
    	cout<<col[i] + 1<<el;
    }
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