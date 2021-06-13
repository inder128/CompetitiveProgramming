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

int n2(int x){
	return x * (x + 1) / 2;
}

void solve(){
    int n, k; cin >> n >> k;
    

    auto maxWt = [&](int mxwt){
    	int ans = 0;
    	for(int a = 1; a <= min(n, mxwt - 2); ++a){
    		int rem_mxwt = mxwt - a;

    		// 1, {1, rem_mxwt - 1},
    		// 2, {1, rem_mxet - 2},
    		// ...
    		// rem_mxwt - 1, 1
    		if(rem_mxwt >= 2 * n){
    			ans += n * n;
    		}
    		else if(rem_mxwt > n){
    			int x = rem_mxwt - n;
    			ans += n * x + n2(n - 1) - n2(x - 1);
    		}
    		else{
    			ans += n2(rem_mxwt - 1);
    		}
    	}
    	return ans;
    };

    int l = 2, r = 3 * n;
    while(l + 1 < r){
    	int m = (l + r) >> 1;
    	int cnt = maxWt(m);
    	if(cnt >= k){
    		r = m;
    	}
    	else{
    		l = m;
    	}
    }

    int wt = r;
    k -= maxWt(wt - 1);
    for(int a = max(1ll, wt - 2 * n); ; ++a){
    	int rem_wt = wt - a;

    	// x, rem_wt - x
    	// ..
    	// rem_wt - x, x;

    	int x = max(rem_wt - n, 1ll);
    	int cnt = rem_wt - x - x + 1;

    	if(cnt >= k){
    		int b = x + k - 1;
    		int c = wt - a - b;
    		cout << a << " " << b << " " << c << el;
    		return;
    	}
    	else{
    		k -= cnt;
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