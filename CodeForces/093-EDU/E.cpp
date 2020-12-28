#include <bits/stdc++.h>
using namespace std;
 
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}"; }
    #define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...); }
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
/*-----------------------------Code begins----------------------------------*/

const int N = 3e2;
vi adj[N], gp(N, -1);
int gpn = 0;

void dfs(int node){
    gp[node] = gpn;
    for(int child : adj[node]){
        if(gp[child] == -1) dfs(child);
    }
}

void solve(){
    int n; cin>>n;
    vi per(n);
    for(int &i : per) cin>>i, i--;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            char x; cin>>x;
            if(x == '1') adj[i].pb(j);
        }
    }
    for (int i = 0; i < n; ++i){
        if(gp[i] != -1) continue;
        dfs(i);
        gpn++;
    }
    // db(gp);
    vvi gpInd(gpn);
    for (int i = 0; i < n; ++i){
        gpInd[gp[i]].pb(per[i]);
    }
    for (int i = 0; i < gpn; ++i){
        sort(rng(gpInd[i]));
        reverse(rng(gpInd[i]));
    }
    for (int i = 0; i < n; ++i){
        cout<<gpInd[gp[i]].back() + 1<<" ";
        gpInd[gp[i]].pop_back();
    }
    cout<<el;
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