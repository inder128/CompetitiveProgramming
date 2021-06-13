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

void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;

    vi pre = a;
    for(int i = 1; i < SZ(pre); ++i){
    	pre[i] += pre[i - 1];
    }
    auto get = [&](int l, int r){
    	maxi(l, 0ll), mini(r, SZ(pre) - 1);
    	if(l > r){
    		return 0ll;
    	}
    	return pre[r] - (l ? pre[l - 1] : 0);
    };


    int ans = 1; // PPPPP
    for(int i = 0; i < n - 2; ++i){ // PPPCC, 
    	if(get(0, i) > get(i + 1, n - 1)){
    		ans++;
    	}
    }


    for(int i = 0; i < n; ++i){ // CPPPP, CCPPP
    	if(get(i + 1, n - 1) > get(0, i)){
    		ans++;
    	}
    }

    vi pre2(n + 5);
    for(int i = n - 1; i >= 0; --i){
    	pre2[i] = a[i] + pre2[i + 2];
    }

    for(int i = -1; i < n - 3; i++){ // PCPPP, PCPCP
    	int mx = (n - i - 1 - 1) / 2;
    	int l = 0, r = mx + 1;
    	while(l + 1 < r){
    		int m = (l + r) >> 1;
    		int sump = pre2[i + 1] - pre2[i + 1 + 2 * m] + get(i + 1 + 2 * m, n - 1);
    		if(sump > get(0, n - 1) - sump){
    			l = m;
    		}
    		else{
    			r = m;
    		}
    	}
    	ans += l;
    }
    for(int i = 2; i < n - 1; i++){ // PCCPP
    	int mx = (n - i - 1 - 1) / 2;
    	int l = -1, r = mx + 1;
    	while(l + 1 < r){
    		int m = (l + r) >> 1;
    		int sump = a[0] + pre2[i + 1] - pre2[i + 1 + 2 * m] + get(i + 1 + 2 * m, n - 1);
    		if(sump > get(0, n - 1) - sump){
    			l = m;
    		}
    		else{
    			r = m;
    		}
    	}
    	ans += l + 1;
    }

    for(int i = -1; i < n - 2; ++i){ // PPPPC, CPPPC, PCPPC
    	int mx = (n - i - 1 - 2) / 2;
    	int l = -1, r = mx + 1;
    	while(l + 1 < r){
    		int m = (l + r) >> 1;
    		int sump = pre2[i + 1] - pre2[i + 1 + 2 * m] + get(i + 1 + 2 * m, n - 2);
    		if(sump > get(0, n - 1) - sump){
    			l = m;
    		}
    		else{
    			r = m;
    		}
    	}
    	ans += l + 1;
    }
    for(int i = 2; i < n - 2; ++i){
    	int mx = (n - i - 1 - 2) / 2;
    	int l = -1, r = mx + 1;
    	while(l + 1 < r){
    		int m = (l + r) >> 1;
    		int sump = a[0] + pre2[i + 1] - pre2[i + 1 + 2 * m] + get(i + 1 + 2 * m, n - 2);
    		if(sump > get(0, n - 1) - sump){
    			l = m;
    		}
    		else{
    			r = m;
    		}
    	}

    	ans += l + 1;
    }


    cout << ans % 998244353 << el;
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