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
    vector <pi> xy(n); 
    for(int i = 0; i < n; ++i){
    	cin >> xy[i].F >> xy[i].S;
    }

    auto dist = [&](int i, int j){
    	int dx = xy[i].F - xy[j].F;
    	int dy = xy[i].S - xy[j].S;
    	return dx * dx + dy * dy;
    };

    vi prem{0}, vis(n);
    vis[0] = true;
    int l = 0;
    for(int i = 0; i < n - 1; ++i){

    	vi rem;
    	for(int j = 0; j < n; ++j){
    		if(vis[j]){
    			continue;
    		}
    		rem.pb(j);
    	}
    	sort(rng(rem), [&](int j, int k){
    		return dist(j, l) > dist(k, l);
    	});

		prem.pb(rem[0]);
		vis[rem[0]] = true;
		l = rem[0];
		
    }

    for(int i : prem){
    	cout << i + 1 << " ";
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