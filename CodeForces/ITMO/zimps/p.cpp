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
// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/E


class DSU{ 
public: 
    int n, head, time;

    vector <vector<int>> nodes;
    vi shift, par;

    DSU(int n, int m){ 
        this->n = n;
        nodes.resize(n);
        shift.resize(n);
        par.resize(n);
        for (int i = 0; i < n; ++i){
        	nodes[i].pb(i);
        	par[i] = i;
        } 
        time = m; 
        head = 0;
    }

    int getPar(int u){
        return par[u];
    }

    int size(int u){
    	return nodes[u].size();
    }

    bool unite(int u, int v){
    	while(nodes[u].size()){
    		int w = nodes[u].back(); nodes[u].pop_back();
    		par[w] = v;
    		nodes[v].pb(w);
    	}
    	return true;
    }

    bool unite(int u, int v, int t){
        u = getPar(u), v = getPar(v);
        if(u == v) return false;

        if(u != head and v != head){
        	if(size(u) > size(v)){
        		return unite(v, u);
        	}
        	else{
        		return unite(u, v);
        	}
        }

        if(u == head) swap(u, v);

        // v is head;
        if(size(v) >= size(u)){
        	for(int w : nodes[u]){
        		shift[w] += (t - time);
        	}
        	unite(u, v);
        } 
        else{
        	for(int w : nodes[v]){
        		shift[w] += (time - t);
        	}

        	time = t;
        	head = u;
        	unite(v, u);
        }

        return true;
    }


    int get(int u){
    	return shift[u] + time;
    }
};


void solve(){
    int n, q; cin>>n>>q;

    DSU dsu(n, q);

    vector <pi> links(n);
    for (int i = 0; i < n; ++i){
    	int l, r; cin>>l>>r;
    	l--, r--;
    	links[i] = {l, r};
    }


    vector <pi> queries(q), tmpLinks = links;
    for (int i = 0; i < q; ++i){
     	int l, r; cin>>l>>r;
     	l--, r--;
     	queries[i] = {l, r};
     	if(r == 0){
     		tmpLinks[l].F = -2;
     	}
     	else{
     		tmpLinks[l].S = -2;
     	}
    } 

    for (int i = 0; i < n; ++i){
    	if(tmpLinks[i].F != -2){
    		dsu.unite(i, tmpLinks[i].F, q);
    	}
    	if(tmpLinks[i].S != -2){
    		dsu.unite(i, tmpLinks[i].S, q);
    	}
    }

    for (int t = q - 1; t >= 0; --t){
    	int u = queries[t].F;
    	int v;
    	if(queries[t].S == 0){
    		v = links[u].F;
    	}
    	else{
    		v = links[u].S;
    	}
    	dsu.unite(u, v, t);
    }

    for (int i = 0; i < n; ++i){
    	int ans = dsu.get(i);
    	if(ans == q) ans = -1;
    	cout<<ans<<el;
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