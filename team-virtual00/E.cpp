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
 
/*------------------------------Code Begins--------------------------------*/

const int mod = 1e9 + 9;

int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}

int sub(int x, int y){
    return add(x, -y);
}

int mul(int x, int y){
    return (x * 1ll * y) % mod;
}

int binPow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x){
    return binPow(x, mod - 2);
}

int divide(int x, int y){
    return mul(x, inv(y));
}



void solve(){
    int k, b; cin >> k >> b;
    if(b <= 15){
        int ans = 0;
        for(int i = 0; i < (1 << b); ++i){
            if(i % k == 0){
                ans += __builtin_popcount(i);
            }
        }
        cout << ans << el;
        return;
    }

    vector <vector <pi>> DP(k, vector <pi>(b + 1));

    // DP[i][j] -> [0, 1 << (j + 10));
    // DP[i][b - 10 + 1]

    vi pow2(130);
    pow2[0] = 1 % k;
    for(int i = 1; i < 130; ++i){
        pow2[i] = (pow2[i - 1] * 2) % k;
    }

    int mxk = 1024;

    for(int i = 0; i < k; ++i){
        for(int j = i; j < mxk; j += k){
            DP[i][10].F += __builtin_popcount(j);
            DP[i][10].S++;
        }
    }

    

    for(int j = 11; j <= b; ++j){
        for(int i = 0; i < k; ++i){
            DP[i][j] = DP[i][j - 1];

            // find next;
            int nxt = (i - pow2[j - 1] + k) % k;

            
            DP[i][j].F = add(DP[i][j].F, add(DP[nxt][j - 1].F, DP[nxt][j - 1].S));
            DP[i][j].S = add(DP[i][j].S, DP[nxt][j - 1].S);
        }
    }


    cout << DP[0][b].F << el;
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