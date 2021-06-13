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

int n, m; 

bool valid(int x, int y){
    return x >= 0 and  x < n and y >= 0 and y < m; 
}

const int N = 1e6 + 6;
const int mod = 1e9 + 7;
int fact[N], invFact[N];

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

void preCalc(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
    invFact[N - 1] = inv(fact[N - 1]);
    for(int i = N - 2; i >= 0; i--)
        invFact[i] = mul(i + 1, invFact[i + 1]);
}

int C(int n, int k){
    if(k > n) return 0;
    return mul(fact[n], mul(invFact[k], invFact[n - k]));
}

void solve(){
    cin >> n >> m;
    int k; cin >> k;

    // db(n, m, k);

    vector <string> mat(n); cin >> mat;

    vvi dist(n, vi(m, 1e9));
    queue <pi> Q;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		if(mat[i][j] == 'X'){
    			Q.push({i, j});
    			dist[i][j] = 0;
    		}
    	}
    }

    while(SZ(Q)){
    	auto [i, j] = Q.front(); Q.pop();

    	for(int dx = -2; dx <= 2; ++dx){
    		for(int dy = -2; dy <= 2; ++dy){
    			if(dx == 0 or dy == 0) continue;
    			if(abs(dx) + abs(dy) != 3) continue;
    			int ni = i + dx, nj = j + dy;
    			if(valid(ni, nj) and dist[i][j] + 1 < dist[ni][nj]){
	    			dist[ni][nj] = dist[i][j] + 1;
	    			Q.push({ni, nj});
	    		}
    		}
    	}
    }

    vi vals;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		vals.pb(dist[i][j]);
    	}
    }
    sort(rng(vals));

    int fac = C(n * m, k);
    // db(fac);

    int ans = 0;
    for(int i = n * m - 1; i >= 0; --i){
    	ans = add(ans, mul(vals[i], divide(C(i, k  - 1), fac)));
    }


    cout << ans << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    preCalc();
    while(T--){
        solve();
    }
    return 0;
}