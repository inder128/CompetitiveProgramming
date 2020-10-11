#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
#define maxi(x, y) x = max(x, (y))  
#define mini(x, y) x = min(x, (y))  
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

// nice question
// https://www.codechef.com/problems/CORE2004

const int N = 1e5;
vi adj[N], lvl(N), ST(1<<18);
vl mxVal(N), val(N);
vector <set <pair <ll, int>>> nodeST(N);
int d = 0;

void dfs(int node = 0, int par = -1, int l = 0){
    maxi(d, l);
    maxi(mxVal[l], val[node]);
    nodeST[l].insert({val[node], node});
    lvl[node] = l;
    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node, l + 1);
    }
}

int comp(int x, int y){
    return (mxVal[x] >= mxVal[y]) ? x : y;
}
 
void updateUtil(int si, int ss, int se, int i) { 
    if (i < ss || se < i)  return;
 
    if(ss == se) return;

    int mid = (ss + se)/2; 
    updateUtil(2*si+1, ss, mid, i); 
    updateUtil(2*si+2, mid+1, se, i); 

    ST[si] = comp(ST[2*si+1], ST[2*si+2]);
} 
 
void update(int i) { 
    return updateUtil(0, 0, d, i); 
}
 
int getIndUtil(int si, int ss, int se, ll v) { 
    if(ss == se) return ST[si];

    int mid = (ss + se)/2;

    if(mxVal[ST[2*si + 1]] > v)  
        return getIndUtil(2*si + 1, ss, mid, v);

    return getIndUtil(2*si + 2, mid + 1, se, v);
}
 
int getInd(ll v) { 
    return getIndUtil(0, 0, d, v); 
}

void constructUtil(int si, int ss, int se){
    if(ss == se){
        ST[si] = ss;
        return;
    }

    int mid = (ss + se)/2; 
    constructUtil(2*si+1, ss, mid); 
    constructUtil(2*si+2, mid+1, se); 

    ST[si] = comp(ST[2*si+1], ST[2*si+2]);
}

void construct(){
    return constructUtil(0, 0, d);
}

void solve(){
    int n; cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>val[i];
    }
    for (int i = 0; i < n-1; ++i){
        int u, v; cin>>u>>v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    construct();

    int q; cin>>q;
    while(q--){
        int op; cin>>op;
        if(op == 1){
            ll x, y; cin>>x>>y; x--;
            int l = lvl[x];

            nodeST[l].erase({val[x], x});
            val[x] = y;
            nodeST[l].insert({val[x], x});

            mxVal[l] = nodeST[l].rbegin()->F;
            update(l);
        }
        else{
            ll y; cin>>y;
            if(mxVal[ST[0]] <= y){
                cout<<"-1\n";
                continue;
            }
            int i = getInd(y);
            cout<<(nodeST[i].upper_bound({y, 1e9})->S)+1<<el;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}