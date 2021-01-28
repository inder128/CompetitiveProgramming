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
    int n, m, k; cin >> n >> m >> k;
    vi a(k); cin >> a;

    vector <pair <double, double>> ans(n + m + 5);
    for(int i = n - 1; i >= 0; --i){
		if(count(rng(a), i)){
			ans[i].S = 1;
		}
		else{
			ans[i].F = 1 + (ans[i + 1].F - ans[i + m + 1].F) / m;
			ans[i].S = (ans[i + 1].S - ans[i + m + 1].S) / m;
		}

    	ans[i].F += ans[i + 1].F;
    	ans[i].S += ans[i + 1].S;
    }
    ans[0].F -= ans[1].F, ans[0].S -= ans[1].S;

    if(abs(ans[0].S - 1) <= 1e-12){
    	cout << -1 << el;
    	return;
    }

    cout << setprecision(12) << fixed << ans[0].F / (1 - ans[0].S) << el;
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