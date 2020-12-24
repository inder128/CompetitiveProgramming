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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/contest/1286/problem/B
// see -> https://codeforces.com/contest/1287/submission/82250982

const int N = 2e3;
// num[i] is the number assigned to vertex i;
// ver[i] is the vertex assigned to number i;
vi ver(N, -1), num(N, -1), adj[N], smaller(N), papa(N);
set <int> numsSubtree[N];
int currNo = 0;

bool dfs(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;
        bool sol = dfs(child, node);
        if(sol == false){
            return false;
        }
    }

    ver[currNo] = node, num[node] = currNo;

    int pNode = node;
    while(pNode != -1){
        numsSubtree[pNode].insert(currNo);
        pNode = papa[pNode];
    }

    if(SZ(numsSubtree[node]) < smaller[node] + 1){
        return false;
    }

    int toAssgn = *next(numsSubtree[node].begin(), smaller[node]);

    auto itr = numsSubtree[node].rbegin();
    // shifting colors;
    vi toUpdateVertices;
    while(smaller[node] < SZ(numsSubtree[node])){
        // only num array is updated here;
        swap(num[ver[*itr]], toAssgn);
        toUpdateVertices.pb(ver[*itr]);
        itr = next(itr);
        smaller[node]++;
    }

    // updating ver array;
    for(int u : toUpdateVertices){
        if(num[u] == -1) continue;
        ver[num[u]] = u;
    }

    currNo++;
    return true;
}

void solve(){
    int n, root; cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>papa[i]>>smaller[i];
        papa[i]--;
        if(papa[i] >= 0){
            adj[papa[i]].pb(i);
            adj[i].pb(papa[i]);
        }
        else{
            root = i;
        }
    }

    bool sol = dfs(root, -1);

    if(sol == false){
        cout<<"NO"<<el;
    }
    else{
        cout<<"YES"<<el;
        for(int i = 0; i < n; ++i){
            cout<<num[i] + 1<<" ";
        }
        cout<<el;
    }
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