#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
// #define int long long
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

// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
// checkout wrong submision (Memory Limit error);
// stack use much more save than vector;

class DSU{ 
public: 
    int n;

    vector <vector<int>> nodes;
    vi score, inc, par;

    DSU(int n){ 
        this->n = n;
        nodes.resize(n);
        score.resize(n);
        inc.resize(n);
        par.resize(n);
        for (int i = 0; i < n; ++i){
        	nodes[i].pb(i);
        	par[i] = i;
        }  
    }

    int getPar(int x){
        return par[x];
    }

    int size(int x){
    	return nodes[x].size();
    }

    bool unite(int x, int y){
        x = getPar(x), y = getPar(y);
        if(x == y) return false;

        if(size(x) > size(y)) swap(x, y);

        while(nodes[x].size()){
        	int w = nodes[x].back(); nodes[x].pop_back();
        	score[w] += inc[x] - inc[y];
        	par[w] = y;
        	nodes[y].pb(w);
        }

        return true;
    }


    void increase(int x, int v){
    	inc[par[x]] += v;
    }

    int get(int x){
    	return inc[par[x]] + score[x];
    }
};


void solve(){
    int n, q; cin>>n>>q;
    DSU dsu(n);
    while(q--){
    	string op; cin>>op;
    	if(op == "add"){
    		int u, v; cin>>u>>v;
    		u--;
    		dsu.increase(u, v);
    	}
    	else if(op == "join"){
    		int u, v; cin>>u>>v;
    		u--, v--;
    		dsu.unite(u, v);
    	}
    	else{
    		int x; cin>>x;
    		x--;
    		cout<<dsu.get(x)<<el;
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