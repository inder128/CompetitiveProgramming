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
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

struct node{
	int cnt[41];
};

#define lsi 2*si + 1
#define rsi 2*si + 2
class segmentTree{
public :
	int size, n;
	node neutral;
	vector <node> ST;
	segmentTree(int _n){
		n = _n;
		size = 1;
		while(size < n) size <<= 1;
		for (int i = 0; i <= 40; ++i){
			neutral.cnt[i] = 0;
		}
		ST.assign(2 * size, neutral);
	}


	inline int getMid(int &sl, int &sr){
		return (sl + sr) >> 1;
	}
	void printUtil(int si, int sl, int sr){
		cout<<si<<" : "<<sl<<" - "<<sr<<" : "<<ST[si].cnt[0]<<el;

		if(sl == sr) return;

		int mid = getMid(sl, sr);
		printUtil(lsi, sl, mid);
		printUtil(rsi, mid + 1, sr);
	}
	void print(){
		return printUtil(0, 0, n - 1);
	}

	node merge(node n1, node n2){
		node m;
		for (int i = 0; i <= 40; ++i){
			m.cnt[i] = n1.cnt[i] + n2.cnt[i];
		}
		for (int i = 2; i <= 40; ++i){
			n2.cnt[i] += n2.cnt[i - 1];
			m.cnt[0] += n1.cnt[i] * n2.cnt[i - 1];
		}
		return m;
	}
	void updateUtil(int si, int sl, int sr, int i, int newVal){
		if(sl == sr){
			ST[si] = neutral;
			ST[si].cnt[newVal] = 1;
			return;
		}

		int mid = getMid(sl, sr);
		if(i <= mid)
			updateUtil(lsi, sl, mid, i, newVal);
		else
			updateUtil(rsi, mid + 1, sr, i, newVal);

		ST[si] = merge(ST[lsi], ST[rsi]);
	}
	void update(int i, int newVal){
		return updateUtil(0, 0, n - 1, i, newVal);
	}


	node getInvUtil(int si, int sl, int sr, int ql, int qr){
		if(sr < ql or qr < sl) return neutral;

		if(ql <= sl and sr <= qr) return ST[si]; 

		int mid = getMid(sl, sr);
		node leftSum = getInvUtil(lsi, sl, mid, ql, qr);
		node rightSum = getInvUtil(rsi, mid + 1, sr, ql, qr);
		return merge(leftSum, rightSum);
	}
	int getInv(int ql, int qr){
		return getInvUtil(0, 0, n - 1, ql, qr).cnt[0];
	}
};

void solve(){
    int n, q; cin>>n>>q;
    segmentTree st(n);
    for (int i = 0; i < n; ++i){
    	int val; cin>>val;
    	st.update(i, val);
    }
    // st.print();
    while(q--){
    	int op; cin>>op;
    	if(op == 1){
    		int l, r; cin>>l>>r; 
    		l--, r--;
    		cout<<st.getInv(l, r)<<el;
    	}
    	else{
    		int i, val; cin>>i>>val;
    		i--;
    		st.update(i, val);
    	}
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}