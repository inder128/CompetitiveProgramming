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
    int n, a, b; cin >> n >> a >> b;
    vi h(n), d(n);
    int tot = 0;
    vi gains;
    for(int i = 0; i < n; ++i){
    	cin >> h[i] >> d[i];
    	gains.pb(max(0ll, h[i] - d[i]));
    	tot += d[i];
    }

    if(b == 0){
    	cout << tot << el;
    	return;
    }

    gains.pb(INT_MAX);
    sort(rng(gains), greater <int>());
    vi gainsp = gains;
    gainsp[0] = 0;
    for(int i = 2; i <= n; ++i){
    	gainsp[i] += gainsp[i - 1];
    }

    auto get = [&](int del){
    	auto i = lower_bound(rng(gains), del, greater <int>()) - gains.begin();
    	if(i <= b){
    		return gainsp[min(b + 1, n)] - gains[i];
    	}
    	else{
    		return gainsp[min(b, n)];
    	}
    };

    int ans = tot + gainsp[min(b, n)];

    b--;

    for(int i = 0; i < n; ++i){
    	int pg = max(0ll, h[i] - d[i]);
    	if(h[i] * (1 << a) > d[i]){
    		maxi(ans, h[i] * (1 << a) + tot - d[i] + get(pg));
    	}
    	else{
    		continue;
    	}
    }

    cout << ans << el;
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