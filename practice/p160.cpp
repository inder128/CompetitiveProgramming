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

    vi pow2(30);
    pow2[0] = 1;
    for(int i = 1; i < 30; ++i){
    	pow2[i] = pow2[i - 1] * 2;
    }

    int ans = 0;
    for(int k = 0; k <= 24; ++k){
    	int mod = pow2[k + 1];
    	vi vals;
    	for(int i : a){
    		vals.pb(i % mod);
    	}
    	sort(rng(vals));
    	
    	auto get = [&](int l, int r, int i){
    		return upper_bound(vals.begin() + i, vals.end(), r) - lower_bound(vals.begin() + i, vals.end(), l);
    	};

    	int cnt = 0;
    	for(int i = 0; i < n; ++i){
    		int l = pow2[k] - vals[i], r = pow2[k + 1] - 1 - vals[i];
    		cnt += get(l, r, i + 1);
    		
    		l = pow2[k] + pow2[k + 1] - vals[i], r = pow2[k + 2] - 2 - vals[i];
    		cnt += get(l, r, i + 1);
    	}
    	ans += (cnt % 2) * pow2[k];
    }
    cout << ans << el;
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