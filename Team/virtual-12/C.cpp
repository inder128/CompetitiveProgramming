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

const int N = 1000, K = 60;
int DP[N + 1][N + 1][K + 1];
int fact[N + 1];

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
	fact[0] = 1;
	for(int i = 1; i <= N; ++i){
		fact[i] = mul(i, fact[i - 1]);
	}


	// DP[i][d][k] -> 1, ---- i, k pairs, mxD = d;
    for(int i = 0; i <= N; ++i){
    	for(int d = 0; d <= N; ++d){
    		DP[i][d][0] = 1;
    	}	
    }


    for(int i = 1; i <= N; ++i){
    	for(int d = 0; d <= N; ++d){
    		for(int k = 1; k <= K; ++k){
    			if(d == 0){
    				DP[i][d][k] = (k == 1) * i;
    			}
    			else{
    				DP[i][d][k] = add(DP[i][d][k], DP[i - 1][d][k]);
    				DP[i][d][k] = add(DP[i][d][k], DP[i][d - 1][k]);
    				DP[i][d][k] = sub(DP[i][d][k], DP[i - 1][d - 1][k]);
    				if(i > d){
    					DP[i][d][k] = add(DP[i][d][k], DP[i - d - 1][d - 1][k - 1]);
    				}
    			}
    		}
    	}
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    solve();
    cin >> T;
    while(T--){
        int n, k; cin >> n >> k;
        if(k > 60){
        	cout << 0 << el;
        }
        else{
        	cout << mul(fact[k], DP[n][1000][k]) << el;
        }
    }
    return 0;
}