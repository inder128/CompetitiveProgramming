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

class BIT{
public :
	int n;
	vi f;
	BIT(int n){
		this->n = n;
		f.assign(n, 0);
	}

	int get(int pos){
		int res = 0;
		for (; pos >= 0; pos = (pos & (pos + 1)) - 1){
		    res += f[pos];
		}
		return res;
	}

	int get(int l, int r){
		if(l > r) return 0;
		return get(min(r, n - 1)) - get(l - 1);
	}

	void increase(int pos, int val){
		for (; pos < SZ(f); pos = (pos | (pos + 1))) {
			f[pos] += val;
		}
	}

	// (logn)^2;
	int operator[](int i){
		int l = -1, r = n;
		// invarients;
		// get(r) > i, get(l) <= i;
		while(l + 1 < r){
			int m = (l + r) >> 1;
			if(get(m) > i){
				r = m;
			}
			else{
				l = m;
			}
		}
		return r;
	}
};

vi b;
int n;
const int N = 500;
int DP[N][N];
map <int, int> ind;

int get(int l, int r){
	if(DP[l][r] != -1){
		return DP[l][r];
	}
	if(l >= r){
		// db(l, r);
		return DP[l][r] = 1;
	}

	BIT bt(r + 1);

	DP[l][r] = 0;
	int ls = ind[l];
	for (int i = l; i <= r; ++i){
		bt.increase(ind[i], 1);
		// db(ind[i], i);
		// ind[l]
		int mx = ls + i - l;
		if(bt.get(ls, mx) == i - l + 1){
			// db(bt.get(ls, mx));
			DP[l][r] = add(DP[l][r], mul(get(l + 1, i), get(i + 1, r)));
			// db(DP[l][r], i, l, r);
		}
	}

	// db(l, r, DP[l][r]);
	return DP[l][r];
}

void solve(){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			DP[i][j] = -1;
		}
	}

	ind.clear();

    int n; cin >> n;
    vi a(n); cin >> a;
    map <int, int> mp;
    for (int i = 0; i < n; ++i){
    	mp[a[i]] = i;
    }
    b = vi(n); cin >> b;
    for (int i = 0; i < n; ++i){
    	b[i] = mp[b[i]];
    	ind[b[i]] = i;
    }




    cout << get(1, n - 1) << el;
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