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

// 2500 rated difficult question 
// below algo is wrong
// https://codeforces.com/contest/1407/problem/E

const int N = 5e5;
vector <pair <int, bool>> adj[N];
vector <char> state(N, 'w');
vector <pi> memo(N, {-1, -1});
string str(N, '1');
int n;

int dfs(int node = 0){
    if(node == n-1) return 0;
    if(state[node] == 'b'){
        return max(memo[node].F, memo[node].S);
    }

    state[node] = 'g';
    for(auto childPr : adj[node]){
        if(state[childPr.F] == 'g') continue;
        int td = dfs(childPr.F);
        if(childPr.S == false){
            maxi(memo[node].F, td + 1); 
        }
        else{
            maxi(memo[node].S, td + 1); 
        }
    }

    state[node] = 'b';
    if(memo[node].F == -1) memo[node].F = 1e9;
    if(memo[node].S == -1) memo[node].S = 1e9;
    if(memo[node].F > memo[node].S)
        str[node] = '0';
    return max(memo[node].F, memo[node].S);
}

void solve(){
    int m; cin>>n>>m;
    for (int i = 0; i < m; ++i){
        int u, v, ty; cin>>u>>v>>ty;
        u--, v--;
        adj[u].pb({v, ty});
    }
    int ans = dfs();
    cout<<(ans >= 1e9 ? -1 : ans)<<el;
    cout<<string(str.begin(), str.begin() + n)<<el;
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