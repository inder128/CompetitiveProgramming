#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

const int N = 1e5;
vi adj[N], mxComp(N, 1);
int n;

int dfs(int node = 0, int par = -1){
    int sz = 1;
    for(int child : adj[node]){
        if(child == par) continue;
        int chSz = dfs(child, node);
        maxi(mxComp[node], chSz);
        sz += chSz;
    }
    maxi(mxComp[node], n - sz);
    return sz;
}

void solve(){
    cin>>n;
    for (int i = 0; i < n; ++i){
        mxComp[i] = 1;
        adj[i].clear();
    }
    for (int i = 0; i < n-1; ++i){
        int u, v; cin>>u>>v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    int mnCompSz = *min_element(mxComp.begin(), mxComp.begin() + n);
    int mnCnt = count(mxComp.begin(), mxComp.begin() + n, mnCompSz);
    

    int x = 0, y = n-1;
    while(mxComp[x] != mnCompSz) x++;
    while(mxComp[y] != mnCompSz) y--;

    int z = (adj[y][0] == x ? adj[y][1] : adj[y][0]);

    cout<<y+1<<" "<<z+1<<el;
    cout<<x+1<<" "<<z+1<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}