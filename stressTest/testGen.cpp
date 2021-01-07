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

/*-----------------------------Code begins----------------------------------*/

int rand(int l, int r){
    return l + rand() % (r - l + 1);
}

void solve(int bin){
    int n = 100000;
    vector <pi> edges;
    for(int i = 1; i < n; ++i){
        edges.pb({rand(0, i), i});
        edges.pb({rand(0, i), i});
        edges.pb({rand(0, i), i});
    }
    cout << n << " " << SZ(edges) << " " << rand(1, n) << el;
    for(pi p : edges){
        cout << p.F + 1 << " " << p.S + 1 << el;
    }
    return;
}
 
int32_t main(int32_t argc, char* argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    srand(atoi(argv[1]));
    while(T--){
        solve(atoi(argv[1]));
    }
    return 0;
}