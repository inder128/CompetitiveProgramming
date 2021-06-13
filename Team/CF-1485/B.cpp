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

void solve(){
    int n, q, k; cin >> n >> q >> k;
    vi a(n); cin >> a;
    a.pb(k + 1);

    a.insert(a.begin(), 0);

    vi b(n);
    for(int i = 1; i <= n; ++i){
    	b[i - 1] = a[i + 1] - a[i - 1] - 2;
    }

    vi pre = b;
    for(int i = 1; i < SZ(pre); ++i){
    	pre[i] += pre[i - 1];
    }
    auto get = [&](int l, int r){
    	maxi(l, 0), mini(r, SZ(pre) - 1);
    	if(l > r){
    		return 0;
    	}
    	return pre[r] - (l ? pre[l - 1] : 0);
    };	

    while(q--){
    	int l, r; cin >> l >> r;
    	if(l == r){
    		cout << k - 1 << el;
    		continue;
    	}

   		int ans = k + 1 - a[r - 1] - 2 - (a[r + 1] - a[r - 1] - 2);
   		ans += a[l + 1] - 0 - 2 - (a[l + 1] - a[l - 1] - 2);
    	l--, r--;
    	cout << ans + get(l, r) << el;
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