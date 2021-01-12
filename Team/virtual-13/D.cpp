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


class sparseTable{
public:
	vvi spt;
	vi arr, numLog;
	int k, n;

	sparseTable(vi &arr_){
		build(arr_);
	}

	sparseTable(){
	}

	void build(vi &arr_){
		arr = arr_;
		n = arr.size();

		numLog.resize(n + 1);
		numLog[1] = 0;
		for(int i = 2; i <= n; ++i){
			numLog[i] = numLog[i / 2] + 1;
		}

		k = numLog[n];

		spt = vvi(k + 1, vi(n));
		iota(rng(spt[0]), 0);
		for(int b = 1; b <= k; ++b){
			for(int i = 0, j = i + (1 << b) - 1; j < n; ++i, ++j){
				int s1 = spt[b - 1][i], s2 = spt[b - 1][i + (1 << b) / 2];
				spt[b][i] = compare(s1, s2);
			}
		}
	}

	int compare(int s1, int s2){
		return (arr[s1] > arr[s2] ? s1 : s2);
	}

	int get(int l, int r){
		int lg = numLog[r - l + 1];
		return compare(spt[lg][l], spt[lg][r - (1 << lg) + 1]);
	}

	int getVal(int l, int r){
		return arr[get(l, r)];
	}
};


void solve(){
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    vi d(n - 1);
    for(int i = 0; i < n - 1; ++i){
    	d[i] = abs(a[i + 1] - a[i]);
    }
    sparseTable spt(d);
    while(q--){
    	int l, r; cin >> l >> r;
    	l--, r--;
    	int ans = 0;
    	queue <pi> Q;
    	Q.push({l, r});
    	while(SZ(Q)){
    		auto [l, r] = Q.front(); Q.pop();
    		if(l == r){
    			continue;
    		}
    		int mxd = spt.get(l, r - 1);
    		int x = mxd - l + 1;
    		int y = r - l + 1 - x;
    		ans += x * y * d[mxd];
    		Q.push({l, mxd});
    		Q.push({mxd + 1, r});
    	}
    	cout << ans << el;
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