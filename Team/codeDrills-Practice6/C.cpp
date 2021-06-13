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


int N = 100;
vvi x, c;
int n, m;
int xx, yy;

int p, p1; 

vector <string> mat;

void get(int i, int j){
    if(mat[i][j] == '2'){
        x[i][j] = c[i][j] = 0;
        return;
    }
    if(mat[i][j] == 'x'){
        x[i][j] = 1, c[i][j] = 0;
        return;
    }

    if(x[i][j] != -1){
        return;
    }

    get(i, j + 1);
    get(i + 1, j);

    x[i][j] = add(mul(p, x[i][j + 1]), mul(p1, x[i + 1][j]));
    c[i][j] = add(mul(p, 1 + c[i][j + 1]), mul(p1, 1 + c[i + 1][j]));
}


void solve(){
    cin >> n >> m;

    mat = vector <string> (n);
    cin >> mat;

    cin >> xx >> yy;

    p = divide(xx, yy);
    p1 = divide(yy - xx, yy);

    int sr = 0;

    int ans = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(mat[i][j] != '1'){
                continue;
            }
            sr++;


            x = c = vvi(N, vi(N, -1));
            get(i, j);

            // x = x[i][j] * x + c[i][j];

            ans = add(ans, divide(c[i][j], 1 - x[i][j]));
        }
    }

    cout << divide(ans, sr) << el;
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