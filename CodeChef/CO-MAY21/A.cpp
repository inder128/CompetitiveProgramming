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
    vi a(n);
    for(int i = 0; i < n; ++i){
    	int x; cin >> x;
    	x--;
    	a[i] = x;
    }
    vi p(n);
    for(int i = 0; i < n; ++i){
    	int x; cin >> x;
    	x--;
    	p[i] = x;
    }

    vi vis(n), cyno(n), ind(n);
    vvi cycles;
    for(int i = 0; i < n; ++i){
    	if(vis[i]) continue;
    	cycles.pb({});
    	int u = i;
    	while(vis[u] == false){
    		vis[u] = true;
    		cyno[u] = SZ(cycles) - 1;
    		ind[u] = SZ(cycles.back());
    		cycles.back().pb(u);
    		u = p[u];
    	}
    }

    int q; cin >> q;
    int rot = 0;
    while(q--){
    	int ty; cin >> ty;
    	if(ty == 1){
    		rot++;
    	}
    	else if(ty == 2){
    		int x, y; cin >> x >> y;
    		x--, y--;

    		auto &cycx = cycles[cyno[x]];
    		int xi = cycx[(ind[x] - rot % SZ(cycx) + SZ(cycx)) % SZ(cycx)];
    		auto &cycy = cycles[cyno[y]];
    		int yi = cycy[(ind[y] - rot % SZ(cycy) + SZ(cycy)) % SZ(cycy)];

    		swap(a[xi], a[yi]);
    	}
    	else{
    		int x; cin >> x;
    		x--;

    		auto &cycx = cycles[cyno[x]];
    		int xi = cycx[(ind[x] - rot % SZ(cycx) + SZ(cycx)) % SZ(cycx)];

    		cout << a[xi] + 1 << el;
    	}
    }
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