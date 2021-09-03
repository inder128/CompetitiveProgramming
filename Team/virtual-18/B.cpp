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
const int mod = 1e9;

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

vi f(N), pref(N);

#define lsi (2*si + 1)
#define rsi (2*si + 2)
#define mid ((sl + sr) >> 1)
class segmentTree{
public :
	int size, n;
	pi NEUTRAL = {0, 0};
	vector <pi> ST;
	int NO_OPERATION = 0;
	vi lazy;
	segmentTree(int _n){
		n = _n;
		size = 1;
		while(size < n) size <<= 1;
		ST.assign(2 * size - 1, NEUTRAL);
		lazy.assign(2 * size - 1, NO_OPERATION);
	}

	void printUtil(int si, int sl, int sr){
		cout<<si<<" : "<<sl<<" - "<<sr<<" : "<<ST[si]<<", "<<lazy[si]<<el;

		if(sl == sr) return;

		printUtil(lsi, sl, mid);
		printUtil(rsi, mid + 1, sr);
	}
	void print(){
		return printUtil(0, 0, n - 1);
	}


	void increase(int si, int sl, int sr, int inc){
		ST[si].F = add(ST[si].F, mul(inc, pref[sr - sl]));
		ST[si].S = add(ST[si].S, mul(inc, sub(pref[sr - sl + 1], pref[0])));
		lazy[si] = add(lazy[si], inc);
	}
	void propogate(int si, int sl, int sr){
		if(lazy[si] == NO_OPERATION) return;
		increase(lsi, sl, mid, lazy[si]);
		increase(rsi, mid + 1, sr, lazy[si]);
		lazy[si] = NO_OPERATION;
	}

	pi merge(pi p1, pi p2, int l){
		if(l == 0){
			return p2;
		}
		if(l == 1){
			p1.F = add(p1.F, p2.S);
		}
		else{
			p1.F = add(p1.F, add(mul(p2.F, f[l - 2]), mul(p2.S, f[l - 1])));
		}
		p1.S = add(p1.S, add(mul(p2.F, f[l - 1]), mul(p2.S, f[l])));
		return p1;
	}
	

	void increaseUtil(int si, int sl, int sr, int ql, int qr, int inc){
		if(qr < sl or sr < ql) return;

		if(ql <= sl and sr <= qr){
			return increase(si, sl, sr, inc);
		}

		propogate(si, sl, sr);

		increaseUtil(lsi, sl, mid, ql, qr, inc);
		increaseUtil(rsi, mid + 1, sr, ql, qr, inc);

		ST[si] = merge(ST[lsi], ST[rsi], mid - sl + 1);
	}
	void increase(int ql, int qr, int inc){
		return increaseUtil(0, 0, n - 1, ql, qr, inc);
	}

	void updateUtil(int si, int sl, int sr, int i, int newVal){
		if(sl == sr){
			ST[si] = {newVal, newVal};
			return;
		}

		if(i <= mid)
			updateUtil(lsi, sl, mid, i, newVal);
		else
			updateUtil(rsi, mid + 1, sr, i, newVal);

		ST[si] = merge(ST[lsi], ST[rsi], mid - sl + 1);
	}
	void update(int i, int newVal){
		return updateUtil(0, 0, n - 1, i, newVal);
	}


	pi getSumUtil(int si, int sl, int sr, int ql, int qr){
		if(qr < sl or sr < ql) return NEUTRAL;

		if(ql <= sl and sr <= qr){
			return ST[si];
		}

		propogate(si, sl, sr);

		pi leftSum = getSumUtil(lsi, sl, mid, ql, qr);
		pi rightSum = getSumUtil(rsi, mid + 1, sr, ql, qr);
		return merge(leftSum, rightSum, max(0ll, min(mid, qr) - max(sl, ql) + 1));
	}
	pi getSum(int ql, int qr){
		return getSumUtil(0, 0, n - 1, ql, qr);
	}
};


void solve(){
	f[0] = f[1] = 1;
    for (int i = 2; i < N; ++i){
    	f[i] = add(f[i - 2], f[i - 1]);
    }
    pref[0] = f[0];
    for (int i = 1; i < N; ++i){
    	pref[i] = add(pref[i - 1], f[i]);
    }


    int n, m; cin >> n >> m;
    segmentTree st(n);
    for (int i = 0; i < n; ++i){
    	int x; cin >> x;
    	st.update(i, x);
    }

    while(m--){
    	int ty; cin >> ty;
    	if(ty == 1){
    		int i, v; cin >> i >> v;
    		i--;
    		st.update(i, v);
    	}
    	else if(ty == 2){
    		int l, r; cin >> l >> r;
    		l--, r--;
    		cout << st.getSum(l, r).F << el;
    	}
    	else{
    		int l, r, v; cin >> l >> r >> v;
    		l--, r--;
    		st.increase(l, r, v);
    	}
    }
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