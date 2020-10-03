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

// https://www.codechef.com/CZEN2020/problems/AVVST
// nice question;

const int N = 3e5 + 3;
vi adj[N], sieve(N, true);
vi rg(N), ind(N), f(N), val(N);
int tin;

int isPrime(int n){
    return ((n > 1 and sieve[n]) ? 1 : 0);
}

void calcSieve(){
    for (ll i = 2; i < N; ++i){
        if(sieve[i] == false) continue;
        for (ll j = i*i; j < N; j += i){
            sieve[j] = false;
        }
    }
}

int get(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        res += f[pos];
    return res;
}
void update(int pos, int val){
    for (; pos < int(f.size()); pos |= pos + 1)
        f[pos] += val;
}

void dfs(int node = 1, int par = -1){
    ind[node] = tin++;
    update(ind[node], isPrime(val[node]));
    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child, node);
    }
    rg[ind[node]] = tin - ind[node];
}

void solve(){
    int n, q; cin>>n>>q;
    tin = 1;
    for (int i = 0; i <= n; ++i){
        adj[i].clear();
        f[i] = 0;
    }
    for (int i = 1; i <= n; ++i){
        cin>>val[i];
    }
    for (int i = 0; i < n-1; ++i){
        int x, y; cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs();
    while(q--){
        int op; cin>>op;
        if(op == 2){
            int node; cin>>node;
            cout<<get(ind[node] + rg[ind[node]] - 1) - get(ind[node] - 1)<<el;
        }
        else{
            int x, nv; cin>>x>>nv;
            update(ind[x], isPrime(nv) - isPrime(val[x])); 
            val[x] = nv;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    calcSieve();
    cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}