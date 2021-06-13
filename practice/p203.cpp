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
    string s; cin >> s;
    int k; cin >> k;
    int n = SZ(s);

    if(s == string(n, '?')){
        n = n * k;
        if(n == 1){
            cout << 0 << el;
        }
        else{
            cout << mul(n, binPow(2, n - 2)) << el;
        }
        return;
    }

    if(n == 1){
        cout << 0 << el;
        return;
    }

    int si = 0;
    while(s[si] == '?'){
        si++;
    }

    string x = s.substr(si, n - si) + s.substr(0, si);

    auto get2 = [&](int c1, int c2, int st, int q){
        if(c2 != st and c2 != '?'){
            return 0ll;
        }
        if(c1 == st){
            return 0ll;
        }
        return binPow(2, q - (c1 == '?') - (c2 == '?'));
    };

    auto get = [&](char c1, char c2){
        string ss = s;
        ss[0] = c1, ss[n - 1] = c2;
        char st = '1' - c1 + '0';
        int ans = 0;
        int q = count(rng(x), '?') * (k - 1) + count(rng(ss), '?');
        for(int i = 1; i < n; ++i){
            if(i == si and k > 1){
                ans = add(ans, get2(x[n - 1], ss[si], st, q));
            }
            else{
                ans = add(ans, get2(ss[i - 1], ss[i], st, q));
            }
        }
        if(k == 1){
            return ans;
        }
        ans = add(ans, (si != 0) * get2(ss[si - 1], x[0], st, q));
        ans = add(ans, mul(max(0ll, k - 2), get2(x[n - 1], x[0], st, q)));
        for(int i = 1; i < n; ++i){
            ans = add(ans, mul(k - 1, get2(x[i - 1], x[i], st, q)));
        }
        return ans;
    };

    int ans = 0;
    for(char c1 : {'0', '1'}){
        for(char c2 : {'0', '1'}){
            if((s[0] == '?' or s[0] == c1) and (s[n - 1] == '?' or s[n - 1] == c2)){
                ans = add(ans, get(c1, c2));
            }
        }
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