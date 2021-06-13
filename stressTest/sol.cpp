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


const int N = 101;
vector <vvi> DP(N, vvi(N, vi(N)));
int p, q, s, n; 

void go(int c1, int c2, int rem){

    if(DP[c1][c2][rem]){
        return;
    }

    DP[c1][c2][rem] = 1;
    if(rem == 0){
        return;
    }
    // db(c1, c2, rem);

    go(p, c2, rem - 1);
    go(c1, q, rem - 1);

    go(0, c2, rem - 1);
    go(c1, 0, rem - 1);
    
    int tak = min(p - c1, c2);
    go(c1 + tak, c2 - tak, rem - 1);
    tak = min(c1, q - c2);
    go(c1 - tak, c2 + tak, rem - 1);
}

void solve(){
    cin >> p >> q >> s >> n;

    go(0, 0, s);

    int diff = n;
    for(int i = 0; i <= p; ++i){
        for(int j = 0; j <= q; ++j){
            if(accumulate(rng(DP[i][j]), 0)) {
                mini(diff, abs(i + j - n));
            }
        }
    }

    cout << diff << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}