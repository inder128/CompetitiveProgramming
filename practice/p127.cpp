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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/contest/1155/problem/E
// gaussian elimination;


const int mod = 1e6 + 3;

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

int binpow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int divide(int x, int y){
    return mul(x, inv(y));
}


// return 0 (if no soln / incosistent), 1 (if unique soln), 1e9 (if infinite soln);
int gaussianElimination(vvi AB, vi& X){
    // m equations and n variables;
    int m = SZ(AB), n = SZ(AB[0]) - 1; 

    vi pivotRow(n, -1);
    for(int col = 0, row = 0; col < n and row < m; ++col){
        // maximum hueristic;
        int sel = row;
        for(int i = row; i < m; ++i){
            if(AB[i][col] > AB[sel][col]){
                sel = i;
            }
        }

        // no pivot row is found for this variable or this variable is free;
        // now defenately unique soln does not exist;
        if(AB[sel][col] == 0){
            continue;
        }

        for(int i = col; i <= n; ++i){
            swap(AB[sel][i], AB[row][i]);
        }
        pivotRow[col] = row;

        for(int i = 0; i < m; ++i){
            if(i != row){
                int c = divide(AB[i][col], AB[row][col]);
                for (int j = col; j <= n; ++j){
                    AB[i][j] = sub(AB[i][j], mul(AB[row][j], c));
                }
            }
        }

        ++row;
    }

    X.assign(n, 0);
    for(int i = 0; i < n; ++i){
        if(pivotRow[i] != -1){
            X[i] = divide(AB[pivotRow[i]][n], AB[pivotRow[i]][i]);
        }
        // else : free variables (pivotRow[i] == i) are taken 0 by default;
    }

    for(int i = 0; i < m; ++i){
        int sum = 0;
        for(int j = 0; j < n; ++j){
            sum = add(sum, mul(X[j], AB[i][j]));
        }

        // no solution or incosistent;
        if(sum != AB[i][n]){
            return 0;
        }
    }

    for(int i = 0; i < n; ++i){
        // infinitely many solution or rank(AB) < n;
        if(pivotRow[i] == -1){
            return 1e9;
        }
    }

    // unique soln or rank(AB) = n;
    return 1;
}


vi hidden(11);


int get(int x){
    int ans = 0, f = 1;
    for(int i = 0; i < 11; ++i){
        ans = add(ans, mul(f, hidden[i]));
        f = mul(f, x);
    }
    return ans;
}



void solve(){
    vvi AB(11, vi(12));
    for(int i = 0; i < 11; ++i){
        cout<<"? "<<i<<endl;
        cin>>AB[i][11];
        int f = 1;
        for(int j = 0; j < 11; ++j){
            AB[i][j] = f;
            f = mul(f, i);
        }
    }

    gaussianElimination(AB, hidden);

    int ans = -1;
    for(int i = 0; i < 1e6 + 3; ++i){
        if(get(i) == 0){
            ans = i;
            break;
        }
    }
    cout<<"! "<<ans<<endl;
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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

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
};
template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
extern const int MOD = 1e6 + 3;
using modInt = _m_int<MOD>;


// return 0 (if no soln / incosistent), 1 (if unique soln), 1e9 (if infinite soln);
int gaussianElimination(vector <vector<modInt>> AB, vector <modInt>& X){
    // m equations and n variables;
    int m = SZ(AB), n = SZ(AB[0]) - 1; 

    vi pivotRow(n, -1);
    for(int col = 0, row = 0; col < n and row < m; ++col){
        // maximum hueristic;
        int sel = row;
        for(int i = row; i < m; ++i){
            if(AB[i][col] > AB[sel][col]){
                sel = i;
            }
        }

        // no pivot row is found for this variable or this variable is free;
        // now defenately unique soln does not exist;
        if(AB[sel][col] == 0){
            continue;
        }

        for(int i = col; i <= n; ++i){
            swap(AB[sel][i], AB[row][i]);
        }
        pivotRow[col] = row;

        for(int i = 0; i < m; ++i){
            if(i != row){
                modInt c = AB[i][col] / AB[row][col];
                for (int j = col; j <= n; ++j){
                    AB[i][j] -= AB[row][j] * c;
                }
            }
        }

        ++row;
    }

    X.assign(n, 0);
    for(int i = 0; i < n; ++i){
        if(pivotRow[i] != -1){
            X[i] = AB[pivotRow[i]][n] / AB[pivotRow[i]][i];
        }
        // else : free variables (pivotRow[i] == i) are taken 0 by default;
    }

    for(int i = 0; i < m; ++i){
        modInt sum = 0;
        for(int j = 0; j < n; ++j){
            sum += X[j] * AB[i][j];
        }

        // no solution or incosistent;
        if(sum != AB[i][n]){
            return 0;
        }
    }

    for(int i = 0; i < n; ++i){
        // infinitely many solution or rank(AB) < n;
        if(pivotRow[i] == -1){
            return 1e9;
        }
    }

    // unique soln or rank(AB) = n;
    return 1;
}

vector <modInt> hidden(11);
 
 
modInt get(int x){
    modInt ans = 0, f = 1;
    for(int i = 0; i < 11; ++i){
        ans += f * hidden[i];
        f *= x;
    }
    return ans;
}


void solve(){
    vector <vector <modInt>> AB(11, vector <modInt>(12));
    for(int i = 0; i < 11; ++i){
        cout<<"? "<<i<<endl;
        int x; cin>>x;
        AB[i][11] = x;
        modInt f = 1;
        for(int j = 0; j < 11; ++j){
            AB[i][j] = f;
            f *= i;
        }
    }

    gaussianElimination(AB, hidden);

    int ans = -1;
    for(int i = 0; i < 1e6 + 3; ++i){
        if(get(i) == 0){
            ans = i;
            break;
        }
    }
    cout<<"! "<<ans<<endl;
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