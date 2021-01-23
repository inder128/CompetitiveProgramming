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
    int n; cin >> n;
    vi perm(n + 1);
    perm[n] = n / 2;
    for(int i = n / 2 + 1; i <= n - 1; ++i){
        perm[i] = i + 1;
    }
    perm[1] = n / 2 + 1;
    for(int i = n / 2; i >= 2; --i){
        perm[i] = i - 1;
    }
    vi aperm = perm;

    vector <pi> op;
    int cost = 0;
    auto dop = [&](int i, int j){
        op.pb({i, j});
        cost += (j - i) * (j - i);
        assert(perm[j] == i);
        swap(perm[i], perm[j]);
    };

    for(int i = n / 2 + 1; i <= n - 1; ++i){
        int j = 1;
        dop(i, j);
    }
    for(int i = n / 2; i >= 2; --i){
        int j = n;
        dop(i, j);
    }
    dop(1, n);

    for(int i = 1; i <= n; ++i){
        assert(perm[i] == i);
    }


    cout << cost << el;
    for(int i = 1; i <= n; ++i){
        cout << aperm[i] << " ";
    }
    cout << el;
    cout << SZ(op) << el;
    for(auto p : op){
        cout << p.F << " " << p.S << el;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}