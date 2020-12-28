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


#define lsi (2*si + 1)
#define rsi (2*si + 2)
#define mid ((sl + sr) >> 1)
class segmentTree{
public :
	int size, n, NEUTRAL = 0;
	vi ST;
	segmentTree(int _n){
		n = _n;
		size = 1;
		while(size < n) size <<= 1;
		ST.assign(2 * size - 1, NEUTRAL);
	}

	void printUtil(int si, int sl, int sr){
		cout<<si<<" : "<<sl<<" - "<<sr<<" : "<<ST[si]<<el;

		if(sl == sr) return;

		printUtil(lsi, sl, mid);
		printUtil(rsi, mid + 1, sr);
	}
	void print(){
		return printUtil(0, 0, n - 1);
	}


	void updateUtil(int si, int sl, int sr, int i, int newVal){
		if(sl == sr){
			maxi(ST[si], newVal);
			return;
		}

		if(i <= mid)
			updateUtil(lsi, sl, mid, i, newVal);
		else
			updateUtil(rsi, mid + 1, sr, i, newVal);

		ST[si] = max(ST[lsi], ST[rsi]);
	}
	void update(int i, int newVal){
		return updateUtil(0, 0, n - 1, i, newVal);
	}


	int getMaxUtil(int si, int sl, int sr, int ql, int qr){
		if(sr < ql or qr < sl) return NEUTRAL;

		if(ql <= sl and sr <= qr) return ST[si]; 

		int leftMax = getMaxUtil(lsi, sl, mid, ql, qr);
		int rightMax = getMaxUtil(rsi, mid + 1, sr, ql, qr);
		return max(leftMax, rightMax);
	}
	int getMax(int ql, int qr){
		return getMaxUtil(0, 0, n - 1, ql, qr);
	}
};


void solve(){
    int n; cin >> n;
    segmentTree st(n + 1);
    vi arr(n); cin >> arr;
    vi ans(n);

    map <int, vi> req;
    stack <int> stk;
    for(int i = 0; i < n; ++i){
    	while(SZ(stk) and arr[stk.top()] <= arr[i]){
    		stk.pop();
    	}
    	if(SZ(stk)){
    		req[stk.top() - 1].pb(i);
    	}
    	stk.push(i);
    }

    for(int i = -1; i < n; ++i){
    	if(i >= 0){
	    	maxi(ans[i], 1 + st.getMax(0, arr[i]));

	    	st.update(arr[i], ans[i]);
	    }

    	for(int j : req[i]){
    		// handle req;
    		ans[j] = 2 + st.getMax(0, arr[j]);
    	}
    }

    cout << st.getMax(0, n) << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}