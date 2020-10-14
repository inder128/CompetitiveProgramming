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

const int N = 1e5 + 5;
vl f(N);
ll get(int pos) {
 ll res = 0;
 for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
     res += f[pos];
 return res;
}
void update(int pos, int val){
 for (; pos < int(f.size()); pos = (pos | (pos + 1)))
     f[pos] += val;
}

void solve(){
    int n, lx, fx; cin>>n;
    ll inc = 0;
    for (int i = 0; i < n; ++i){
        int x; cin>>x;
        update(i, x);
        update(i + 1, -x);
        if(i and x > lx) inc += x - lx;
        lx = x;
    }
    cout<<(ll)ceil((inc + get(0))/2.0)<<el;
    int q; cin>>q;
    while(q--){
        int l, r, x; cin>>l>>r>>x;
        l--, r--;
        if(l) inc -= max(0ll, get(l) - get(l-1));
        if(r < n-1) inc -= max(0ll, get(r + 1) - get(r));
        
        update(l, x);
        update(r + 1, -x);

        if(l) inc += max(0ll, get(l) - get(l-1));
        if(r < n-1) inc += max(0ll, get(r + 1) - get(r));

        cout<<(ll)ceil((inc + get(0))/2.0)<<el;
    }
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