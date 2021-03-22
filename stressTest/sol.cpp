/*
c[0] -> (1 - n)


sum of c[i] * 10^i;

c[0] -> (n + 1) / 2
c[1] -> (n + 1)



groups = (n + 1) / 2^(i + 1);
c[i] += groups * 2 ^ (i) 
c[i] += max(0, (n + 1) - groups * 2 ^ (i + 1) - 2 * (i));

0000
0001
0010
0011

0100
0101
0110
0111

1000
1001
1010
1011

1100
1101
1110

*/
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

const int mod = 1e9 + 7;

void solve(){
    vi pow2(61);
    pow2[0] = 1;
    for(int i = 1; i < 61; ++i){
        pow2[i] = pow2[i - 1] * 2;
    }

    int n; cin >> n;
    int pow10 = 1;
    int ans = 0;
    for(int i = 0; i < 60; ++i){
        int groups = (n + 1) / pow2[i + 1];
        int ci = groups * pow2[i] + max(0ll, n + 1 - groups * pow2[i + 1] - pow2[i]);
        ans = (ans + ci % mod * pow10) % mod;
        pow10 = pow10 * 10 % mod;
    }

    cout << ans << el;
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
