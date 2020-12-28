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

vvi mat, rmat;
int n, m;

int get(vvi v, int t){
    int ans = 0;
    for (int i = 0; i < m; i++){
        int ta = 0;
        for (int j = 0; j < t; ++j)
            ta += (mat[j][i] != v[i%2][j]);
        ans += min(ta, t - ta);
    }
    return ans;
}


void solve(){
    cin>>n>>m;
    mat = vvi(n, vi(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            char x; cin>>x;
            mat[i][j] = (x == '1');
        }
    }
    if(n >= 4){
        cout<<"-1\n";
        return;
    }
    if(n == 1){
        cout<<"0\n";
        return;
    }

    int ans = INT_MAX;
    if(n==2){
        ans = min(ans, get({{0, 0}, {0, 1}}, 2));
        ans = min(ans, get({{0, 1}, {0, 0}}, 2));
    }
    else{
        ans = min(ans, get({{0, 0, 0}, {0, 1, 0}}, 3));
        ans = min(ans, get({{0, 1, 0}, {0, 0, 0}}, 3));
        ans = min(ans, get({{0, 0, 1}, {1, 0, 0}}, 3));
        ans = min(ans, get({{1, 0, 0}, {0, 0, 1}}, 3));
    }
    cout<<ans<<el;
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