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

const int N = 1e5;
vector <pi> adj[N], radj[N], fadj[N];
vi costt(N, 1e18), costs(N, 1e18);
vi w(N);

set <int> ming, bridges;

vector<bool> visited(N);
vector<int> tin(N), low(N);
int timer;

int cst;

void findEg(int u, int curr){
    for (auto [v, wi] : adj[u]) {
    	if(visited[wi]) continue;
    	visited[wi] = true;
        if(curr + w[wi] + costt[v] == cst){
        	ming.insert(wi);
        	findEg(v, curr + w[wi]);
        } 
    }
}

void findBg(int v, int p){
	visited[v] = true;
    tin[v] = low[v] = timer++;
    for (auto [to, wi] : fadj[v]) {
        if (wi == p) continue;
        if(ming.count(wi) == 0) continue; 
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            findBg(to, wi);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.insert(wi);
        }
    }
}

void solve(){
    int n, m, s, t; cin >> n >> m >> s >> t;
    s--, t--;
    vector <pi> edges;
    for (int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v >> w[i];
    	u--, v--;
    	adj[u].pb({v, i});
    	radj[v].pb({u, i});
    	fadj[u].pb({v, i}), fadj[v].pb({u, i});
    	edges.pb({u, v});
    }

    priority_queue <pi, vector <pi>, greater <pi>> PQ;
    PQ.push({costs[s] = 0, s});
    while(SZ(PQ)){
        auto [wt, node] = PQ.top(); PQ.pop(); 
        if(wt > costs[node]){
            continue;
        }
        for(auto [child, wi] : adj[node]){
            if(costs[child] > costs[node] + w[wi]){
                costs[child] = costs[node] + w[wi];
                PQ.push({costs[child], child});
            }
        }
    }
    cst = costs[t];

    PQ.push({costt[t] = 0, t});
    while(SZ(PQ)){
        auto [wt, node] = PQ.top(); PQ.pop();
        if(wt > costt[node]){
            continue;
        }
        for(auto [child, wi] : radj[node]){
            if(costt[child] > costt[node] + w[wi]){
                costt[child] = costt[node] + w[wi];
                PQ.push({costt[child], child});
            }
        }
    }

    findEg(s, 0);
   	for (int i = 0; i < m; ++i){
   		visited[i] = false;
   	}
    findBg(s, -1);

    // db(ming, bridges);

    int wi = 0;
    for(auto [u, v] :  edges){
        if(bridges.count(wi)){
        	cout << "YES" << el;
        }
        else if(costs[u] + 1 + costt[v] < cst){
        	cout << "CAN " << w[wi] - (cst - 1 - (costs[u] + costt[v])) << el;
        }
        else{
        	cout << "NO" << el;
        }
        wi++;
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