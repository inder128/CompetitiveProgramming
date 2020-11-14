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

const int N = 2e5 + 5;
vi weights(N);
vi adj[N];
int n, m;
vi ad(N), bd(N), cd(N);

void bfs(vi &v, int s){
	for (int i = 0; i < n; ++i){
		v[i] = -1;
	}
	v[s] = 0;
	queue <int> Q;
	Q.push(s);
	while(Q.size()){
		int node = Q.front(); Q.pop();
		for(int ch : adj[node]){
			if(v[ch] != -1) continue;
			v[ch] = v[node] + 1;
			Q.push(ch);
		}
	}
}

void solve(){
    cin>>n>>m;
    for (int i = 0; i < n; ++i){
    	adj[i].clear();
    }
    int a, b, c; cin>>a>>b>>c;
    a--, b--, c--;

    for (int i = 1; i <= m; ++i){
    	cin>>weights[i];
    }
    sort(weights.begin(), weights.begin() + m + 1);
    for (int i = 1; i <= m; ++i){
    	weights[i] += weights[i - 1];
    }

    for (int i = 0; i < m; ++i){
    	int u, v; cin>>u>>v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    bfs(ad, a);
    bfs(bd, b);
    bfs(cd, c);

    int ans = LLONG_MAX;
    for (int i = 0; i < n; ++i){
    	int x = ad[i], y = bd[i], z = cd[i];
        if(x + y + z > m) continue;
    	mini(ans, weights[x + y + z] + weights[y]);
    }

    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
