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

// don't use the same variables names;
// make new variable names;
// nice question;
// check editorial;
// check these submissions :-
// https://codeforces.com/contest/1444/submission/97514842
// https://codeforces.com/contest/1444/submission/97519874
// https://codeforces.com/contest/1444/submission/97523365
// https://codeforces.com/contest/1444/submission/97523466

int n, m, k;
const int N = 5e5;
vi gp(N), adj[N], notBipartite(N), no(N);
map <pi, vector <pi>> edges;

void dfs(int node, int num){
    no[node] = num;
    for(int child : adj[node]){
        if(gp[child] != gp[node]) continue;
        if(no[child] == no[node]){
            notBipartite[gp[node]] = 1;
            return;
        }
        if(no[child]) continue;
        dfs(child, num^1);
    }
}

int checkBpt(vector <pi> &egs){
    map <int, int> par, size;
    for(pi eg : egs){
        int u = no[eg.F], v = no[eg.S];
        par[u] = u;
        par[v] = v;
        par[u^1] = u^1;
        par[v^1] = v^1;
        size[u] = size[u^1] = 1;
        size[v] = size[v^1] = 1;
    }

    function <int(int)> getPar = [&](int i){
        return ((i == par[i]) ? i : par[i] = getPar(par[i]));
    };

    for(pi eg : egs){
        int u = no[eg.F], v = no[eg.S];
        // union u and v^1, v and u^1;
        int pu = getPar(u), pv = getPar(v);
        int pu1 = getPar(u^1), pv1 = getPar(v^1);

        if(pu == pv or pu1 == pv1) return 1;

        // merge(pu, pv1);
        if(size[pu] > size[pv1]) swap(pu, pv1);
        size[pv1] += size[pu];
        par[pu] = pv1;

        // merge(pv, pu1);
        if(size[pv] > size[pu1]) swap(pv, pu1);
        size[pu1] += size[pv];
        par[pv] = pu1;
    }

    return 0;
}

// another implementation to check bipartite.
// int checkBpt(vector <pi> &egs){
//     map <int, set <int>> ladj;
//     for(pi eg : egs){
//         int u = no[eg.F], v = no[eg.S];
//         ladj[u].insert(v);
//         ladj[v].insert(u);

//         ladj[u].insert(u^1);
//         ladj[v].insert(v^1);
//     }
//     map <int, int> col;
//     for(auto &ppp : ladj){
//         if(col[ppp.F]) continue;

//         queue <int> Q;
//         Q.push(ppp.F);
//         col[ppp.F] = 2;
//         while(Q.size()){
//             int node = Q.front(); Q.pop();
//             for(auto &ch : ladj[node]){
//                 if(col[ch] == col[node]) return 1;
//                 if(col[ch]) continue;
//                 col[ch] = col[node]^1;
//                 Q.push(ch);
//             }
//         }
//     }
//     return 0;
// }

void solve(){
    cin>>n>>m>>k;
    for (int i = 0; i < n; ++i){
        cin>>gp[i];
        gp[i]--;
    }
    for (int i = 0; i < m; ++i){
        int u, v; cin>>u>>v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        if(gp[u] == gp[v]) continue;
        if(gp[u] > gp[v]) swap(u, v);

        // gp[u] < gp[v];
        edges[{gp[u], gp[v]}].pb({u, v});
    }

    int nos = 2;
    for (int i = 0; i < n; ++i){
        if(no[i]) continue;
        dfs(i, nos);
        nos += 2;
    }

    // don't use the same variables names;
    // make new variable names;
    int goodKs = 0;
    for (int i = 0; i < k; ++i){
        if(notBipartite[i] == 0){
            goodKs++;
        }
    }
    int ans = goodKs*(goodKs - 1)/2;
    
    for(auto &ppp : edges){
        int g1 = ppp.F.F, g2 = ppp.F.S;
        if(notBipartite[g1] or notBipartite[g2]) continue;

        ans -= checkBpt(ppp.S);
    }
    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}