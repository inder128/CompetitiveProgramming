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
typedef pair<int,int> pi; typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector <vvi> vvvi;
 
/*-----------------------------Code Begins--------------------------------*/

// https://codeforces.com/contest/1487/problem/G


const int mod = 998244353;

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


const int N = 400;
int DP[N + 1][26][26];
int DP1[N + 1][2][2][N + 1];

void solve(){
    int n; cin >> n;
    vi c(26); cin >> c;

    for(int i = 0; i < 26; ++i){
    	for(int j = 0; j < 26; ++j){
    		DP[2][i][j] = 1;
    	}
    }
    for(int i = 3; i <= n; ++i){
    	for(int c1 = 0; c1 < 26; ++c1){
    		for(int c2 = 0; c2 < 26; ++c2){
    			for(int c0 = 0; c0 < 26; ++c0){
    				if(c0 == c2) continue;
    				DP[i][c1][c2] = add(DP[i][c1][c2], DP[i - 1][c0][c1]);
    			}
    		}
    	}
    }

    for(int i = 0; i < 2; ++i){
    	for(int j = 0; j < 2; ++j){
    		DP1[2][i][j][i + j] = (i ? 1 : 25) * (j ? 1 : 25);
    	}
    }
    for(int i = 3; i <= n; ++i){
    	for(int c1 = 0; c1 < 2; ++c1){
    		for(int c2 = 0; c2 < 2; ++c2){
    			for(int cnt1 = c1 + c2; cnt1 <= i; ++cnt1){
    				for(int c0 = 0; c0 < 2; ++c0){
    					// c0 c1 c2
    					if(c0 and c2) continue;
    					int fac = c2 ? 1 : 24 + (c0 > 0);
    					DP1[i][c1][c2][cnt1] = add(DP1[i][c1][c2][cnt1], mul(fac, DP1[i - 1][c0][c1][cnt1 - c2]));
    				}
    			}
    		}
    	}
    }


    vector <vvvi> DP2(3, vvvi(3, vvi(n + 1, vi(n + 1))));
    for(int i = 0; i < 3; ++i){
    	for(int j = 0; j < 3; ++j){
    		DP2[i][j][(int)(i == 1) + (j == 1)][(int)(i == 2) + (j == 2)] = (i ? 1 : 24) * (j ? 1 : 24);
    	}
    }
    for(int i = 3; i <= n; ++i){
    	vector <vvvi> newDP2(3, vvvi(3, vvi(n + 1, vi(n + 1))));
    	for(int c1 = 0; c1 < 3; ++c1){
    		for(int c2 = 0; c2 < 3; ++c2){
    			for(int cnt1 = (int)(c1 == 1) + (c2 == 1); cnt1 <= i; ++cnt1){
    				for(int cnt2 = (int)(c1 == 2) + (c2 == 2); cnt1 + cnt2 <= i; ++cnt2){
    					for(int c0 = 0; c0 < 3; ++c0){
    						if(c0 and c2 and c0 == c2) continue;
    						int fac = c2 ? 1 : 23 + (c0 > 0);
    						newDP2[c1][c2][cnt1][cnt2] = add(newDP2[c1][c2][cnt1][cnt2], mul(fac, DP2[c0][c1][cnt1 - (c2 == 1)][cnt2 - (c2 == 2)]));
    					}
    				}
    			}
    		}
    	}
    	DP2 = newDP2;
    }


    int ans = 0;
    for(int i = 0; i < 26; ++i){
    	for(int j = 0; j < 26; ++j){
    		ans = add(ans, DP[n][i][j]);
    	}
    }
    for(int i = 0; i < 26; ++i){
    	for(int j = c[i] + 1; j <= n; ++j){
    		for(int c1 = 0; c1 < 2; ++c1){
    			for(int c2 = 0; c2 < 2; ++c2){
    				ans = sub(ans, DP1[n][c1][c2][j]);
    			}
    		}
    	}
    }
    for(int i = 0; i < 26; ++i){
    	for(int j = 0; j < i; ++j){
    		for(int ci = c[i] + 1; ci <= n; ++ci){
    			for(int cj = c[j] + 1; cj <= n; ++cj){
    				for(int c1 = 0; c1 < 3; ++c1){
    					for(int c2 = 0; c2 < 3; ++c2){
    						ans = add(ans, DP2[c1][c2][ci][cj]);
    					}
    				}
    			}
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