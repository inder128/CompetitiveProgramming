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

// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/D

class DSU{ 
public: 
    vi par, rank, shift;
    vector <vi> nodes;
    int n;

    DSU(int n){ 
        this->n = n; 
        nodes.resize(n);
        par.resize(n);
        for (int i = 0; i < n; ++i){
        	nodes[i].pb(i);
        	par[i] = i;
        }
        rank.resize(n);
        shift.resize(n);
    }

    int size(int u){
    	return nodes[u].size();
    }

    bool unite(int u, int v){
    	u = par[u], v = par[v];

        int boss = v;

        if(size(u) > size(v)) swap(u, v);
        
        while(nodes[u].size()){
        	int w = nodes[u].back(); nodes[u].pop_back();

        	// actual rank;
        	rank[w] += shift[u];

        	// v is boss;
        	if(boss == v){
        		// shifting; // or componsationg;
        		rank[w] -= shift[v];

        		// increment -> rank will increase (v is parent);
        		rank[w]++;
        	}

        	// u is boss;
        	if(boss == u){
        		// no increase in rank;
        		// but rank of childs of v will increase -> (if(boss == u) shift[v]++;)

        		// componsating for -> (if(boss == u) shift[v]++;)
        		rank[w] -= (shift[v] + 1);
        	}

        	nodes[v].pb(w);
        	par[w] = v;
        }

        if(boss == u) shift[v]++;

        return true;
    }

    int get(int u){
    	return rank[u] + shift[par[u]];
    }
};


void solve(){
    int n, q; cin>>n>>q;
    DSU dsu(n);

    
    while(q--){
    	int op; cin>>op;
    	if(op == 1){
    		int u, v; cin>>u>>v;
    		u--, v--;
    		dsu.unite(u, v);
    	}
    	else{
    		int u; cin>>u;
    		u--;
    		cout<<dsu.get(u)<<el;
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