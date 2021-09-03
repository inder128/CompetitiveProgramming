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


void solve(){
    int n, d; cin >> n >> d;
    int mid = 0;
    vi l, r;
    map <int, int> freq2;
    for (int i = 0; i < n; ++i){
    	int x; cin >> x;
    	if(x < -d){
    		l.pb(-x);
    	}
    	else if(x > d){
    		r.pb(x);
    	}
    	else{
    		freq2[x]++;
    		mid++;
    	}
    }

    sort(rng(l));
    sort(rng(r));

    int ans = sub(binPow(2, mid), 1 + mid);
    ans = add(ans, mul(SZ(l) + SZ(r), sub(binPow(2, mid), 1)));


    for (int lf = -d; lf <= d; ++lf){
    	for (int rt = lf; rt <= d; ++rt){
    		int fac;
    		if(rt == lf){
    			fac = sub(binPow(2, freq2[lf]), 1);
    		}
    		else{
    			fac = mul(sub(binPow(2, freq2[lf]), 1), sub(binPow(2, freq2[rt]), 1));
    			int cnt = 0;
    			for (int k = lf + 1; k <= rt - 1; ++k){
    				cnt += freq2[k];
    			}
    			fac = mul(fac, binPow(2, cnt));
    		}
    		for (int i = 0, a = 0, b = 0; i < SZ(l); ++i){
		    	int mn = l[i] - d + lf, mx = l[i] + d + rt;

		    	while(b < SZ(r) and r[b] <= mx){
		    		b++;
		    	}
		    	while(a < SZ(r) and r[a] < mn){
		    		a++;
		    	}
		    	ans = add(ans, mul(fac, b - a));
		    }
    	}
    }

    cout << ans << el;    
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