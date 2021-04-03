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
    vi t(n + 1), x(n + 1);
    for(int i = 1; i <= n; ++i){
    	cin >> t[i] >> x[i];
    }
    t.pb(1e15);

    int sx = 0, ex = 0, ans = 0;
    for(int i = 1; i <= n; ++i){
    	if(abs(ex - sx) <= t[i] - t[i - 1]){
    		sx = ex;
    		ex = x[i];
    	}
    	else{
    		sx += (t[i] - t[i - 1]) * (ex > sx ? 1 : -1);
    	}

    	int ssx = sx, eex;
    	if(abs(ex - sx) <= t[i + 1] - t[i]){
    		eex = ex;
    	}
    	else{
    		eex = sx + (t[i + 1] - t[i]) * (ex > sx ? 1 : -1);
    	}
    	if(eex < ssx){
    		swap(ssx, eex);
    	}

    	ans += (ssx <= x[i] and x[i] <= eex);
    }

    cout << ans << el;
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