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

struct node{
	int size, par, mn, mx;
};

class DSU{ 
public: 
    int n;

    vector <node> nodes;

    DSU(int n){ 
        this->n = n; 
        for (int i = 0; i < n; ++i){
        	nodes.pb({1, i, i, i});
        }
    }

    int getPar(int x){
        return nodes[x].par = (nodes[x].par == x ? x : getPar(nodes[x].par));
    }

    bool unite(int x, int y){
        x = getPar(x), y = getPar(y);
        if(x == y) return false;

        if(nodes[x].size > nodes[y].size) swap(x, y);

        nodes[y].size += nodes[x].size;
       	nodes[x].par = y;

       	mini(nodes[y].mn, nodes[x].mn);
       	maxi(nodes[y].mx, nodes[x].mx);
        return true;
    }
};


void solve(){
    int n, q; cin>>n>>q;
    DSU dsu(n);
    while(q--){
    	string op; cin>>op;
    	if(op == "union"){
    		int u, v; cin>>u>>v;
    		u--, v--;
    		dsu.unite(u, v);
    	}
    	else{
    		int u; cin>>u;
    		u--;
    		u = dsu.getPar(u);
    		node ans = dsu.nodes[u];
    		cout<<ans.mn + 1<<" "<<ans.mx + 1<<" "<<ans.size<<el;
    	}
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