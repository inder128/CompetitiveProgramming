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

#define lsi (2*si + 1)
#define rsi (2*si + 2)
#define mid ((sl + sr) >> 1)
class segmentTree{
public :
	int size, n;
	int NEUTRAL = 0;
	vi ST;
	int NO_OPERATION = 0;
	vi lazy;
	segmentTree(int _n){
		n = _n;
		size = 1;
		while(size < n) size <<= 1;
		ST.assign(2 * size - 1, 0ll);
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
		ST[si] += inc;
		lazy[si] += inc;
	}
	void propogate(int si, int sl, int sr){
		if(lazy[si] == NO_OPERATION) return;
		increase(lsi, sl, mid, lazy[si]);
		increase(rsi, mid + 1, sr, lazy[si]);
		lazy[si] = NO_OPERATION;
	}
	

	void increaseUtil(int si, int sl, int sr, int ql, int qr, int inc){
		if(qr < sl or sr < ql) return;

		if(ql <= sl and sr <= qr){
			return increase(si, sl, sr, inc);
		}

		propogate(si, sl, sr);

		increaseUtil(lsi, sl, mid, ql, qr, inc);
		increaseUtil(rsi, mid + 1, sr, ql, qr, inc);

		ST[si] = max(ST[lsi], ST[rsi]);
	}
	void increase(int ql, int qr, int inc){
		return increaseUtil(0, 0, n - 1, ql, qr, inc);
	}


	int getMaxUtil(int si, int sl, int sr, int ql, int qr){
		if(qr < sl or sr < ql) return NEUTRAL;

		if(ql <= sl and sr <= qr){
			return ST[si];
		}

		propogate(si, sl, sr);

		int leftMax = getMaxUtil(lsi, sl, mid, ql, qr);
		int rightMax = getMaxUtil(rsi, mid + 1, sr, ql, qr);
		return max(leftMax, rightMax);
	}
	int getMax(int ql, int qr){
		return getMaxUtil(0, 0, n - 1, ql, qr);
	}

	int getLeftmostNotLessUtil(int si, int sl, int sr, int l, int val){
		if(sr < l) return -1;

		if(ST[si] < val) return -1;

		if(sl == sr) return sl;

		propogate(si, sl, sr);

		int ans = getLeftmostNotLessUtil(lsi, sl, mid, l, val);
		if(ans == -1){
			ans = getLeftmostNotLessUtil(rsi, mid + 1, sr, l, val);
		}
		return ans;
	}
	int getLeftmostNotLess(int l, int val){
		return getLeftmostNotLessUtil(0, 0, n - 1, l, val);
	}
};

void solve(){
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;

    int sma = accumulate(rng(a), 0ll);

    vi pre = a;
    for(int i = 1; i < SZ(pre); ++i){
    	pre[i] += pre[i - 1];
    }
    auto get = [&](int l, int r){
    	maxi(l, 0ll), mini(r, SZ(pre) - 1);
    	if(l > r){
    		return 0ll;
    	}
    	return pre[r] - (l ? pre[l - 1] : 0ll);
    };

    vi mx(n);
    segmentTree st(2 * n);
    for(int i = n - 1; i >= 0; --i){
    	st.increase(i + n, 2 * n - 1, a[i]);
    }
    for(int i = n - 1; i >= 0; --i){
    	st.increase(i, 2 * n - 1, a[i]);
    	mx[i] = st.getMax(i, i + n - 1);
    	// db(i, mx[i]);
    }

    for(int i = 0; i < m; ++i){
    	int ci = 0;
    	int x; cin >> x;
    	if(x > mx[ci] and sma <= 0){
    		cout << -1 << " ";
    		continue;
    	}

    	int fr = 0;
    	if(x > mx[ci]){
    		fr = (x - mx[ci] + sma - 1) / sma;
    	}

    	// db(x, mx[ci], fr);
    	x -= fr * sma;
    	int j = st.getLeftmostNotLess(ci, x - get(0, ci - 1));
    	// db(ci, j, x);

    	cout << n * fr + j - ci << " ";

    	ci = j % n;
    }

    cout << el;
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