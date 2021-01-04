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
    int n, v; cin >> n >> v;
    vector <pi> b[2];
    b[0].pb({0, 0});
    b[1].pb({0, 0});
    for(int i = 1; i <= n; ++i){
        int t, x; cin >> t >> x;
        b[t - 1].pb({x, i});
    }
    for(int i = 0; i < 2; ++i){
        sort(b[i].begin() + 1, b[i].end(), greater<pi>());
        for(int j = 1; j < SZ(b[i]); ++j){
            b[i][j].F += b[i][j - 1].F;
        }
    }

    int a = 0, bb = 0, c = -1;
    for(int i = 0; i < SZ(b[0]) and i <= v; ++i){
        int rem = v - i;
        rem /= 2;
        mini(rem, SZ(b[1]) - 1);
        if(b[0][i].F + b[1][rem].F > c){
            a = i, bb = rem, c = b[0][i].F + b[1][rem].F;
        }
    }


    cout << c << el;
    for(int i = 1; i <= a; ++i){
        cout << b[0][i].S << " ";
    }
    for(int i = 1; i <= bb; ++i){
        cout << b[1][i].S << " ";
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