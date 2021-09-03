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


// combanitorics
const int N = 200043;
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


int m;
map <pi, pi> DP;

pi get(int a, int b){
	if(DP.count({a, b})){
		return DP[{a, b}];
	}
	if(a == m or b == m){
		return DP[{a, b}] = {0, 0};
	}


	pi ans = {0, 0};
	int fac = 1;
	for (int i = 1; i <= 6; ++i){
		if(a + i == m){
			pi = 
		}
		else if(a + i > m){
			for (int j = 1; j <= 6; ++j){
				if(b + j <= m){
					if(b + j == a){
						pi a2 = get(1, b + j);
						a2.S = add(a2.S, 2);
					}
					else{
						pi a2 = get(a, b + j);
						a2.S = add(a2.S, 2);
					}
				}
				else{
					fac = sub(fac, divide(1, 36));
				}
			}
		}
		else if(a + i == b){
			for (int j = 1; j <= 6; ++j){
				if(1 + j == a + i){
					if(a == 1 and b == 1 + j){
						fac = sub(fac, divide(1, 36));
					}
					else{
						pi a2 = get(1, 1 + j);
						a2.S = add(a2.S, 2);
					}
				}
				else{
					pi a2 = get(a + i, 1 + j);
				}
			}
		}
		else{
			for (int j = 1; j <= 6; ++j){
				if(b + j > m){

				}
				else if(b + j == a){
					// a = 1, b = b + j
					a2 = get(1, b + j);
				}
				else{
					a2 = get(a + i, b + j);
				}
			}
		}
	}
}


void solve(){
    
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