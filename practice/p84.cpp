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
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

void solve(){
    vi a(6); cin>>a;
    int n; cin>>n;
    vi h(n); cin>>h; 
    sort(rng(a));
    sort(rng(h));

    vector <vi> ha(6, vi(n));
    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < 6; ++j){
    		ha[6 - 1 - j][i] = h[i] - a[j];
    	}
    }

    int ans = LLONG_MAX;
    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < 6; ++j){
    		int mx = h[i] - a[j];
    		// all less than equal to mx -> as greater as possible;
    		
    		int p = 5;
    		while(p >= 0 and ha[p][0] > mx) p--;
    		if(p == -1) continue;

    		int mn = ha[p][0];
    		int k = 0;
    		while(true){
    			k = upper_bound(rng(ha[p]), mx) - ha[p].begin();
    			if(k == n) break;
    			while(p >= 0 and ha[p][k] > mx) p--;
    			if(p == -1) break;
    			mini(mn, ha[p][k]);
    		}
    		if(k == n) mini(ans, mx - mn);

    	}
    }

    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}