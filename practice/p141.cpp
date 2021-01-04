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
    int n, m; cin >> n >> m;
    vector <pi> ab(n);
    for(int i = 0; i < n; ++i){
    	cin >> ab[i].F >> ab[i].S;
    }
    vector <pi> cd(m);
    for(int i = 0; i < m; ++i){
    	cin >> cd[i].F >> cd[i].S;
    }

    vector <pi> xy;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		if(ab[i].F <= cd[j].F and ab[i].S <= cd[j].S){
    			xy.pb({cd[j].F - ab[i].F + 1, cd[j].S - ab[i].S + 1});
    		}
    	}
    }


    sort(rng(xy), greater <pi>());

    int ans = 1e9;
    int mxy = 0, l = -1;
    for(int i = 1e6 + 1; i >= 0; --i){
    	while(l + 1 < SZ(xy) and xy[l + 1].F > i){
    		maxi(mxy, xy[l + 1].S);
    		l++;
    	}
    	mini(ans, i + mxy);
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