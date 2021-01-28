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
	int NO_OPERATION = LLONG_MAX;
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


	void update(int si, int sl, int sr, int val){
		ST[si] = val * (sr - sl + 1);
		lazy[si] = val;
	}
	void propogate(int si, int sl, int sr){
		if(lazy[si] == NO_OPERATION) return;
		update(lsi, sl, mid, lazy[si]);
		update(rsi, mid + 1, sr, lazy[si]);
		lazy[si] = NO_OPERATION;
	}
	

	void updateUtil(int si, int sl, int sr, int ql, int qr, int val){
		if(qr < sl or sr < ql) return;

		if(ql <= sl and sr <= qr){
			return update(si, sl, sr, val);
		}

		propogate(si, sl, sr);

		updateUtil(lsi, sl, mid, ql, qr, val);
		updateUtil(rsi, mid + 1, sr, ql, qr, val);

		ST[si] = ST[lsi] + ST[rsi];
	}
	void update(int ql, int qr, int val){
		return updateUtil(0, 0, n - 1, ql, qr, val);
	}


	int getSumUtil(int si, int sl, int sr, int ql, int qr){
		if(qr < sl or sr < ql) return NEUTRAL;

		if(ql <= sl and sr <= qr){
			return ST[si];
		}

		propogate(si, sl, sr);

		int leftSum = getSumUtil(lsi, sl, mid, ql, qr);
		int rightSum = getSumUtil(rsi, mid + 1, sr, ql, qr);
		return leftSum + rightSum;
	}
	int getSum(int ql, int qr){
		return getSumUtil(0, 0, n - 1, ql, qr);
	}
};


void solve(){
    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;

    vi l(q), r(q);
    for(int i = 0; i < q; ++i){
    	cin >> l[i] >> r[i];
    	l[i]--, r[i]--;
    }

    segmentTree st(n);
    for(int i = 0; i < n; ++i){
    	if(t[i] == '1'){
    		st.update(i, i, 1);
    	}
    }

    for(int i = q - 1; i >= 0; --i){
    	int ones = st.getSum(l[i], r[i]);
    	int zeros = r[i] - l[i] + 1 - ones;

    	if(ones == zeros){
    		cout << "NO" << el;
    		return;
    	}

    	st.update(l[i], r[i], ones > zeros);
    }

    for(int i = 0; i < n; ++i){
    	if(st.getSum(i, i) != (s[i] - '0')){
    		cout << "NO" << el;
    		return;
    	}
    }

    cout << "YES" << el;
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