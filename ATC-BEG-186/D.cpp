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

class DSU{ 
public: 
    int n;

    vector <vector<int>> nodes;
    vector <map<int, int>> cnt;
    vi par;

    DSU(int n, vi &cl){
        this->n = n;
        nodes.resize(n);
        par.resize(n);
        cnt.resize(n);
        for (int i = 0; i < n; ++i){
        	nodes[i].pb(i);
        	cnt[i][cl[i]] = 1;
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
        	par[w] = y;
        	nodes[y].pb(w);
        }

        for(pi p : cnt[x]){
        	cnt[y][p.F] += p.S;
        }

        cnt[x].clear();

        return true;
    }


    int get(int x, int cl){
    	return cnt[par[x]][cl];
    }
};


void solve(){
    int n, q; cin>>n>>q;
    vi cl(n); cin>>cl;
    DSU dsu(n, cl);
    while(q--){
    	int op; cin>>op;
    	if(op == 1){
    		int a, b; cin>>a>>b;
    		a--, b--;
    		dsu.unite(a, b);
    	}
    	else{
    		int x, y; cin>>x>>y;
    		x--;
    		cout<<dsu.get(x, y)<<el;
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