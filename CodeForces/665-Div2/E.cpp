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

const int N = 1e6 + 6;
vi del[N], add[N];
vi fs(N), fe(N);
vector <pi> verts(N, {-1, -1});

ll get(int pos, vi &f){
    ll res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        res += f[pos];
    return res;
}
void update(int pos, int val, vi &f){
    for (; pos < int(f.size()); pos |= pos + 1)
        f[pos] += val;
}


void solve(){
    int n, m; cin>>n>>m;

    for (int i = 0; i < n; ++i){
        int y, l, r; cin>>y>>l>>r;
        if(l==0) del[r].pb(y), update(y, 1, fs);
        if(r==1e6) add[l].pb(y);
    }
    update(1e6, 1, fs);
    update(0, 1, fs);

    for (int i = 0; i < m; ++i){
        int x, l, h; cin>>x>>l>>h;
        verts[x] = {l, h};
    }
    verts[(int)1e6] = {0, 1e6};
    verts[0] = {0, 1e6};

    ll ans = 0;
    for (int i = 0; i <= 1e6; ++i){
        for(int y : add[i]) update(y, 1, fe);

        if(i != 0)
            ans += get(verts[i].S, fs) - get(verts[i].F - 1, fs);
        if(i != 1e6)
            ans += get(verts[i].S, fe) - get(verts[i].F - 1, fe);

        if(verts[i].S != -1)
            db(verts[i], ans);

        for(int y : del[i]) update(y, -1, fs);
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