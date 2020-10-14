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

void solve(){
    int w, h, n, m; cin>>w>>h>>n>>m;
    vi a(n); for(int &i : a) cin>>i;
    vi b(m); for(int &i : b) cin>>i;
    set <int> sa, spb(rng(b));
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            sa.insert(abs(a[i] - a[j]));
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i){
        for (int j = i+1; j < m; ++j){
            if(sa.count(abs(b[j] - b[i])))
                sa.erase(abs(b[j] - b[i])), ans++;
        }
    }
    int ex = 0;
    for (int i = 0; i <= h; ++i){
        if(spb.count(i)) continue;
        set <int> exln;
        for (int j = 0; j < m; ++j){
            exln.insert(abs(i - b[j]));
        }
        int tex = 0;
        for(int ln : exln){
            if(sa.count(ln))
                tex++;
        }
        ex = max(ex, tex);
    }
    cout<<ans + ex<<el;
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