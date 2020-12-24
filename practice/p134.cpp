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

// check practice/p127.cpp;
template<const int &MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }

    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }

    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }

    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }

    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];

    static void prepare_save() {
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_save();

        if (val < SAVE_INV)
            return save_inv[val];

        _m_int product = 1;
        int v = val;

        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }

        return product * save_inv[v];
    }

    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
    friend istream& operator>>(istream &is, _m_int &m) {
        return is >> m.val;
    }
};
template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
extern const int MOD = 998244353;
using modInt = _m_int<MOD>;

// https://atcoder.jp/contests/agc046/tasks/agc046_c
// see submissions;

void solve(){
    string str; cin>>str;
    int k; cin>>k;

    vi arr;
    int currSum = 0;
    for(char c : str){
        if(c == '0'){
            arr.pb(currSum);
            currSum = 0;
        }
        else{
            currSum++;
        }
    }
    arr.pb(currSum);

    db(arr);

    int m = SZ(arr);

    int n = count(rng(str), '1');
    // any confrigation of arr can be achieved by atmost n operations;

    k = min(k, n);

    modInt DP[m + 1][n + 1][k + 1];
    modInt DPexpic[m + 1][n + 1][k + 1];
    modInt DPex[m + 1][n + 1][k + 1];
    // DP[i][excess][picked];

    DP[m][0][0] = 1;
    for(int i = 0; i <= min(n, k); ++i){
        DPexpic[m][i][i] = 1;
    }
    for(int i = 0; i <= n; ++i){
        DPex[m][i][0] = 1;
    }

    // O(n ^ 3);
    // O(n ^ 4) works too;
    for(int i = m - 1; i >= 0; --i){ // n
        for(int ex = 0; ex <= n; ++ex){ // n
            for(int pic = 0; pic <= k; ++pic){ // n               
  
                int len = arr[i] - max(0, arr[i] - min(ex, pic)) + 1;
                DP[i][ex][pic] += DPexpic[i + 1][ex][pic] - ((ex - len >= 0 and pic - len >= 0) ? DPexpic[i + 1][ex - len][pic - len] : 0);

                DP[i][ex][pic] += DPex[i + 1][ex - arr[i] + min(n, n + arr[i] - ex)][pic] - DPex[i + 1][ex][pic];

                DPexpic[i][ex][pic] = DP[i][ex][pic] + ((ex and pic) ? DPexpic[i][ex - 1][pic - 1] : 0);
                DPex[i][ex][pic] = DP[i][ex][pic] + (ex ? DPex[i][ex - 1][pic] : 0);

            }
        }
    }

    modInt ans = 0;
    for(int i = 0; i <= k; ++i){
        ans += DP[0][0][i];
    }

    cout<<ans<<el;
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


// normal (works);
// for(int i = m - 1; i >= 0; --i){ // n
//     for(int ex = 0; ex <= n; ++ex){ // n
//         for(int pic = 0; pic <= k; ++pic){ // n
//             for(int curr = 0; curr <= n; ++curr){ // n
//                 if(curr <= arr[i]){ // picked;
//                     if(arr[i] - curr > ex) continue;
//                     if(arr[i] - curr > pic) continue;
//                     DP[i][ex][pic] += DP[i + 1][ex - (arr[i] - curr)][pic - (arr[i] - curr)];
//                 }
//                 else{ // droped;
//                     if(ex + curr - arr[i] > n) continue;
//                     DP[i][ex][pic] += DP[i + 1][ex + curr - arr[i]][pic];
//                 }
//             }
//         }
//     }
// }

// to apply prefix sums;
// for(int curr = max(0, arr[i] - min(ex, pic)); curr <= arr[i]; ++curr){ // picked
//     DP[i][ex][pic] += DP[i + 1][ex - arr[i] + curr][pic - arr[i] + curr];
// }
// for(int curr = arr[i] + 1; curr <= min(n, n + arr[i] - ex); ++curr){ // droped; 
//     DP[i][ex][pic] += DP[i + 1][ex - arr[i] + curr][pic];
// }