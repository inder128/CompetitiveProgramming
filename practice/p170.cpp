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
    int n; cin >> n;
    vi p(n); cin >> p;
    BIT bt1(n);
    vi inc(n), pos(n);
    for(int i = n - 1; i >= 0; --i){
    	p[i]--;
    	inc[p[i]] = bt1.get(0, p[i] - 1);
    	pos[p[i]] = i;
    	bt1.increase(p[i], 1);
    }

    BIT bt(n);
    bt.increase(pos[0], 1);
    int med = pos[0];
    int ans = 0;
    cout << 0 << " ";
    for(int i = 1; i < n; ++i){
    	bt.increase(pos[i], 1);
    	int newMed = bt[i / 2];
    	bt.increase(pos[i], -1);

    	if(newMed > med){
    		ans += bt.get(0, med) * (newMed - med);
    		ans -= bt.get(med + 1, n - 1) * (newMed - med);
    	}
    	if(newMed < med){
    		ans += bt.get(med, n - 1) * (med - newMed);
    		ans -= bt.get(0, med - 1) * (med - newMed);
    	}
    	ans += abs(pos[i] - newMed) + inc[i];
    	
    	bt.increase(pos[i], 1);
    	med = newMed;

    	int lm = bt.get(0, newMed - 1), rm = bt.get(newMed + 1, n - 1);
    	cout << ans - lm * (lm + 1) / 2 - rm * (rm + 1) / 2 << " ";
    }
    cout << el;
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