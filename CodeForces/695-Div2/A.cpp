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



void solve(){
    int n, k, q; cin >> n >> k >> q;
    vi arr(n + 1);
    for(int i = 1; i <= n; ++i){
    	cin >> arr[i];
    }

    vvi go(n + 2, vi(k + 1));
    for(int i = 1; i <= n; ++i){
    	go[i][0] = 1;
    }
    for(int mv = 1; mv <= k; ++mv){
    	for(int pos = 1; pos <= n; ++pos){
    		go[pos][mv] = add(go[pos + 1][mv - 1], go[pos - 1][mv - 1]);
    		// db(mv, pos, go[pos][mv]);
    	}
    }

    vi occ(n + 1);
	for(int i = 1; i <= n; ++i){
	    for(int pos = 0; pos <= k; ++pos){
	    	occ[i] = add(occ[i], mul(go[i][pos], go[i][k - pos]));
	    }
	}  

	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans = add(ans, mul(arr[i], occ[i]));
	}
	// db(occ);

	while(q--){
		int i, x; cin >> i >> x;
		ans = sub(ans, mul(arr[i], occ[i]));
		arr[i] = x;
		ans = add(ans, mul(arr[i], occ[i]));
		cout << ans << el;
	}
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