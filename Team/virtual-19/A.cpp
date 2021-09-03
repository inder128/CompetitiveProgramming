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

const int N = 200043;
const int mod = 998244353;
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
	int n; cin >> n;
    vi arr{0};
    for(int i = 0; i < n; ++i){
    	char ch; cin >> ch;
    	if(ch == '+'){
    		int x; cin >> x;
    		arr.pb(x);
    	}
    	else{
    		arr.pb(-1);
    	}
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
    	if(arr[i] == -1){
    		continue;
    	}
    	vvi DP(n + 1, vi(n));
    	DP[0][0] = 1;
    	for(int j = 1; j < i; ++j){
    		DP[j] = DP[j - 1];
    		if(arr[j] == -1){
				DP[j][0] = add(DP[j][0], DP[j - 1][0]);
			}
    		for(int k = 0; k < n; ++k){
    			if(arr[j] == -1){
    				if(k + 1 < n){
    					DP[j][k] = add(DP[j][k], DP[j - 1][k + 1]);
    				}
    			}
    			else if(arr[j] <= arr[i]){
    				if(k - 1 >= 0){
    					DP[j][k] = add(DP[j][k], DP[j - 1][k - 1]);
    				}
    			}
    			else{
    				DP[j][k] = add(DP[j][k], DP[j - 1][k]);
    			}
    		}
    	}
    	DP[i] = DP[i - 1];
    	for(int j = i + 1; j <= n; ++j){
    		DP[j] = DP[j - 1];
    		for(int k = 0; k < n; ++k){
    			if(arr[j] == -1){
    				if(k + 1 < n){
    					DP[j][k] = add(DP[j][k], DP[j - 1][k + 1]);
    				}
    			}
    			else if(arr[j] < arr[i]){
    				if(k - 1 >= 0){
    					DP[j][k] = add(DP[j][k], DP[j - 1][k - 1]);
    				}
    			}
    			else {
    				DP[j][k] = add(DP[j][k], DP[j - 1][k]);
    			}
    		}
    	}
    	for(int k = 0; k < n; ++k){
    		ans = add(ans, mul(arr[i], DP[n][k]));
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