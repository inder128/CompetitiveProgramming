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

int mod;

struct mat{
	int v[2][2];
};

#define lsi 2*si + 1
#define rsi 2*si + 2
class segmentTree{
public :
	int size, n;
	mat neutral = {{{1, 0}, {0, 1}}};
	vector <mat> ST;
	segmentTree(int _n){
		n = _n;
		size = 1;
		while(size < n) size <<= 1;
		ST.assign(2 * size, neutral);
	}


	inline int getMid(int &sl, int &sr){
		return (sl + sr) >> 1;
	}
	void printUtil(int si, int sl, int sr){
		cout<<si<<" : "<<sl<<" - "<<sr<<" : ";
		out(ST[si]); cout<<el;

		if(sl == sr) return;

		int mid = getMid(sl, sr);
		printUtil(lsi, sl, mid);
		printUtil(rsi, mid + 1, sr);
	}
	void print(){
		return printUtil(0, 0, n - 1);
	}

	void out(mat &m){
		cout<<m.v[0][0]<<" "<<m.v[0][1]<<el;
    	cout<<m.v[1][0]<<" "<<m.v[1][1]<<el;
	}

	mat mul(mat &m1, mat &m2){
		mat m = {{{0, 0}, {0, 0}}};
		for (int i = 0; i < 2; ++i){
			for (int j = 0; j < 2; ++j){
				for (int k = 0; k < 2; ++k){
					m.v[i][j] += m1.v[i][k] * m2.v[k][j];
					m.v[i][j] %= mod;
				}
			}
		}
		return m;
	}
	void updateUtil(int si, int sl, int sr, int i, mat newMat){
		if(sl == sr){
			ST[si] = newMat;
			return;
		}

		int mid = getMid(sl, sr);
		if(i <= mid)
			updateUtil(lsi, sl, mid, i, newMat);
		else
			updateUtil(rsi, mid + 1, sr, i, newMat);

		ST[si] = mul(ST[lsi], ST[rsi]);
	}
	void update(int i, mat newMat){
		return updateUtil(0, 0, n - 1, i, newMat);
	}


	mat getMulUtil(int si, int sl, int sr, int ql, int qr){
		if(sr < ql or qr < sl) return neutral;

		if(ql <= sl and sr <= qr) return ST[si]; 

		int mid = getMid(sl, sr);
		mat leftMul = getMulUtil(lsi, sl, mid, ql, qr);
		mat rightMul = getMulUtil(rsi, mid + 1, sr, ql, qr);
		return mul(leftMul, rightMul);
	}
	mat getMul(int ql, int qr){
		return getMulUtil(0, 0, n - 1, ql, qr);
	}
};

void solve(){
    int n, q; cin>>mod>>n>>q;
    segmentTree st(n);
    for (int i = 0; i < n; ++i){
    	mat m; 
    	cin>>m.v[0][0]>>m.v[0][1];
    	cin>>m.v[1][0]>>m.v[1][1];
    	st.update(i, m);
    }

    while(q--){
    	int l, r; cin>>l>>r; 
    	l--, r--;
    	mat m = st.getMul(l, r);
    	st.out(m);
    	cout<<el;
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