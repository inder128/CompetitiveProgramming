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
		return get(r) - get(l - 1);
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

void solve(){
    int n, t; cin >> n >> t;
    BIT bit(n + 2);
    bit.increase(0, -1e9);

    auto q = [&](int r){
    	int pre = bit.get(r);
    	// db(r, pre);
		if(pre >= 0){
			return pre;
		}
		cout << "? 1 " << r << endl;
		int ans; cin >> ans;
		int zeros = r - ans;
		bit.increase(r, zeros - pre);
		bit.increase(r + 1, pre - zeros);
		return zeros;
	};

    while(t--){
	    int k; cin >> k;
	    int l = 0, r = n;
	    while(l + 1 < r){
	    	int m = (l + r) >> 1;
	    	int zeros = q(m);
	    	if(zeros < k){
	    		l = m;
	    	}
	    	else{
	    		r = m;
	    	}
	    }
	    cout << "! " << r << endl;
	    bit.increase(r, -1);
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