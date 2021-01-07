#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

void solve(){
    int n, k; cin >> n >> k;
    set <int> vals;
    for(int i = 0; i < k; ++i){
        int a; cin >> a;
        vals.insert(a - n);
    }
    n = SZ(vals);

    map <int, vi> adj;
    map <int, int> dist;
    for(int i = -1000; i <= 1000; ++i){
        for(int j : vals){
            adj[i].pb(i + j);
        }
        dist[i] = 1e9;
    }

    queue <int> Q;
    Q.push(0);
    dist[0] = 0;
    while(SZ(Q)){
        int node = Q.front(); Q.pop();
        for(int child : adj[node]){
            if(child == 0){
                cout << dist[node] + 1 << el;
                return;
            }
            if(dist[child] > dist[node] + 1){
                dist[child] = dist[node] + 1;
                Q.push(child);
            }
        }
    }

    cout << -1 << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}