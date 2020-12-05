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
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

const int N = 1e6 + 6;
vi properDivisor[N], lenCnt(N), pow2(N);

const int mod = 1e9 + 7;

void preCalc(){
    pow2[0] = 1, pow2[1] = 2;
    for(int i = 2; i <= 1e6; ++i){
        pow2[i] = pow2[i - 1] * 2 % mod;
        for(int j = i; j <= 1e6; j += i){
            properDivisor[j].pb(i);
        }
    }
}

int calc(int n){
    return (n * (n + 1) * (n + 1) / 2 % mod - n * (n + 1) * (2*n + 1) / 6 % mod + mod) % mod;
}

void solve(){
    int n; cin>>n;
    vi arr(n); cin>>arr;
    for(int i = 0; i < n; ++i){
        for(int div : properDivisor[arr[i]]){
            lenCnt[div]++;
        }
    }

    int ans = 0;
    // 1 *n + 2* n - 1 + 
    for(int i = 1e6; i >= 2; --i){
        if(lenCnt[i]) lenCnt[i] = lenCnt[i] * pow2[lenCnt[i] - 1];
        for(int j = 2*i; j <= 1e6; j += i){
            lenCnt[i] = (lenCnt[i] - lenCnt[j] + mod) % mod;
        }
        ans = (ans + i * lenCnt[i]) % mod;
    }

    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    preCalc();
    while(T--){
        solve();
    }
    return 0;
}