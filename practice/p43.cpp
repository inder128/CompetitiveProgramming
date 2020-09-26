#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
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
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; 
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// nice question;
// https://codeforces.com/contest/1304/problem/E

const int N = 1e5;
vi adj[N], depth(N, -1);
vvi sp(N, vi(20, -1));

void dfs(int node){
    for(int child : adj[node]){
        if(depth[child] != -1) continue;
        depth[child] = depth[node] + 1;
        sp[child][0] = node;
        dfs(child);
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for (int b = 0; b < 20; ++b){
        if(diff&(1<<b)) v = sp[v][b];
    }
    if(v == u) return u;

    for (int b = 19; b >= 0; --b){
        int au = sp[u][b], av = sp[v][b];
        if(au == av) continue;
        u = au, v = av;
    }
    return sp[u][0];
}

int dist(int u, int v){
    int a = lca(u, v);
    return depth[u] + depth[v] - 2*depth[a];
}

bool ok(int dist, int k){
    return dist <= k and dist%2 == k%2;
}

void solve(){
    int n; cin>>n;
    for (int i = 0; i < n-1; ++i){
        int u, v; cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    depth[0] = 0; dfs(0);
    for (int b = 1; b < 20; ++b){
        for (int i = 0; i < n; ++i){
            if(sp[i][b-1] != -1)
                sp[i][b] = sp[sp[i][b-1]][b-1];
        }
    }
    int q; cin>>q;
    while(q--){
        bool isSol = false;
        int x, y, a, b, k; cin>>x>>y>>a>>b>>k;
        x--, y--, a--, b--;
        int ab = dist(a, b), xy = dist(x, y);
        int ax = dist(a, x), ay = dist(a, y);
        int bx = dist(b, x), by = dist(b, y);
        if(ax + ay != xy and bx + by != xy){ // a and b are not part of cycle;
            isSol |= ok(ab, k);
            isSol |= ok(ax + by + 1, k);
            isSol |= ok(ay + bx + 1, k);
        }
        else{ // a or b is part of cycle
            if(ax + ay == xy){ // making sure b is a part of cycle;
                swap(a, b), swap(ax, bx), swap(ay, by);
            }
            isSol |= ok(ab, k); // stat-1
            // isSol |= ok(ab + (xy + 1), k);  //same to one of (ax + 1 + yb) or (ay + 1 + xb); stat-2
            isSol |= ok(ax + ay + 1 - ab, k); // stat-3
            // isSol |= ok(ax + ay + 1 - ab + (xy + 1), k); // stat-4


            // stat-1 and stat-4 are same and (ax + ay + 1 - ab + (xy + 1)) >= (ab)
            // so basicly statement 4 is useless;

            // stat-2 and stat-3 are same and (ab + (xy + 1)) >= (ax + ay + 1 - ab)
            // so basicly statement 3 is useless;
        }

        /*
        checking this no matter the position of a and b will work;
        isSol |= ok(ab, k);
        isSol |= ok(ax + by + 1, k);
        isSol |= ok(ay + bx + 1, k);
        */

        cout<<(isSol ? "YES" : "NO")<<el;
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