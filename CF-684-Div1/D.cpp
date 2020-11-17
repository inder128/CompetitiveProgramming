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

// gives tle with simple set;
const int N = 1e5;
unordered_set <int> adj[N];

void solve(){
    int n, m, k; cin>>n>>m>>k;
    for (int i = 0; i < n; ++i){
        adj[i].clear();
    }
    vector <int> degree(n);
    for (int i = 0; i < m; ++i){
        int u, v; cin>>u>>v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
        degree[u]++;
        degree[v]++;
    }
    set <pi> degreePair;
    for (int i = 0; i < n; ++i){
        degreePair.insert({degree[i], i});
    }

    while(degreePair.size()){
        auto small = *degreePair.begin();
        int node = small.S, deg = small.F;

        if(deg >= k){
            cout<<1<<" "<<degreePair.size()<<el;
            for(pi p : degreePair){
                cout<<p.S + 1<<" ";
            }
            cout<<el;
            return;
        }

        // this can happen atmost m / k times;
        // its runtime -> O(k * k);
        // total runtime -> O((m / k) * (k * k)) = O(m * k);
        // k < sqrt(n);
        // total runtime -> O(m * sqrt(n));
        // O(300 * 10^5) -> O(3 * 10^7);
        if(deg == k - 1){
            vi clique{node};
            for(int child : adj[node]){
                clique.pb(child);
            }

            bool isClique = true;
            for (int i = 0; i < k; ++i){
                int u = clique[i];
                for (int j = 0; j < i; ++j){
                    int v = clique[j];
                    if(adj[u].count(v) == 0){
                        isClique = false;
                        break;
                    }
                }
                if(isClique == false) break;
            }

            if(isClique){
                cout<<2<<el;
                for(int i : clique) cout<<i + 1<<" "; cout<<el;
                return;
            }
        }

        degreePair.erase(small);

        for(int par : adj[node]){
            degreePair.erase({degree[par], par});
            degree[par]--;
            adj[par].erase(node);
            degreePair.insert({degree[par], par});
        }
        adj[node].clear();
        degree[node] = 0;
    }

    cout<<"-1\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}