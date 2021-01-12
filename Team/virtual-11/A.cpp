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


typedef array <int, 6> node;

#define lsi (2*si + 1)
#define rsi (2*si + 2)
#define mid ((sl + sr) >> 1)
class segmentTree{
public :
	int size, n;
	node NEUTRAL = {0, 0, 0, 0, 0, 0};
	vector <node> ST;
	segmentTree(int _n){
		n = _n;
		size = 1;
		while(size < n) size <<= 1;
		ST.assign(2 * size - 1, NEUTRAL);
	}

	node merge(node& left, node& right){
		node res = left;
		res[5] += right[5];
		int of = (5 - left[5] % 5) % 5;
		for(int i = 0; i < 5; ++i){
			res[i] += right[(of + i) % 5];
		}
		return res;
	}
	void updateUtil(int si, int sl, int sr, int i, int newVal){
		if(sl == sr){
			if(newVal){
				ST[si][0] = newVal;
				ST[si][5] = 1;
			}
			else{
				ST[si][0] = 0;
				ST[si][5] = 0;
			}
			return;
		}

		if(i <= mid)
			updateUtil(lsi, sl, mid, i, newVal);
		else
			updateUtil(rsi, mid + 1, sr, i, newVal);

		ST[si] = merge(ST[lsi], ST[rsi]);
	}
	void update(int i, int newVal){
		return updateUtil(0, 0, n - 1, i, newVal);
	}
};


void solve(){
    int n; cin >> n;
    vi queries, ind;
    while(n--){
    	string str; cin >> str;
    	if(str == "add"){
    		int x; cin >> x;
    		ind.pb(x);
    		queries.pb(x);
    	}
    	else if(str == "del"){
    		int x; cin >> x;
    		ind.pb(x);
    		queries.pb(-x);
    	}
    	else{
    		queries.pb(0);
    	}
    }
    sort(rng(ind));
    ind.resize(unique(rng(ind)) - ind.begin());

    n = SZ(ind);
    segmentTree st(n);
    for(int q : queries){
    	int i = lower_bound(rng(ind), abs(q)) - ind.begin();
    	if(q == 0){
    		cout << st.ST[0][2] << el;
    	}
    	else if(q > 0){
    		st.update(i, q);
    	}
    	else{
    		st.update(i, 0);
    	}
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