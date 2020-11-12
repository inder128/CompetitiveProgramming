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
    vi size, par;
    int n;

    DSU(int n){ 
        this->n = n; 
        size.assign(n, 1);
        par.resize(n);
        iota(rng(par), 0);
    }

    int getPar(int u){
        return par[u] = (par[u] == u ? u : getPar(par[u]));
    }

    bool unite(int u, int v){
        u = getPar(u), v = getPar(v);
        if(u == v) return false;

        if(size[u] > size[v]) swap(u, v);
        size[v] += size[u], par[u] = v;
        return true;
    }
};

struct edje{
	int u, v, w, ind; 
};

void solve(){
    int n, m, cost; cin>>n>>m>>cost;
    vector <edje> edjes(m);
    for (int i = 0; i < m; ++i){
    	int u, v, w; cin>>u>>v>>w;
    	u--, v--;
    	edjes[i] = {u, v, w, i + 1};
    }
    sort(rng(edjes), [&](const edje &e1, const edje &e2){
    	return e1.w > e2.w;
    });

    

	DSU dsu(n);
    vi vec;
	for (int j = 0; j < m; ++j){
		if(dsu.unite(edjes[j].u, edjes[j].v)){

    	}
        else{
            vec.pb(j);
        }
    }

    int j = 0;
    reverse(rng(vec));
    vi ans;
    for (int i : vec){
        if(cost - edjes[i].w < 0) break;
        j++;
        cost -= edjes[i].w;
        ans.pb(edjes[i].ind);
    }

    cout<<ans.size()<<el;
    for(int i : ans) cout<<i<<" "; cout<<el;
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